#pragma once
#include <memory>
#include <vector>

using namespace std;

class CWorker;

class IBalancer
{
public:
    virtual ~IBalancer() = default;
    virtual void setWorkers(const vector<shared_ptr<CWorker>> &) = 0;
    virtual shared_ptr<CWorker> getWorker() = 0;
};
