#include "stdafx.h"
#include "Account.h"
#include "App.h"
#include "Role.h"
#include "Bundle.h"
#include "AccountDefine.h"
Account::Account()
    : mNetInterface(nullptr) {
}


Account::~Account() {
}



void Account::onEnterGate() {
    //this->call("enterWorld");
}

void Account::onRoleRqEnterWorld(string guid) {
    mActiveRole = new Role();
    if (!mActiveRole->initialize()) {
        assert(0);
        return;
    }
    mActiveRole->setGuid(guid.c_str());
    mActiveRole->enterScene();
}

void Account::sendDBToClient(string data) {
    assert(mNetInterface);
    rtDBData rt;
    assert(data.length() < Default::DataSize);
    dMemoryCopy(rt.data, (void*)data.c_str(), data.length());
    //SendPKG(mNetInterface->getSocket(), rt);
}

void Account::setConnection(Connection* connect) {
    mNetInterface = connect;
}



void Account::enterWorld() {
}



void Account::createDefine() {
    mDBInterface = new AccountDefine();
}

bool Account::initialize() {
    if (!__super::initialize())
        return false;
    return true;
}
