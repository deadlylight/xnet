#include <cxnetfactory.hpp>
#include "cxnetimpl.hpp"

shared_ptr<IXNet> CXNetFactory::createXNet()
{
    return make_shared<CXNetImpl>();
}
