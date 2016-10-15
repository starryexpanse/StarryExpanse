#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

class State
{
    public:
        int registerA;
        int registerB;
        int resultRegister;
        void print() {
            cout << "regA: " << registerA << endl;
            cout << "regB: " << registerB << endl;
            cout << "result: " << resultRegister << endl;
        }
};




class Action
{
    public:
        string type;
        string module;
};

class SetRegA : public Action
{
    public:
        int nextRegA;

    SetRegA(int nextRegA) : nextRegA(nextRegA) {
        type = "SetRegA";
        module = "Foo";
    }
};

class SetRegB : public Action
{
    public:
        int nextRegB;

    SetRegB(int nextRegB) : nextRegB(nextRegB) {
        type = "SetRegB";
        module = "Foo";
    }
};

class AddAB : public Action
{
    public:
    AddAB() {
        type = "AddAB";
        module = "Foo";
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
    if (action.type == "SetRegA")
        return handleSetRegA(state, static_cast<const SetRegA&>(action));
    if (action.type == "SetRegB")
        return handleSetRegB(state, static_cast<const SetRegB&>(action));
    if (action.type == "AddAB")
        return handleAddAB(state, static_cast<const AddAB&>(action));
    return state;
}

template<typename State, typename Action>
class Store
{
    typedef function<State(State, const Action&)> Reducer;

    class Dispatcher {
        Store& store;
        bool dispatching;
        vector<Reducer> reducers;
        deque<Action*> unhandledActions;

        public:
            Dispatcher(Store& store)
                : store(store), dispatching(false)
            {
            }

            void dispatch(Action* action)
            {
                if (dispatching) {
                    cout << "Cannot dispatch inside of a reducer!" << endl;
                    return;
                }
                unhandledActions.push_back(action);
                dispatching = true;
                handleStuff();
                dispatching = false;
            }

            void handleStuff() {
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
        Dispatcher* dispatcher;

        Store() {
            this->dispatcher = new Dispatcher(*this);
        }
};

Store<State, Action> myStore;

int main()
{
    myStore.dispatcher->registerReducer(mathReducer);

    SetRegB act(32);
    myStore.dispatcher->dispatch(&act);

    SetRegA act2(1);
    myStore.dispatcher->dispatch(&act2);

    AddAB act3;
    myStore.dispatcher->dispatch(&act3);

    cout << "Result is " << myStore.state.resultRegister << endl;

    return 0;
}
