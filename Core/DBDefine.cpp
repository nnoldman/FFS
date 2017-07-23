#include "stdafx.h"
#include "DBDefine.h"
#include "App.h"
#include "DataBase.h"
#include "Value.h"

bool DBDefine::pull(Value keyvalue) {
    return App::DataBase.pull(keyvalue, this);
}

