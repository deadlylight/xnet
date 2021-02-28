#include "cminloadbalancer.hpp"

void CMinLoadBalancer::setWorkers(const vector<shared_ptr<CWorker>> &inWorkers)
{
    for (auto &vWorker : inWorkers)
    {
        mWorkers.push(vWorker);
    }
}

shared_ptr<CWorker> CMinLoadBalancer::getWorker()
{
    //TODO
    return nullptr;
}
