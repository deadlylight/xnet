#pragma once

class IEvent
{
public:
    virtual ~IEvent() = default;
    virtual int getAffinity() = 0;
    virtual void handleEvent(int inAffinity) = 0;
};
