#include "stdafx.h"
#include "World.h"
#include "App.h"
#include "DBObject.h"
#include "Connection.h"


World::World() {
}


World::~World() {
    App::Net.onDisconnect.remove(&World::onDisconnect, this);
    dSafeDeleteMap2(mAccounts);
}

bool World::initialize() {
    App::Net.onDisconnect.add(&World::onDisconnect, this);
    return true;
}

void World::reclaimAccount(DBObject* account) {
    onAccountLeaveWorld.invoke(account);

    assert(account);
    assert(mAccounts.find(account->globalID()) != mAccounts.end());
    mAccounts.erase(account->globalID());
    dSafeDelete(account);
}

void World::onEnterWorld(DBObject* account) {
    assert(mAccounts.find(account->globalID()) == mAccounts.end());
    mAccounts.insert(make_pair(account->globalID(), account));
    onAccountEnterWorld.invoke(account);
}

void World::sync(int account_guid, string cmd) {
    auto acc = mAccounts.find(account_guid);
    assert(acc != mAccounts.end());
    acc->second->sendDBToClient(cmd);
}

void World::onDisconnect(Connection* connection) {
    auto ibegin = mAccounts.begin();
    auto iend = mAccounts.end();
    for (; ibegin != iend; ++ibegin) {
        if (ibegin->second->getNetInterface() == connection) {
            reclaimAccount(ibegin->second);
            return;
        }
    }
}
