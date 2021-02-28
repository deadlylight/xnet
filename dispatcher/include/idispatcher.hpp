#pragma once
#include <memory>

using namespace std;

class IEvent;

class IDispatcher
{
public:
    virtual ~IDispatcher() = default;
    virtual bool startDispatcher() = 0;
    virtual bool stopDispatcher() = 0;
    virtual bool addDispatcherEvent(shared_ptr<IEvent>) = 0;
};
