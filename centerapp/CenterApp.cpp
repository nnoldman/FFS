#include "stdafx.h"
#include "CenterApp.h"
#include "NetAgent.h"
#include "GameUserDefine.h"
#include "GameRoleDefine.h"

CenterApp::CenterApp(int narg, const char** args)
    : App(narg, args)
    , mNetAgent(nullptr)
{

}

CenterApp::~CenterApp()
{
    dSafeDelete(mNetAgent);
}

const NetConfig& CenterApp::getNetConfig()
{
    return *Config.center.centers[mServerID];
}

const DBConfig& CenterApp::getDataBaseConfig()
{
    return Config.center.db;
}

bool CenterApp::parseCommandLine()
{
    auto commandline = this->getCommandLine();
    commandline.get("serverID", mServerID);
    string serverID;
    commandline.get("serverID", serverID);
    ServerID::set(serverID.c_str());
    return mServerID > 0;
}

void CenterApp::archive()
{
}

bool CenterApp::onInitializeEnd()
{
    return true;
}

bool CenterApp::onInitializeNet()
{
    mNetAgent = new NetAgent();
    mNetAgent->initialize();
    return true;
}

const vector<const DBTableDefine*>& CenterApp::getTableDefines() const
{
    static const vector<const DBTableDefine*> ret
    {
        &GameUserDefine::GetDefine(),
        &GameRoleDefine::GetDefine(),
    };
    return ret;
}
