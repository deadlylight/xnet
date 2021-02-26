#pragma once

class ITcpSender
{
public:
    virtual ~ITcpSender() = default;
    virtual bool sendMsg(shared_ptr<IMsg>) = 0;
};
