#include "stdafx.h"
#include "NetAgent.h"
#include "Account.h"
#include "Command.pb.h"
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

Map<Connection*, int> NetAgent::mClients;

