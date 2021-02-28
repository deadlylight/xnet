#pragma once
#include <memory>

using namespace std;

class IMsg;

class ITcpSender
{
public:
    virtual ~ITcpSender() = default;
    virtual bool sendMsg(shared_ptr<IMsg>) = 0;
};
