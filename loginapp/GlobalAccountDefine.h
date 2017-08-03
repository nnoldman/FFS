#pragma once
#include "DBDefine.h"
#include "CharBuffer.h"

class GlobalAccountDefine :
    public DBDefine {
  public:
    CharBuffer<Default::NameSize> user;
    CharBuffer<Default::NameSize> password;
    int accountid;
  public:
    virtual const char* table() override {
        return "global_account";
    }

    virtual const char* key() override {
        return "user";
    }

    virtual void deserialize() override {
        stream() >> accountid;
        stream() >> user;
        stream() >> password;
    }

    virtual void serialize() override {
        stream() << accountid;
        stream() << user;
        stream() << password;
    }

};

