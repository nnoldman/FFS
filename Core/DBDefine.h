#pragma once
class DataBase;
#include "DBStream.h"
#include "Value.h"
#include "ServerID.h"
class COREAPI DBDefine
{
public:
    virtual ~DBDefine() {}
    virtual const char* table() = 0;
    virtual const char* key() = 0;
    virtual const char* key2()
    {
        return nullptr;
    }

    virtual void deserialize() final
    {
        this->stream().moveToEnd();
        this->deserializeMe();
    }

    virtual void serialize() final
    {
        this->stream().clear();
        this->serializeMe();
    }

    virtual void serializeMe() = 0;
    virtual void deserializeMe() = 0;

    void set(vector<string>& values)
    {
        stream_.set(values);
    }
    bool pull(Value keyvalue);
    bool commit(Value keyvalue);
    bool insertAndQuery(Value keyvalue);
    bool getValues(stringstream& ss);
public:
    inline DBStream& stream()
    {
        return stream_;
    }
protected:

private:
    DBStream stream_;
};

