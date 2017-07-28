#include "stdafx.h"
#include "NetAgent.h"
#include "Account.h"
#include "GlobalAccountDefine.h"
#include "Command.pb.h"
#include "Cmd.pb.h"

NetAgent::NetAgent() {
}


NetAgent::~NetAgent() {
}

void NetAgent::onCallBack(const Delegate& d, uEventArgs* e) {
    if (d == App::Net.onMessage) {
        NetWork::MsgArgs* arg = (NetWork::MsgArgs*)e;
        PKG* pkg = arg->pkg;
        Connection* connect = arg->connect;

        switch (pkg->opcode) {
        case Cmd::CLIENT_COMMAND::RQLoginGameServer: {
            auto req = (Cmd::ReqLoginGameServer*)pkg;
        }
        break;
        default:
            break;
        }
    } else if (d == App::Net.onDisconnect) {
        NetWork::ConnectArg* arg = (NetWork::ConnectArg*)e;
        mClients.erase(arg->connect);
    }
}

bool NetAgent::on_rqCreateAccount(const string& user, const string& password, Connection* con) {
    return false;
}


bool NetAgent::on_rqLoginAccount(string user, string psw, Connection* con) {
    return false;
}

void NetAgent::onLoginSucess(Account* account) {
    App::Gate.onEnter(account);
}

const char* NetAgent::YW_DB = "yourworld";

const char* NetAgent::YW_TABLE_ACCOUNT = "yw_account";

const char* NetAgent::YW_TABLE_ACCOUNT_USER = "user";

const char* NetAgent::YW_TABLE_ACCOUNT_PSD = "psw";

const char* NetAgent::YW_TABLE_ACCOUNT_ID = "guid";

Map<Connection*, int> NetAgent::mClients;

