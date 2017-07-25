#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
class CX_LIB AccountDefine :
    public DBDefine {
  public:
    int id;
    CharBuffer<Default::NameSize> user;
    CharBuffer<Default::NameSize> password;
  public:
    virtual const char* table() override {
        return "role";
    }

    virtual const char* key() override {
        return "id";
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

