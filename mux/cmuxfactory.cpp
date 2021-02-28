#include <cmuxfactory.hpp>
#include "cmuxepoll.hpp"

shared_ptr<IMux> CMuxFactory::createMux(const string &inType)
{
    if (inType == "epoll")
    {
        return make_shared<CMuxEpoll>();
    }
    return nullptr;
}
