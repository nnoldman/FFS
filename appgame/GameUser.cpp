#include "stdafx.h"
#include "GameUser.h"
#include "GameUserDefine.h"


GameUser::GameUser()
{
}


GameUser::~GameUser()
{
}

void GameUser::createDefine()
{
    this->dbInterface_ = new GameUserDefine();
}

bool GameUser::initialize()
{
    return __super::initialize();
}

void GameUser::onEnterGate()
{
    auto def = getDefine();
    for (auto& iter : roles_)
        iter.initialize();

    if (def->pull(def->id))
    {
        for (int i = 0; i < Default::Capacity::Role; ++i)
        {
            roles_[i].initialize();

            int roleID = (&def->role1)[i];
            if (roleID > 0)
            {
                roles_[i].setGlobalID(roleID);
                roles_[i].getDefine()->pull(roleID);
            }
        }
    }
}

Role* GameUser::getRole(int index)
{
    return &roles_[index];
}

void GameUser::activeRole(int index0)
{
    auto role = getRole(index0);
    if (role->valid())
    {
        role->setConnection(getNetInterface());
        role->syncToClient();
    }
    else
    {
        assert(false);
    }
}
