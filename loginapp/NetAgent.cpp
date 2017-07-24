#include "stdafx.h"
#include "NetAgent.h"
#include "Account.h"
#include "Command.pb.h"


NetAgent::NetAgent() {
}


NetAgent::~NetAgent() {
}
//case OPCODE::Create_Account:
//{
//	rqCreateAccount* rq = (rqCreateAccount*)pkg;
//	if (!on_rqCreateAccount(rq->user, rq->psd))
//	{
//		rtCreateAccountFailed_Exist rt;
//		SendPKG(connect->getSocket(), rt);
//	}
//	else
//	{

//	}
//}
//break;
//case OPCODE::Login:
//{
//	if (!mClients.findkey(connect))
//		mClients.Insert(connect, 1);

//	rqLogin* rq = (rqLogin*)pkg;
//	on_rqLogin(rq->user, rq->psd, connect);
//}
//break;
//case OPCODE::ClientToLogin:
//{
//	rtCreateAccountFailed_Exist rt;
//	SendPKG(connect->getSocket(), rt);
//}
//break;
//default:
//{

//}
//break;
//}
void NetAgent::onCallBack(const Delegate& d, uEventArgs* e) {
    if (d == App::Net.onMessage) {
        NetWork::MsgArgs* arg = (NetWork::MsgArgs*)e;
        PKG* pkg = arg->pkg;
        Connection* connect = arg->connect;

        switch (pkg->opcode) {
        case OPCODE::ClientLogin: {
            switch (pkg->childid) {
            case OPCODE::ClientLoginType::RqGameServerInfo: {
                ClientToLogin_RqGameServerInfo* rq = (ClientToLogin_RqGameServerInfo*)pkg;
                NetConfig* netconfig;
                if (App::Config.center.centers.Get(rq->serverID, netconfig)) {
                    Cmd::RTGameServer rt;
                    rt.set_ip(netconfig->ip.c_str());
                    rt.set_port(netconfig->port);
                    SendProtoBuffer(connect->getSocket(), 1, rt);
                }
            }
            break;
            }
        }
        break;
        case OPCODE::CenterLogin: {
            switch (pkg->childid) {
            case OPCODE::CenterLoginType::AppStart: {
            }
            break;
            case OPCODE::CenterLoginType::AppInfo: {
            }
            break;
            }
        }
        break;

        case OPCODE::ID::CenterClient: {
            switch (pkg->childid) {
            case OPCODE::ClientLoginType::RqGameServerInfo: {
                ClientToLogin_RtGameServerInfo cmd;
                //SendPKG(connect->getSocket(), cmd);
            }
            break;
            }
        }
        }
    } else if (d == App::Net.onDisconnect) {
        NetWork::ConnectArg* arg = (NetWork::ConnectArg*)e;
        mClients.erase(arg->connect);
    }
}

bool NetAgent::on_rqCreateAccount(string user, string psd) {
    if (App::DataBase.queryColValue(YW_TABLE_ACCOUNT, YW_TABLE_ACCOUNT_USER, user.c_str())) {
        return false;
    } else {
        //if (App::DataBase.insertRecordByGUID(YW_TABLE_ACCOUNT, user, psd))
        {
            return true;
        }
    }
    return false;
}


bool NetAgent::on_rqLogin(string user, string psw, Connection* con) {
    //the account enter the net gate
    Account* gateAccount = new Account();
    gateAccount->setConnection(con);
    if (!gateAccount->init()) {
        delete gateAccount;
        return nullptr;
    }

    bool res = false;

    gateAccount->getDBInterface()->setField(YW_TABLE_ACCOUNT_USER, user);

    if (!gateAccount->getDBInterface()->fetchByField(YW_TABLE_ACCOUNT_USER)) {
        if (App::Config.login.db.autoCreateAccount) {
            gateAccount->getDBInterface()->setField(YW_TABLE_ACCOUNT_PSD, psw);
            gateAccount->getDBInterface()->setField(YW_TABLE_ACCOUNT_ID, Platform::generateGUIDSimpleString());

            //does not exist,create successfully!
            if (gateAccount->getDBInterface()->createAndInsertToDB()) {
                res = true;
            }
        }
    } else {
        string strpwd ;
        gateAccount->getDBInterface()->getField(YW_TABLE_ACCOUNT_PSD, strpwd);
        if (strpwd == psw) {
            //exist,load successfully!
            res = true;
        }
    }

    return res;
}

const char* NetAgent::YW_DB = "yourworld";

const char* NetAgent::YW_TABLE_ACCOUNT = "yw_account";

const char* NetAgent::YW_TABLE_ACCOUNT_USER = "user";

const char* NetAgent::YW_TABLE_ACCOUNT_PSD = "pwd";

const char* NetAgent::YW_TABLE_ACCOUNT_ID = "guid";

Map<Connection*, int> NetAgent::mClients;

