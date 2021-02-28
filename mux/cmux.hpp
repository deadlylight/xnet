#include <imux.hpp>

class CMux : public IMux
{
private:

protected:
    string mBindAddr;
    weak_ptr<CMux> mSelf;

public:
    CMux();
    ~CMux();

    bool registerTcpServer(shared_ptr<ITcpServer>) override;
    bool registerTcpClient(shared_ptr<ITcpClient>) override;
};
