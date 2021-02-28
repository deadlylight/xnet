#pragma once
#include <cstdint>
#include <memory>
#include <queue>
#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

class IEvent;

class CEventHandler
{
private:
    bool mRunning;
    queue<shared_ptr<IEvent>, list<shared_ptr<IEvent>>> mEventQ;
    mutex mMutex;
    condition_variable mCond;

private:
    static void handleSelf(shared_ptr<CEventHandler>);
    void handleEvents();

protected:
    bool startEventHandler(shared_ptr<CEventHandler>);
    bool stopEventHandler();

    virtual void handleEvent(shared_ptr<IEvent>) = 0;

public:
    CEventHandler();
    ~CEventHandler();

    bool addEvent(shared_ptr<IEvent>);
};
