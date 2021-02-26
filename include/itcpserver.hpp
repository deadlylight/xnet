#pragma once
#include <cstdint>
#include <memory>

using namespace std;

class ITcpReceiver;
class ITcpSender;

class ITcpServer
{
public:
    virtual ~ITcpServer() = default;
    virtual uint16_t getPort() = 0;
    virtual shared_ptr<ITcpReceiver> onNewConnection(shared_ptr<ITcpSender>) = 0;
};
