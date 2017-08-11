#pragma once
#include "DBDefine.h"
#include "Default.h"
#include "DBStream.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"

class GlobalRoleDefine : public DBDefine
{
public:
    static const DBTableDefine Define;
public:
    CharBuffer<Default::NameSize> name;
    int id;
    int level;
    int vip;

    virtual const char* table() override
    {
        return Define.tableName.c_str();
    }

    virtual const char* key() override
    {
        return Define.primaryKey2.c_str();
    }

    virtual void deserializeMe() override
    {
        stream() >> id;
        stream() >> level;
        stream() >> name;
        stream() >> vip;
    }

    virtual void serializeMe() override
    {
        stream() << id;
        stream() << level;
        stream() << name;
        stream() << vip;
    }

};

__declspec(selectany) const DBTableDefine GlobalRoleDefine::Define =
{
    "global_role","id","name",
    {
        { "id",enum_field_types::MYSQL_TYPE_LONG,0,true,false },
        { "name",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
        { "level",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
        { "vip",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
    },
};

