#include <ievent.hpp>
#include "cworker.hpp"

CWorker::CWorker(int inId)
    : mWorkerId(inId)
{
}

int CWorker::getAffinity() const
{
    return mWorkerId;
}

void CWorker::handleEvent(shared_ptr<IEvent> inEvent)
{
    inEvent->handleEvent(mWorkerId);
}

bool CWorker::startWorker(shared_ptr<CWorker> inSelf)
{
    return startEventHandler(inSelf);
}

bool CWorker::stopWorker()
{
    return stopEventHandler();
}
