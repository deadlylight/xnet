#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <ixnet.hpp>

using namespace std;

class IMux;
class IDispatcher;

class CXNetImpl : public IXNet
{
private:
    shared_ptr<IMux> mMux;
    shared_ptr<IDispatcher> mDispatcher;

    bool startMux(const string &);
    bool startDispatcher(uint32_t);

public:
    CXNetImpl();
    ~CXNetImpl();

    bool registerTcpServer(shared_ptr<ITcpServer>) override;
    bool registerTcpClient(shared_ptr<ITcpReceiver>) override;
    bool registerUdp(shared_ptr<IUdpReceiver>) override;

    bool setBindAddr(const string &) override;

    bool startXNet(const string &, uint32_t) override;
    bool stopXNet() override;
};
