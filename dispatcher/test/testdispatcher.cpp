#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <idispatcher.hpp>
#include <ievent.hpp>
#include <cdispatcherfactory.hpp>

static atomic<int> sCount;

class CTestEvent : public IEvent
{
public:
    ~CTestEvent()
    {

    }
    int getAffinity() override
    {
        return -1;
    }
    void handleEvent(int inAffinity) override
    {
        cout << "CTestEvent::handleEvent by " << inAffinity << endl;
        sCount--;
    }
};

int main()
{
    shared_ptr<IDispatcher> vDispatcher = CDispatcherFactory::createDispatcher(2);
    vDispatcher->startDispatcher();

    int vLoop = 10;
    sCount = vLoop;
    while (vLoop > 0)
    {
        vLoop--;
        shared_ptr<CTestEvent> vEvent = make_shared<CTestEvent>();
        vDispatcher->addDispatcherEvent(vEvent);
    }

    while (sCount > 0)
    {
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    return 0;
}
