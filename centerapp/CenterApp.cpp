#include "stdafx.h"
#include "CenterApp.h"
#include "NetAgent.h"

CenterApp::CenterApp(int narg, const char** args)
    : App(narg, args)
    , mNetAgent(nullptr) {

}

CenterApp::~CenterApp() {
    dSafeDelete(mNetAgent);
}

bool CenterApp::initialize() {
    if (!__super::initialize())
        return false;
    mNetAgent = new NetAgent();
    mNetAgent->initialize();
    return true;
}

const NetConfig& CenterApp::getNetConfig() {
    throw std::exception("The method or operation is not implemented.");
}

const DBConfig& CenterApp::getDataBaseConfig() {
    throw std::exception("The method or operation is not implemented.");
}

bool CenterApp::parseCommandLine() {
    auto commandline = this->getCommandLine();
    commandline.get("serverID", mServerID);
    return mServerID > 0;
}
