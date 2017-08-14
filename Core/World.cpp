#include "stdafx.h"
#include "World.h"
#include "App.h"
#include "DBObject.h"
#include "Connection.h"


World::World()
{
}


World::~World()
{
    App::Net.onDisconnect.remove(&World::onDisconnect, this);
    dSafeDeleteMap2(accounts_);
}

bool World::initialize()
{
    App::Net.onDisconnect.add(&World::onDisconnect, this);
    return true;
}

void World::reclaimAccount(DBObject* account)
{
    onAccountLeaveWorld.invoke(account);

    assert(account);
    assert(accounts_.find(account->globalID()) != accounts_.end());
    accounts_.erase(account->globalID());
    dSafeDelete(account);
}

void World::onEnterWorld(DBObject* account)
{
    assert(accounts_.find(account->globalID()) == accounts_.end());
    accounts_.insert(make_pair(account->globalID(), account));
    onAccountEnterWorld.invoke(account);
}

void World::sync(int account_guid, string cmd)
{
    auto acc = accounts_.find(account_guid);
    assert(acc != accounts_.end());
    acc->second->sendDBToClient(cmd);
}

void World::onDisconnect(Connection* connection)
{
    auto ibegin = accounts_.begin();
    auto iend = accounts_.end();
    for (; ibegin != iend; ++ibegin)
    {
        if (ibegin->second->getNetInterface() == connection)
        {
            reclaimAccount(ibegin->second);
            return;
        }
    }
}
