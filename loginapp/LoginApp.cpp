#include "stdafx.h"
#include "LoginApp.h"
#include "LoginNetAgent.h"

App* CrateApp(int narg, const char** args) {
    return new LoginApp(narg, args);
}

LoginApp::LoginApp(int narg, const char** args)
    : App(narg, args)
    , mNetAgent(nullptr) {

}

LoginApp::~LoginApp() {
    dSafeDelete(mNetAgent);
}

bool LoginApp::initialize() {
    if (!__super::initialize())
        return false;
    mNetAgent = new LoginNetAgent();
    mNetAgent->initialize();
    return true;
}
