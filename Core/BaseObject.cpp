#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject() {
}


BaseObject::~BaseObject() {
}

bool BaseObject::init() {
    return true;
}

void BaseObject::setGuid(const char* guid) {

}

std::string BaseObject::guid() {
    return mGUID;
}

void BaseObject::setField(const char* name, const char* value) {

}

void BaseObject::setField(const char* name, int value) {

}

void BaseObject::setField(const char* name, u32 value) {

}

void BaseObject::setField(const char* name, string& value) {

}

void BaseObject::getField(const char* name, u32& value) {

}

void BaseObject::getField(const char* name, string& value) {

}

void BaseObject::getField(const char* name, int& value) {

}
