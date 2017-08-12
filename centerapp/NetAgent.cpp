#include "stdafx.h"
#include "NetAgent.h"
#include "Command.pb.h"
#include "Cmd.pb.h"
#include "md5.h"

NetAgent::NetAgent()
{
}


NetAgent::~NetAgent()
{
    App::Net.onMessage.remove(&::NetAgent::OnMessage, this);
    App::Net.onDisconnect.remove(&::NetAgent::onDisconnect, this);
}

bool NetAgent::initialize()
{
    App::Net.onMessage.add(&::NetAgent::OnMessage, this);
    App::Net.onDisconnect.add(&::NetAgent::onDisconnect, this);
    return true;
}

void NetAgent::onDisconnect(Connection* connection)
{
    mClients.erase(connection);
}

void NetAgent::OnMessage(ProtocoBuffer* pb, Connection* connect)
{
    switch (pb->opcode)
    {
    case Cmd::CLIENT_COMMAND::RQLoginGame:
        {
            auto req = pb->parse<Cmd::ReqLoginGameServer>();
            stringstream ss;
            ss << req->accountid();
            ss << req->time();
            ss << Default::Token::kLoginKey;
            MD5 md5(ss.str());

            Cmd::RetLoginGameServer ret;

            if (md5.toStr() != req->token())
            {
                ret.set_error(Cmd::LoginGameServerErrorCode::Invalid);
            }
            else if (req->time() + 600 < std::time(nullptr))
            {
                ret.set_error(Cmd::LoginGameServerErrorCode::Overdue);
            }
            else
            {
                ret.set_error(Cmd::LoginGameServerErrorCode::Sucess);
            }
            SendProtoBuffer(connect->getSocket(), Cmd::RTLoginGame, ret);
        }
        break;
    default:
        break;
    }
}

bool NetAgent::on_rqCreateAccount(const string& user, const string& password, Connection* con)
{
    return false;
}


bool NetAgent::on_rqLoginAccount(string user, string psw, Connection* con)
{
    return false;
}

void NetAgent::onLoginSucess(Account* account)
{
}

