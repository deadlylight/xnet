#pragma once
#include <memory>
#include <string>
#include "cmux.hpp"

using namespace std;

class ITcpServer;
class ITcpClient;

class CMuxEpoll : public CMux
{
public:
    CMuxEpoll();
    ~CMuxEpoll();

    bool setBindAddr(const string &) override;
    bool startMux() override;
    bool stopMux() override;
};
