#include "stdafx.h"
#include "Role.h"
#include "RoleDefine.h"


Role::Role() {
}


Role::~Role() {
}

void Role::enterScene() {
    //this->call("enterScene", nullptr);
}

void Role::createDefine() {
    mDBInterface = new RoleDefine();
}

