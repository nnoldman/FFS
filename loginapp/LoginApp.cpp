#include "stdafx.h"
#include "LoginApp.h"
#include "LoginNetAgent.h"
#include "DBTableDefine.h"
#include "GlobalRoleDefine.h"
#include "GlobalAccountDefine.h"

LoginApp::LoginApp(int narg, const char** args)
    : App(narg, args)
    , mNetAgent(nullptr) {

}

LoginApp::~LoginApp() {
    dSafeDelete(mNetAgent);
}

const NetConfig& LoginApp::getNetConfig() {
    return Config.login.net;
}

const DBConfig& LoginApp::getDataBaseConfig() {
    return Config.login.db;
}

bool LoginApp::parseCommandLine() {
    return true;
}

void LoginApp::archive() {
}

bool LoginApp::onInitializeEnd() {
    return true;
}

bool LoginApp::onInitializeNet() {
    mNetAgent = new LoginNetAgent();
    if (!mNetAgent->initialize())
        return false;
    return true;
}

const vector<const DBTableDefine*> LoginApp::getTableDefines() {
    static const vector<const DBTableDefine*> ret{
        &GlobalAccountDefine::Define,
        &GlobalRoleDefine::Define,
    };
    return ret;
}

