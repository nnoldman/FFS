#pragma once
#include "DBDefine.h"
#include "Default.h"
#include "DBStream.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"

class GlobalRoleDefine : public DBDefine {
  public:
    static const DBTableDefine Define;
  public:
    CharBuffer<Default::NameSize> name;
    int id;
    int level;
    int vip;

    virtual const char* table() override {
        return Define.tableName.c_str();
    }

    virtual const char* key() override {
        return Define.primaryKey1.c_str();
    }

    virtual void deserialize() override {
        stream() >> id;
        stream() >> level;
        stream() >> name;
        stream() >> vip;
    }

    virtual void serialize() override {
        stream() << id;
        stream() << level;
        stream() << name;
        stream() << vip;
    }

};

__declspec(selectany) const DBTableDefine GlobalRoleDefine::Define = {
    "global_role","name","id",
    {
        { "name",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
        { "id",enum_field_types::MYSQL_TYPE_DECIMAL,0,true,false },
        { "level",enum_field_types::MYSQL_TYPE_DECIMAL,0,true,false },
        { "vip",enum_field_types::MYSQL_TYPE_DECIMAL,0,true,false },
    },
};
