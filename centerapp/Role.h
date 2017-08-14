#pragma once
#include "DBObject.h"
#include "GameRoleDefine.h"

class Role:DBObject
{
public:
    Role();
    ~Role();

    virtual bool initialize() override;
    virtual void createDefine()override;

    GameRoleDefine* getDefine() const;
};

