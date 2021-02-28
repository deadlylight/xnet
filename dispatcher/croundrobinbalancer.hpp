#include <queue>
#include <list>
#include "ibalancer.hpp"

class CRoundRobinBalancer : public IBalancer
{
private:
    unsigned int mCurrent;
    vector<shared_ptr<CWorker>> mWorkers;

public:
    void setWorkers(const vector<shared_ptr<CWorker>> &) override;
    shared_ptr<CWorker> getWorker() override;
};
