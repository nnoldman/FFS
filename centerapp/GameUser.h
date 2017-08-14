#pragma once
#include "DBObject.h"
#include "GameUserDefine.h"
#include "Role.h"
class GameUser:public DBObject
{
public:
    GameUser();
    ~GameUser();

    // Í¨¹ý BaseObject ¼Ì³Ð
    virtual void createDefine() override;

    virtual bool initialize() override;

    inline GameUserDefine* getDefine() const;

    void onEnterGate();

    Role* getRole(int index) const;

private:
    Role roles_[Default::Capacity::Role];
};


inline GameUserDefine* GameUser::getDefine() const
{
    return (GameUserDefine*)this->dbInterface_;
}


