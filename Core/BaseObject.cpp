#include "stdafx.h"
#include "BaseObject.h"
#include "DBDefine.h"


BaseObject::BaseObject() {
    createDefine();
}

BaseObject::~BaseObject() {
    dSafeDelete(mDBInterface);
}

DBDefine* BaseObject::getDBInterface() const {
    return mDBInterface;
}

void BaseObject::setField(const char* key, Value value) {

}

bool BaseObject::initialize() {
    return true;
}

void BaseObject::setGuid(const char* guid) {
    mGUID = guid;
}


const char* BaseObject::guid() const {
    return mGUID.c_str();
}
