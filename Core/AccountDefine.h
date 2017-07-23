#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"
class AccountDefine :
    public DBDefine {
  public:
    int id;
    CharBuffer<Default::NameSize> user;
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
    }

    virtual void serialize() override {
        stream() << id;
        stream() << user;
    }

};

