#pragma once
#include <string>

using namespace std;

class IMux
{
public:
    virtual ~IMux() = default;
    virtual bool setBindAddr(const string &) = 0;
    virtual bool stopMux() = 0;

    virtual bool registerTcpServer(shared_ptr<ITcpServer>) = 0;
    virtual bool registerTcpReceiver(shared_ptr<ITcpReceiver>) = 0;
    virtual bool registerUdp(shared_ptr<IUdpReceiver>) = 0;
};
