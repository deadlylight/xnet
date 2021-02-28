#include <iostream>
#include <xnet.hpp>

using namespace std;

class CTestConn : public ITcpReceiver
{
private:
    shared_ptr<ITcpSender> mSender;

public:
    CTestConn(shared_ptr<ITcpSender> inSender)
        : mSender(inSender)
    {
    }
    unsigned int getTimeout() override
    {
        return 0;
    }
    void onData(shared_ptr<IMsg>)
    {
        cout << "CTestConn::onData" << endl;
    }
    void onError()
    {
        cout << "CTestConn::onError" << endl;
    }
    void onTimeout()
    {
        cout << "CTestConn::onTimeout" << endl;
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
    shared_ptr<IXNet> vXNet = CXNetFactory::createXNet();
    shared_ptr<CTestTcpServer> vServer = make_shared<CTestTcpServer>(50445);
    vXNet->registerTcpServer(vServer);
    return 0;
}
