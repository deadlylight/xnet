#include <imux.hpp>
#include <idispatcher.hpp>
#include <cmuxfactory.hpp>
#include <cdispatcherfactory.hpp>
#include "cxnet.hpp"

CXNet::CXNet()
{
}

CXNet::~CXNet()
{
}

bool CXNet::registerTcpServer(shared_ptr<ITcpServer> inTcpServer)
{
    return mMux->registerTcpServer(inTcpServer);
}

bool CXNet::registerTcpClient(shared_ptr<ITcpClient> inTcpClient)
{
    return mMux->registerTcpClient(inTcpClient);
}

bool CXNet::setBindAddr(const string & inAddr)
{
    if (mMux && (inAddr != mBindAddr))
    {
        return mMux->setBindAddr(inAddr);
    }
    mBindAddr = inAddr;
    return false;
}

bool CXNet::startXNet(const string &inAddr, uint32_t inCount)
{
    if (!startMux(inAddr))
    {
        return false;
    }
    if (!startDispatcher(inCount))
    {
        return false;
    }
    return true;
}

bool CXNet::stopXNet()
{
    if (mMux)
    {
        mMux->stopMux();
    }
    if (mDispatcher)
    {
        mDispatcher->stopDispatcher();
    }
    return true;
}

bool CXNet::startMux(const string &inType)
{
    mMux = CMuxFactory::createMux(inType);
    if (!mMux)
    {
        return false;
    }
    mMux->setBindAddr(mBindAddr);
    return mMux->startMux();
}

bool CXNet::startDispatcher(uint32_t inCount)
{
    mDispatcher = CDispatcherFactory::createDispatcher(inCount);
    if (!mDispatcher)
    {
        return false;
    }
    return mDispatcher->startDispatcher();
}
