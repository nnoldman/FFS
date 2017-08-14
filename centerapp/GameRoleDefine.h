#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"

class GameRoleDefine :
    public DBDefine
{
public:
    static const DBTableDefine& GetDefine()
    {
        static const DBTableDefine TheTable
        {
            "game_role",false,"id",nullptr,
            {
                { "id",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role1",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role2",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role3",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
            },
        };
        return TheTable;
    }

    virtual const char* table() override
    {
        return GetDefine().tableName();
    }
public:
    CharBuffer<Default::NameSize> name;
    int vip;
    int level;
    int sex;
    int job;
public:
    virtual const char* key() override
    {
        return GetDefine().key();
    }

    virtual void deserializeMe() override
    {
        stream() >> id;
        stream() >> name;
        stream() >> vip;
        stream() >> level;
        stream() >> sex;
        stream() >> job;
    }

    virtual void serializeMe() override
    {
        stream() << id;
        stream() << name;
        stream() << vip;
        stream() << level;
        stream() << sex;
        stream() << job;
    }
};


