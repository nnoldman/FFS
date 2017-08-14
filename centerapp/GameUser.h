#pragma once
#include "DBObject.h"
#include "GameUserDefine.h"
class GameUser:public DBObject
{
public:
    GameUser();
    ~GameUser();

    // Í¨¹ý BaseObject ¼Ì³Ð
    virtual void createDefine() override;

    virtual bool initialize() override;

    inline GameUserDefine* getDefine() const;

};


inline GameUserDefine* GameUser::getDefine() const
{
    return (GameUserDefine*)this->dbInterface_;
}
