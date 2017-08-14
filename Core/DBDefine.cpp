#include "stdafx.h"
#include "DBDefine.h"
#include "App.h"
#include "DataBase.h"
#include "Value.h"

const char* DBDefine::key2()
{
    return nullptr;
}

void DBDefine::deserialize()
{
    this->stream().moveToEnd();
    this->deserializeMe();
}

void DBDefine::serialize()
{
    this->stream().clear();
    this->serializeMe();
}

void DBDefine::set(vector<string>& values)
{
    stream_.set(values);
}

bool DBDefine::pull(Value keyvalue)
{
    return App::DataBase.pull(keyvalue, this);
}

bool DBDefine::commit(Value keyvalue)
{
    return App::DataBase.commit(keyvalue, this);
}
//delete from global_account where user = '123';
bool DBDefine::insertAndQuery(Value keyvalue)
{
    if (App::DataBase.insert(keyvalue, this))
        return pull(keyvalue);
    return false;
}

bool DBDefine::getValues(stringstream& ss)
{
    for (auto i = 0; i < stream_.getContents().size(); ++i)
    {
        auto content = stream_.getContents()[i];
        ss << content;
        if (i != stream_.getContents().size() - 1)
            ss << ",";
    }
    return true;
}

