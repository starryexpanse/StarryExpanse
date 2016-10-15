#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

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
            Dispatcher(Store& myStore)
                : store(myStore), dispatching(false)
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
            dispatcher.reset(new Dispatcher(*this));
        }
};
