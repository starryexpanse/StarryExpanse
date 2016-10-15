#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

struct State
{
    int registerA;
    int registerB;
    int resultRegister;
    void print() {
        cout << "regA: " << registerA << endl;
        cout << "regB: " << registerB << endl;
        cout << "result: " << resultRegister << endl;
    }
};

struct Action
{
    string type;
    string module;
    Action (string type, string module): type(type), module(module) {}
};

struct SetRegA : Action
{
    int nextRegA;

    SetRegA(int nextRegA) :
        Action("SetRegA", "MATH"),
        nextRegA(nextRegA)
    {
    }
};

struct SetRegB : Action
{
    int nextRegB;

    SetRegB(int nextRegB) :
        Action("SetRegB", "MATH"),
        nextRegB(nextRegB)
    {
    }
};

struct AddAB : Action
{
    AddAB() :
        Action("AddAB", "MATH")
    {
    }
};

State handleSetRegA(State state, const SetRegA& action) {
    state.registerA = action.nextRegA;
    return state;
}

State handleSetRegB(State state, const SetRegB& action) {
    state.registerB = action.nextRegB;
    return state;
}

State handleAddAB(State state, const AddAB& action) {
    state.resultRegister = state.registerA + state.registerB;
    return state;
}

State mathReducer(State state, const Action& action) {
    if (action.module == "MATH") {
        if (action.type == "SetRegA")
            return handleSetRegA(state, static_cast<const SetRegA&>(action));
        if (action.type == "SetRegB")
            return handleSetRegB(state, static_cast<const SetRegB&>(action));
        if (action.type == "AddAB")
            return handleAddAB(state, static_cast<const AddAB&>(action));
    }
    return state;
}

template<typename State, typename Action>
class Store
{
    typedef function<State(State, const Action&)> Reducer;

    typedef function<void(shared_ptr<Action>)> DispatchFunctionType;
    typedef function<void(DispatchFunctionType)> ActionCreator;

    class Dispatcher {
        Store& store;
        bool dispatching;
        vector<Reducer> reducers;
        deque< shared_ptr<Action> > unhandledActions;

        public:
            Dispatcher(Store& store)
                : store(store), dispatching(false)
            {
            }

            void dispatch(shared_ptr<Action> action)
            {
                if (dispatching) {
                    cout << "Cannot dispatch inside of a reducer!" << endl;
                    return;
                }
                unhandledActions.push_back(action);
                dispatching = true;
                handleOutstandingActions();
                dispatching = false;
            }

            void dispatch(ActionCreator ac)
            {
                auto func = [&] (shared_ptr<Action> action) {
                    dispatch(action);
                };
                ac(func);
            }

            void handleOutstandingActions() {
                State currentState = store.state;

                for (auto actionIt = begin(unhandledActions); actionIt != end(unhandledActions); actionIt++) {
                    for (auto reducerIt = begin(reducers); reducerIt != end(reducers); reducerIt++) {
                        Reducer reducer = *reducerIt;
                        const Action& action = **actionIt;
                        currentState = reducer(currentState, action);
                    }
                    unhandledActions.pop_front();
                }

                store.state = currentState;
            }

            void registerReducer(Reducer reducer)
            {
                reducers.push_back(reducer);
            }
    };

    public:
        State state;
        unique_ptr<Dispatcher> dispatcher;

        Store() {
            dispatcher = unique_ptr<Dispatcher>(new Dispatcher(*this));
        }
};


int main()
{
    Store<State, Action> myStore;
    myStore.dispatcher->registerReducer(mathReducer);

    shared_ptr<Action> act = shared_ptr<Action>(new SetRegB(32));
    myStore.dispatcher->dispatch(act);

    auto anActionCreator = [] (function<void(shared_ptr<Action>)> dispatch) {
        auto act2 = shared_ptr<Action>(new SetRegA(2));
        dispatch(act2);

        auto act3 = shared_ptr<Action>(new AddAB());
        dispatch(act3);
    };
    myStore.dispatcher->dispatch(anActionCreator);

    cout << "Result is " << myStore.state.resultRegister << endl;

    return 0;
}
