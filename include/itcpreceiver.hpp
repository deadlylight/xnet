#pragma once
#include <memory>

using namespace std;

class IMsg;

class ITcpReceiver
{
public:
    virtual ~ITcpReceiver() = default;
    virtual uint32_t getTimeout() = 0;
    virtual void onData(shared_ptr<IMsg>) = 0;
    virtual void onError() = 0;
    virtual void onTimeout() = 0;
};
