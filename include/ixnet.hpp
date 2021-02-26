#pragma once
#include <memory>
#include <string>

using namespace std;

class ITcpServer;
class ITcpReceiver;
class IUdpReceiver;

class IXNet
{
public:
    virtual ~IXNet() = default;

    virtual bool registerTcpServer(shared_ptr<ITcpServer>) = 0;
    virtual bool registerTcpClient(shared_ptr<ITcpReceiver>) = 0;
    virtual bool registerUdp(shared_ptr<IUdpReceiver>) = 0;

    virtual bool setBindAddr(const string &) = 0;

    virtual bool startXNet(const string &, uint32_t) = 0;
    virtual bool stopXNet() = 0;
};
