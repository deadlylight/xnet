#include <algorithm>
#include <massert.hpp>
#include <ievent.hpp>
#include "cdispatcher.hpp"
#include "cworker.hpp"
#include "croundrobinbalancer.hpp"

CDispatcher::CDispatcher(unsigned int inCount)
    : mWorkerCount(inCount)
{
    mWorkerCount = std::min<unsigned int>(mWorkerCount, 2);
}

CDispatcher::~CDispatcher()
{
}

bool CDispatcher::startDispatcher()
{
    shared_ptr<CDispatcher> vSelf = mSelf.lock();
    if (!startEventHandler(vSelf))
    {
        return false;
    }

    for (unsigned int vI = 0; vI < mWorkerCount; vI++)
    {
        shared_ptr<CWorker> vWorker = make_shared<CWorker>(static_cast<int>(vI));
        vWorker->startWorker(vWorker);
        mWorkers.push_back(vWorker);
    }
    mBalancer = make_unique<CRoundRobinBalancer>();
    mBalancer->setWorkers(mWorkers);
    return true;
}

bool CDispatcher::stopDispatcher()
{
    stopEventHandler();
    for (auto &vWorker : mWorkers)
    {
        vWorker->stopWorker();
    }
    mWorkers.clear();
    return true;
}

bool CDispatcher::addDispatcherEvent(shared_ptr<IEvent> inEvent)
{
    return addEvent(inEvent);
}

shared_ptr<CWorker> CDispatcher::getWorker()
{
    return mBalancer->getWorker();
}

void CDispatcher::handleEvent(shared_ptr<IEvent> inEvent)
{
    int vAffinity = inEvent->getAffinity();
    shared_ptr<CWorker> vWorker;
    if (vAffinity < 0)
    {
        vWorker = getWorker();
    }
    else
    {
        xnet_assert(vAffinity < mWorkers.size());
        vWorker = mWorkers[vAffinity];
    }
    vWorker->addEvent(inEvent);
}
