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
    if (def->pull(def->id))
    {
        for (int i = 0; i < Default::Capacity::Role; ++i)
        {
            int roleID = (&def->role1)[i];
            if (roleID > 0)
            {
                roles_[i].setGlobalID(roleID);
                roles_[i].getDefine()->pull(roleID);
            }
        }
    }
}

Role* GameUser::getRole(int index) const
{
    return nullptr;
}
