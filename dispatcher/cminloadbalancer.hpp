#include <queue>
#include <list>
#include "ibalancer.hpp"

class CMinLoadBalancer : public IBalancer
{
private:
    queue<shared_ptr<CWorker>, list<shared_ptr<CWorker>>> mWorkers;

public:
    void setWorkers(const vector<shared_ptr<CWorker>> &) override;
    shared_ptr<CWorker> getWorker() override;
};
