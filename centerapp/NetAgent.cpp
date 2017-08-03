#include "stdafx.h"
#include "NetAgent.h"
#include "Command.pb.h"
#include "Cmd.pb.h"

NetAgent::NetAgent() {
}


NetAgent::~NetAgent() {
    App::Net.onMessage.remove(&::NetAgent::OnMessage, this);
    App::Net.onDisconnect.remove(&::NetAgent::onDisconnect, this);
}

bool NetAgent::initialize() {
    App::Net.onMessage.add(&::NetAgent::OnMessage, this);
    App::Net.onDisconnect.add(&::NetAgent::onDisconnect, this);
    return true;
}

void NetAgent::onDisconnect(Connection* connection) {
    mClients.erase(connection);
}

void NetAgent::OnMessage(ProtocoBuffer* pb, Connection* connection) {

}

bool NetAgent::on_rqCreateAccount(const string& user, const string& password, Connection* con) {
    return false;
}


bool NetAgent::on_rqLoginAccount(string user, string psw, Connection* con) {
    return false;
}

void NetAgent::onLoginSucess(Account* account) {
}

const char* NetAgent::YW_DB = "yourworld";

const char* NetAgent::YW_TABLE_ACCOUNT = "yw_account";

const char* NetAgent::YW_TABLE_ACCOUNT_USER = "user";

const char* NetAgent::YW_TABLE_ACCOUNT_PSD = "psw";

const char* NetAgent::YW_TABLE_ACCOUNT_ID = "guid";

Map<Connection*, int> NetAgent::mClients;

