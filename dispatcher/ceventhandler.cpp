#include <thread>
#include "ceventhandler.hpp"

CEventHandler::CEventHandler()
    : mRunning(false)
{
}

CEventHandler::~CEventHandler()
{
}

bool CEventHandler::startEventHandler(shared_ptr<CEventHandler> inSelf)
{
    mRunning = true;
    thread vThread(handleSelf, inSelf);
    vThread.detach();
    return true;
}

bool CEventHandler::stopEventHandler()
{
    mRunning = false;
    unique_lock<mutex> vLock(mMutex);
    mCond.notify_all();
    return true;
}

void CEventHandler::handleSelf(shared_ptr<CEventHandler> inSelf)
{
    inSelf->handleEvents();
}

void CEventHandler::handleEvents()
{
    while (mRunning)
    {
        unique_lock<mutex> vLock(mMutex);
        while (mRunning && mEventQ.empty())
        {
            mCond.wait(vLock);
        }
        shared_ptr<IEvent> vEvent = mEventQ.front();
        mEventQ.pop();
        vLock.unlock();
        handleEvent(vEvent);
    }
}

bool CEventHandler::addEvent(shared_ptr<IEvent> inEvent)
{
    unique_lock<mutex> vLock(mMutex);
    mEventQ.push(inEvent);
    mCond.notify_one();
    return true;
}
