#include "stdafx.h"
#include "World.h"
#include "App.h"


World::World() {
}


World::~World() {
    App::Net.onDisconnect -= this;
    dSafeDeleteMap2(mAccounts);
}

bool World::initialize() {
    App::Net.onDisconnect += this;
    return true;
}

void World::reclaimAccount(Account* account) {
    onAccountLeaveWorld.trigger();

    assert(account);
    assert(mAccounts.find(account->globalID()) != mAccounts.end());
    mAccounts.erase(account->globalID());
    dSafeDelete(account);
}

void World::onEnterWorld(Account* account) {
    assert(mAccounts.find(account->globalID()) == mAccounts.end());
    mAccounts.insert(make_pair(account->globalID(), account));
    account->onEnterGate();
    onAccountEnterWorld.trigger();
}

void World::sync(int account_guid, string cmd) {
    auto acc = mAccounts.find(account_guid);
    assert(acc != mAccounts.end());
    Account* account = acc->second;
    account->sendDBToClient(cmd);
}

void World::onCallBack(const Delegate& d, uEventArgs* e) {
    if (d == App::Net.onDisconnect) {
        NetWork::ConnectArg* arg = (NetWork::ConnectArg*)e;

        auto ibegin = mAccounts.begin();
        auto iend = mAccounts.end();
        for (; ibegin != iend; ++ibegin) {
            if (ibegin->second->getNetInterface() == arg->connect) {
                reclaimAccount(ibegin->second);
                return;
            }
        }
    }
}
