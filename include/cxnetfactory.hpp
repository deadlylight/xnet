#pragma once
#include <memory>
#include <string>

using namespace std;

class IXNet;

class CXNetFactory
{
public:
    CXNetFactory() = delete;
    static shared_ptr<IXNet> createXNet();
};
