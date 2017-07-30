#include "stdafx.h"
#include "NetAgent.h"
#include "Account.h"
#include "Command.pb.h"
#include "Cmd.pb.h"
#include "GlobalAccountDefine.h"
NetAgent::NetAgent() {
}
NetAgent::~NetAgent() {
}
void NetAgent::onCallBack(const Delegate& d, uEventArgs* e) {
    if (d == App::Net.onMessage) {
        NetWork::MsgArgs* arg = (NetWork::MsgArgs*)e;
        ProtocoBuffer* pkg = arg->pkg;
        Connection* connect = arg->connect;

        switch (pkg->opcode) {
        case Cmd::CLIENT_COMMAND::RQAccountOperation: {
            auto req = pkg->parse<Cmd::ReqAccountOperation>();

            if (req->action() == Cmd::AccountAction::AccountAction_Create) {
                on_rqCreateAccount(req->user(), req->password(), connect);
            } else if (req->action() == Cmd::AccountAction::AccountAction_Rename) {
                on_rqRenameAccount(req->user(), req->password(), connect);
            } else if (req->action() == Cmd::AccountAction::AccountAction_Delete) {
                on_rqDeleteAccount(req->user(), req->password(), connect);
            } else if (req->action() == Cmd::AccountAction::AccountAction_Login) {
                on_rqLoginAccount(req->user(), req->password(), connect);
            }
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

bool NetAgent::on_rqLoginAccount(const string& user, const string& password, Connection* con) {
    Account* gateAccount = new Account();
    gateAccount->initialize();
    auto def = (GlobalAccountDefine*)gateAccount->getDBInterface();
    if (def->pull(def->user.getString())) {
        if (def->password != password.c_str()) {
            Cmd::RetAccountOperation ret;
            ret.set_error(Cmd::AccountErrorCode::AccountErrorCode_PasswordError);
            SendProtoBuffer(con->getSocket(), Cmd::SERVER_COMMAND::RTAccountOperation, ret);
            dSafeDelete(gateAccount);
            return false;
        } else {
            gateAccount->setGlobalID(def->accountid);
            Cmd::RetAccountOperation ret;
            ret.set_error(Cmd::AccountErrorCode::AccountErrorCode_LoginSucessed);
            ret.set_accountid(def->accountid);
            SendProtoBuffer(con->getSocket(), Cmd::SERVER_COMMAND::RTAccountOperation, ret);
            //App::Gate.onEnter(gateAccount);
            dSafeDelete(gateAccount);
        }
    } else {
        Cmd::RetAccountOperation ret;
        ret.set_error(Cmd::AccountErrorCode::AccountErrorCode_UserCantFind);
        SendProtoBuffer(con->getSocket(), Cmd::SERVER_COMMAND::RTAccountOperation, ret);
        dSafeDelete(gateAccount);
        return false;
    }
    return true;
}

bool NetAgent::on_rqCreateAccount(const string& user, const string& password, Connection* con) {
    Account* gateAccount = new Account();
    auto def = (GlobalAccountDefine*)gateAccount->getDBInterface();
    if (def->pull(user.c_str())) {
        Cmd::RetAccountOperation ret;
        ret.set_error(Cmd::AccountErrorCode::AccountErrorCode_NameRepeated);
        SendProtoBuffer(con->getSocket(), Cmd::SERVER_COMMAND::RTAccountOperation, ret);
        dSafeDelete(gateAccount);
        return false;
    } else {
        def->user = user.c_str();
        def->password = password.c_str();
        auto queryRet = def->insertAndQuery(user.c_str());
        assert(queryRet);
        gateAccount->setGlobalID(def->accountid);

        Cmd::RetAccountOperation ret;
        ret.set_error(Cmd::AccountErrorCode::AccountErrorCode_CreateSucessed);
        ret.set_accountid(def->accountid);
        SendProtoBuffer(con->getSocket(), Cmd::SERVER_COMMAND::RTAccountOperation, ret);

        dSafeDelete(gateAccount);
        //App::Gate.onEnter(gateAccount);

        return true;
    }
}
bool NetAgent::on_rqDeleteAccount(const string & user, const string & password, Connection * con) {
    return false;
}

bool NetAgent::on_rqRenameAccount(const string & user, const string & password, Connection * con) {
    return false;
}

bool NetAgent::createAccount(string user, string psd, Connection * con) {
    return false;
}

Map<Connection*, int> NetAgent::mClients;

