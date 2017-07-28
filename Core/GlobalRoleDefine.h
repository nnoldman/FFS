#pragma once
#include "DBDefine.h"
#include "Default.h"
#include "DBStream.h"
#include "CharBuffer.h"
class CX_LIB GlobalRoleDefine : public DBDefine {
    CharBuffer<Default::NameSize> name;
    int id;
    int level;
    int vip;

    virtual const char* table() override {
        return "global_role";
    }

    virtual const char* key() override {
        return "name";
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

