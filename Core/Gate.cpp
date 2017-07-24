#include "stdafx.h"
#include "Gate.h"
#include "Account.h"
#include "AccountDefine.h"
#include "App.h"
#include "DataBase.h"


Gate::Gate() {
}


Gate::~Gate() {
}

void Gate::onEnter(Account* account) {
    AccountDefine def;
    App::DataBase.pull(account->guid(),&def);
}
