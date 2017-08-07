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

void CenterApp::archive() {
    throw std::exception("The method or operation is not implemented.");
}

bool CenterApp::onInitializeEnd() {
    throw std::exception("The method or operation is not implemented.");
}

bool CenterApp::onInitializeNet() {
    mNetAgent = new NetAgent();
    mNetAgent->initialize();
    return true;
}

const vector<const DBTableDefine *> CenterApp::getTableDefines() {
    throw std::exception("The method or operation is not implemented.");
}
