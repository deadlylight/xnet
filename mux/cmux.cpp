#include "cmux.hpp"

CMux::CMux()
{
}

CMux::~CMux()
{
}

bool CMux::registerTcpServer(shared_ptr<ITcpServer> inTcpServer)
{
    return true;
}

bool CMux::registerTcpClient(shared_ptr<ITcpClient> inTcpClient)
{
    return true;
}
