#pragma once
#include "DBDefine.h"
#include "Default.h"
#include "DBStream.h"
#include "CharBuffer.h"
class RoleDefine :
    public DBDefine {
    int id;
    int level;
    int vip;
    CharBuffer<Default::NameSize> name;

    virtual const char* table() override {
        return "role";
    }
    virtual const char* key() override {
        return "id";
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

