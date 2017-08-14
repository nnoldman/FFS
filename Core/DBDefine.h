#pragma once
class DataBase;
#include "DBStream.h"
#include "Value.h"
#include "ServerID.h"
class COREAPI DBDefine
{
public:
    int id;
public:
    virtual ~DBDefine() {}
    virtual const char* table() = 0;

    void setGlobalID(int id);
    virtual const char* key() = 0;
    virtual const char* key2();

    virtual void deserialize() final;
    virtual void serialize() final;

    virtual void serializeMe() = 0;
    virtual void deserializeMe() = 0;

    void set(vector<string>& values);
    //use key()
    bool pull(Value keyvalue);
    //use key()
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
inline	void DBDefine::setGlobalID(int id)
{
    this->id = id;
}

