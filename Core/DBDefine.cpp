#include "stdafx.h"
#include "DBDefine.h"
#include "App.h"
#include "DataBase.h"
#include "Value.h"

bool DBDefine::pull(Value keyvalue) {
    return App::DataBase.pull(keyvalue, this);
}

bool DBDefine::commit(Value keyvalue) {
    return App::DataBase.pull(keyvalue, this);
}

bool DBDefine::insertAndQuery(Value keyvalue) {
    return App::DataBase.pull(keyvalue, this);
}

