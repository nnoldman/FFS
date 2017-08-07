#pragma once
class DataBase;
#include "DBStream.h"
#include "Value.h"
class COREAPI DBDefine {
  public:
    virtual ~DBDefine() {}
    virtual const char* table() = 0;
    virtual const char* key() = 0;
    virtual const char* key2() {
        return nullptr;
    }

    virtual void deserialize() = 0;
    virtual void serialize() = 0;

    void set(vector<string>& values) {
        stream_.set(values);
    }
    bool pull(Value keyvalue);
    bool commit(Value keyvalue);
    bool insertAndQuery(Value keyvalue);
    bool getValues(stringstream& ss);
  public:
    inline DBStream& stream() {
        return stream_;
    }
  private:
    DBStream stream_;
};

