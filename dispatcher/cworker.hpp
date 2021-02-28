#pragma once
#include "ceventhandler.hpp"

class CWorker : public CEventHandler
{
private:
    int mWorkerId;

protected:
    void handleEvent(shared_ptr<IEvent>) override;

public:
    CWorker(int);
    int getAffinity() const;
    bool startWorker(shared_ptr<CWorker>);
    bool stopWorker();
};
