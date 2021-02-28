#pragma once
#include <memory>

using namespace std;

class IDispatcher;

class CDispatcherFactory
{
public:
    CDispatcherFactory() = delete;
    static shared_ptr<IDispatcher> createDispatcher(unsigned int);
};
