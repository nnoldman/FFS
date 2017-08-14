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
