#pragma once
#include "Connection.h"
#include "DBDefine.h"
#include "BaseObject.h"
class Role;
class Account : public BaseObject
{
public:
    Account();
    ~Account();

    virtual bool initialize() override;

    void onEnterGate();

    void onRoleRqEnterWorld(int globalID);

    void enterWorld();

    virtual void createDefine() override;

protected:

    Role* mActiveRole;

};
