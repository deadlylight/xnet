#include <xnet.hpp>

class CTestConn : public ITcpReceiver
{
private:
    shared_ptr<ITcpSender> mSender;

public:
    CTestConn(shared_ptr<ITcpSender> inSender)
        : mSender(inSender)
    {
    }
};

class CTestTcpServer : public ITcpServer
{
private:
    uint16_t mPort;

public:
    CTestTcpServer(uint16_t inPort)
        : mPort(inPort)
    {
    }

    uint16_t getPort() override
    {
        return mPort;
    }

    shared_ptr<ITcpReceiver> onNewConnection(shared_ptr<ITcpSender> inSender) override
    {
        return make_shared<CTestConn>(inSender);
    }
};

int main()
{
    shared_ptr<IXNet> vXNet = CXNetFactory::createXNet(string());
    vXNet->registerTcpServer();
    return 0;
}
