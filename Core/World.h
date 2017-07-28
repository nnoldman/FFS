#include "Account.h"
#ifndef World_h__
#define World_h__

class CX_LIB World : public CallbackObject {
  public:
    World();
    virtual ~World();

    Delegate onAccountEnterWorld;
    Delegate onAccountLeaveWorld;

    bool initialize();

  public:

    void reclaimAccount(Account* account);

    void onEnterWorld(Account* account);

    void sync(int account_guid, string cmd);

    virtual void onCallBack(const Delegate& d, uEventArgs* e) override;

  private:
    Map<int, Account*> mAccounts;
};

#endif // World_h__
