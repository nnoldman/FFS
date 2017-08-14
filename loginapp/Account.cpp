#include "stdafx.h"
#include "Account.h"
#include "App.h"
#include "Role.h"
#include "Bundle.h"
#include "GlobalAccountDefine.h"
Account::Account()
{
}


Account::~Account()
{
    printf("~Account()\n");
}

void Account::onEnterGate()
{
    //this->call("enterWorld");
}

void Account::onRoleRqEnterWorld(int globalID)
{
    mActiveRole = new Role();
    if (!mActiveRole->initialize())
    {
        assert(0);
        return;
    }
    mActiveRole->setGlobalID(globalID);
    mActiveRole->enterScene();
}

void Account::enterWorld()
{
}



void Account::createDefine()
{
    this->dbInterface_ = new GlobalAccountDefine();
}

inline GlobalAccountDefine * Account::getDefine() const
{
    return nullptr;
}

bool Account::initialize()
{
    if (!__super::initialize())
        return false;
    return true;
}
