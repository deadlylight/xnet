#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <ixnet.hpp>

using namespace std;

class IMux;
class IDispatcher;

class CXNet : public IXNet
{
private:
    shared_ptr<IMux> mMux;
    shared_ptr<IDispatcher> mDispatcher;
    string mBindAddr;

    bool startMux(const string &);
    bool startDispatcher(uint32_t);

public:
    CXNet();
    ~CXNet();

    bool registerTcpServer(shared_ptr<ITcpServer>) override;
    bool registerTcpClient(shared_ptr<ITcpClient>) override;

    bool setBindAddr(const string &) override;

    bool startXNet(const string &, uint32_t) override;
    bool stopXNet() override;
};
