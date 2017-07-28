#include "stdafx.h"
#include "BaseObject.h"
#include "DBDefine.h"


BaseObject::BaseObject() {
}

BaseObject::~BaseObject() {
    dSafeDelete(mDBInterface);
}
bool BaseObject::initialize() {
    this->createDefine();
    return true;
}

void BaseObject::setGlobalID(int globalID) {
    mGlobalID = globalID;
}

