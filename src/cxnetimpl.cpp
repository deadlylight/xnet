#include <imux.hpp>
#include <idispatcher.hpp>
#include <cmuxfactory.hpp>
#include "cxnetimpl.hpp"

CXNetImpl::CXNetImpl()
{
}

CXNetImpl::~CXNetImpl()
{
}

bool CXNetImpl::registerTcpServer(shared_ptr<ITcpServer> inTcpServer)
{
    return mMux->registerTcpServer(inTcpServer);
}

bool CXNetImpl::registerTcpClient(shared_ptr<ITcpReceiver> inTcpReceiver)
{
    return mMux->registerTcpReceiver(inTcpReceiver);
}

bool CXNetImpl::registerUdp(shared_ptr<IUdpReceiver> inUdpreceiver)
{
    return mMux->registerUdp(inUdpreceiver);
}

bool CXNetImpl::setBindAddr(const string & inAddr)
{
    if (mMux)
    {
        return mMux->setBindAddr(inAddr);
    }
    return false;
}

bool CXNetImpl::startXNet(const string &inAddr, uint32_t inCount)
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

bool CXNetImpl::stopXNet()
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

bool CXNetImpl::startMux(const string &inType)
{
    mMux = CMuxFactory::createMux(inType);
    return mMux != nullptr;
}

bool CXNetImpl::startDispatcher(uint32_t inCount)
{
    mDispatcher = CDispatcherFactory::createDispatcher(inCount);
    return mDispatcher != nullptr;
}
