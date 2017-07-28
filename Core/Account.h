#pragma once
#include "Connection.h"
#include "DBDefine.h"
#include "BaseObject.h"
class Role;
class CX_LIB Account : public BaseObject {
  public:
    Account();
    ~Account();

    virtual bool initialize() override;

    void onEnterGate();

    void onRoleRqEnterWorld(int globalID);

    void sendDBToClient(string data);

    void setConnection(Connection* connect);

    void sync(string data);

    void enterWorld();

    inline Connection* getNetInterface();


    virtual void createDefine() override;

  protected:

    void createRole();

  protected:

    Role* mActiveRole;

    Connection* mNetInterface;
};
inline Connection* Account::getNetInterface() {
    return mNetInterface;
}
