#include "stdafx.h"
#include "CenterNetAgent.h"
#include "Command.pb.h"
#include "Cmd.pb.h"
#include "md5.h"
#include "GameUser.h"
#include "GameUserDefine.h"

CenterNetAgent::CenterNetAgent()
{
}


CenterNetAgent::~CenterNetAgent()
{
    App::Net.onMessage.remove(&::CenterNetAgent::OnMessage, this);
    App::Net.onDisconnect.remove(&::CenterNetAgent::onDisconnect, this);
}

bool CenterNetAgent::initialize()
{
    App::Net.onMessage.add(&::CenterNetAgent::OnMessage, this);
    App::Net.onDisconnect.add(&::CenterNetAgent::onDisconnect, this);
    return true;
}

void CenterNetAgent::onDisconnect(Connection* connection)
{
    mClients.erase(connection);
}

void CenterNetAgent::OnMessage(ProtocoBuffer* pb, Connection* connect)
{
    switch (pb->opcode)
    {
    case Cmd::CLIENT_COMMAND::RQLoginGame:
    {
        auto req = pb->parse<Cmd::ReqLoginGameServer>();

        Cmd::RetLoginGameServer ret;

        if (Encrypt::makeLoginToken(req->accountid(), req->time()) != req->token())
        {
            ret.set_error(Cmd::LoginGameServerErrorCode::Invalid);
        }
        else if (req->time() + 600<Basic::Time_::utc())
        {
            ret.set_error(Cmd::LoginGameServerErrorCode::Overdue);
        }
        else
        {
            auto user = new GameUser();
            user->setGlobalID(req->accountid());
            auto def = (GameUserDefine*)user->getDBInterface();
            if (def->pull(def->id))
            {
                for (int i = 0; i < Default::Capacity::Role; ++i)
                {
                    int roleID = (&def->role1)[i];
                    if (roleID > 0)
                    {
                        auto_ptr<GameRole> role(new GameRole());
                        GameRoleDefine::query();
                    }
                }
            }
            App::World.onEnterWorld(user);
            ret.set_error(Cmd::LoginGameServerErrorCode::Sucess);
        }
        SendProtoBuffer(connect->getSocket(), Cmd::RTLoginGame, ret);
    }
    break;
    default:
        break;
    }
}

bool CenterNetAgent::on_rqCreateAccount(const string& user, const string& password, Connection* con)
{
    return false;
}


bool CenterNetAgent::on_rqLoginAccount(string user, string psw, Connection* con)
{
    return false;
}

void CenterNetAgent::onLoginSucess(Account* account)
{
}

