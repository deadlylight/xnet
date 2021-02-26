#pragma once
#include <cstdint>

class IDispatcher
{
public:
    virtual ~IDispatcher() = default;
    virtual bool startDispatcher(uint32_t) = 0;
    virtual bool stopDispatcher() = 0;
};
