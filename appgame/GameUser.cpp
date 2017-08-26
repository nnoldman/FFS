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
    role_.initialize();

    if (def->pull(def->id))
    {
        if (def->role > 0)
        {
            role_.setGlobalID(def->role);
            role_.getDefine()->pull(def->role);
        }
    }
}

Role* GameUser::getRole()
{
    return &role_;
}

void GameUser::activeRole()
{
    if (role_.valid())
    {
        role_.setConnection(getNetInterface());
        role_.syncToClient();
    }
    else
    {
        assert(false);
    }
}
