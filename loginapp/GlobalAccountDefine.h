#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
#include "DBTableDefine.h"

class GlobalAccountDefine :
    public DBDefine {
  public:
    static const DBTableDefine Define;
  public:
    CharBuffer<Default::NameSize> user;
    CharBuffer<Default::NameSize> password;
    int id;
  public:
    virtual const char* table() override {
        return "global_account";
    }

    virtual const char* key() override {
        return "user";
    }

    virtual void deserialize() override {
        stream() >> id;
        stream() >> user;
        stream() >> password;
    }

    virtual void serialize() override {
        stream() << id;
        stream() << user;
        stream() << password;
    }

};

__declspec(selectany) const DBTableDefine GlobalAccountDefine::Define {
    "global_account","id","user", {
        { "id",enum_field_types::MYSQL_TYPE_LONG,0,true,false },
        { "user",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
        { "password",enum_field_types::MYSQL_TYPE_VARCHAR,Default::NameSize,false,false },
    },
};

