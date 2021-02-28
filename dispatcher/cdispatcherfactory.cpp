#include <cdispatcherfactory.hpp>
#include "cdispatcher.hpp"

shared_ptr<IDispatcher> CDispatcherFactory::createDispatcher(uint32_t inCount)
{
    shared_ptr<CDispatcher> vDispatcher = make_shared<CDispatcher>(inCount);
    vDispatcher->mSelf = vDispatcher;
    return vDispatcher;
}
