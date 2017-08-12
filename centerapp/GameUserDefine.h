#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"
#include "ServerID.h"

class GameUserDefine :
    public DBDefine
{
public:
    static const DBTableDefine& GetDefine()
    {
        static const DBTableDefine TheTable
        {
            "game_user",false,"id",nullptr,
            {
                { "id",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role1",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role2",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
                { "role3",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
            },
        };
        return TheTable;
    };
public:
    int id;

    int role1;
    int role2;
    int role3;
public:
    virtual const char* key() override
    {
        return GetDefine().key();
    }
    virtual const char* table() override
    {
        return GetDefine().tableName();
    }
    virtual void deserializeMe() override
    {
        stream() >> id;

        stream() >> role1;
        stream() >> role2;
        stream() >> role3;
    }

    virtual void serializeMe() override
    {
        stream() << id;

        stream() << role1;
        stream() << role2;
        stream() << role3;
    }
};
