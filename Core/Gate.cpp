#include "stdafx.h"
#include "Gate.h"
#include "Account.h"
#include "GlobalAccountDefine.h"
#include "App.h"
#include "DataBase.h"


Gate::Gate() {
}


Gate::~Gate() {
}

void Gate::onEnter(Account* account) {
    GlobalAccountDefine def;
    App::DataBase.pull(account->globalID(), &def);
}
