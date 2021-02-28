#include "croundrobinbalancer.hpp"

void CRoundRobinBalancer::setWorkers(const vector<shared_ptr<CWorker>> &inWorkers)
{
    mWorkers = inWorkers;
    mCurrent = 0;
}

shared_ptr<CWorker> CRoundRobinBalancer::getWorker()
{
    if (mWorkers.empty())
    {
        return nullptr;
    }

    unsigned int vCurrent = mCurrent;
    mCurrent = (mCurrent + 1) % mWorkers.size();
    return mWorkers[vCurrent];
}
