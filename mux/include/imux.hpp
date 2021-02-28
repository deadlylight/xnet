#pragma once
#include <memory>
#include <string>

using namespace std;

class ITcpServer;
class ITcpClient;

class IMux
{
public:
    virtual ~IMux() = default;
    virtual bool registerTcpServer(shared_ptr<ITcpServer>) = 0;
    virtual bool registerTcpClient(shared_ptr<ITcpClient>) = 0;

    virtual bool setBindAddr(const string &) = 0;
    virtual bool startMux() = 0;
    virtual bool stopMux() = 0;
};
