#pragma once

typedef function<void(shared_ptr<Action>)> DispatchFunctionType;
typedef function<void(DispatchFunctionType)> ActionCreator;
