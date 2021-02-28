#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <idispatcher.hpp>
#include "ceventhandler.hpp"

using namespace std;

class IBalancer;
class CWorker;

class CDispatcher : public IDispatcher, public CEventHandler
{
    friend class CDispatcherFactory;

private:

private:
    uint32_t mWorkerCount;
    weak_ptr<CDispatcher> mSelf;
    vector<shared_ptr<CWorker>> mWorkers;
    unique_ptr<IBalancer> mBalancer;

private:
    shared_ptr<CWorker> getWorker();

protected:
    void handleEvent(shared_ptr<IEvent>) override;

public:
    CDispatcher(uint32_t);
    ~CDispatcher();

    bool startDispatcher() override;
    bool stopDispatcher() override;
    bool addDispatcherEvent(shared_ptr<IEvent>) override;
};
