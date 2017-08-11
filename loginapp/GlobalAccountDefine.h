#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"

class GlobalAccountDefine :
    public DBDefine
{
public:
    static const DBTableDefine Define;
public:
    CharBuffer<Default::NameSize> user;
    CharBuffer<Default::NameSize> password;
    int id;
    int late_serverid1;
    int late_serverid2;
    int late_serverid3;
public:
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
        stream() >> user;
        stream() >> password;
        stream() >> late_serverid1;
        stream() >> late_serverid2;
        stream() >> late_serverid3;
    }

    virtual void serializeMe() override
    {
        stream() << id;
        stream() << user;
        stream() << password;
        stream() << late_serverid1;
        stream() << late_serverid2;
        stream() << late_serverid3;
    }
};

__declspec(selectany) const DBTableDefine GlobalAccountDefine::Define
{
    "global_account","id","user",
    {
        { "id",enum_field_types::MYSQL_TYPE_LONG,0,true,false },
        { "user",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
        { "password",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
        { "late_serverid1",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
        { "late_serverid2",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
        { "late_serverid3",enum_field_types::MYSQL_TYPE_LONG,0,false,false },
    },
};

