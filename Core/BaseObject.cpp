#include "stdafx.h"
#include "BaseObject.h"
#include "DBDefine.h"


BaseObject::BaseObject()
    : mNetInterface(nullptr)
    , mDBInterface(nullptr) {
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

void BaseObject::sendDBToClient(string data) {

}

