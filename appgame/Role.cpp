#include "stdafx.h"
#include "Role.h"
#include "GameRoleDefine.h"

Role::Role()
{
}


Role::~Role()
{
}

bool Role::initialize()
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Role::createDefine()
{
    this->dbInterface_ = new GameRoleDefine();
}

GameRoleDefine* Role::getDefine() const
{
    return (GameRoleDefine*)this->dbInterface_;
}

void Role::syncToClient()
{
    throw std::exception("The method or operation is not implemented.");
}
