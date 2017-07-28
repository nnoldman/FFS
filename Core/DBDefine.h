#pragma once
class DataBase;
#include "DBStream.h"
#include "Value.h"
class CX_LIB DBDefine {
  public:
    virtual const char* table() = 0;
    virtual const char* key() = 0;

    virtual void deserialize() = 0;
    virtual void serialize() = 0;

    void set(vector<string>& values) {
        stream_.set(values);
    }
    bool pull(Value keyvalue);
    bool commit(Value keyvalue);
    bool insertAndQuery(Value keyvalue);
  public:
    inline DBStream& stream() {
        return stream_;
    }
  private:
    DBStream stream_;
};

