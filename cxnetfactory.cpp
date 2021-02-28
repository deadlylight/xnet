#include <cxnetfactory.hpp>
#include "cxnet.hpp"

shared_ptr<IXNet> CXNetFactory::createXNet()
{
    return make_shared<CXNet>();
}
