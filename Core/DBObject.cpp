#include "stdafx.h"
#include "DBObject.h"
#include "App.h"


DBObject::DBObject() {
}


DBObject::~DBObject() {
}

bool DBObject::fetchByField(const char* field) {
    return true;
    //ScriptArgs arg;
    //arg << field;
    //return App::Script.invoke<bool>(nameSpace(), className(), "fetchByField", mObject, arg.pointer());
}

void DBObject::sync(string data) {

}

bool DBObject::fetch() {
    bool res = fetchByField(dbKey());
    //callDB("onFetch", nullptr);
    return res;
}

bool DBObject::saveToDB() {
    return false;
}

bool DBObject::createAndInsertToDB() {
    return false;
}

void DBObject::requireGUID() {
    //mGUID = uPlatform::generateGUIDSimpleString();
    //setField("guid", mGUID);
}


const char* DBObject::dbKey() {
    return guid();
}
