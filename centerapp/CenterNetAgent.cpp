#include "stdafx.h"
#include "CenterNetAgent.h"
#include "Command.pb.h"
#include "Cmd.pb.h"
#include "md5.h"
#include "GameUser.h"
#include "GameUserDefine.h"
#include "Role.h"

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
    case Cmd::CLIENTID::RQLoginGame:
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
                user->onEnterGate();

                for (int i=0; i<Default::Capacity::Role; ++i)
                {
                    auto role = user->getRole(i);
                    if (role->valid())
                    {
                        auto gamerole = ret.add_roles();
                        auto def = role->getDefine();
                        gamerole->set_id(def->id);
                        gamerole->set_vip(def->vip);
                        gamerole->set_level(def->level);
                        gamerole->set_job(def->job);
                        gamerole->set_sex(def->sex);
                    }
                }

                App::World.onEnterWorld(connect,user);
                ret.set_error(Cmd::LoginGameServerErrorCode::Sucess);
            }
            SendProtoBuffer(connect->getSocket(), Cmd::RTLoginGame, ret);
        }
        break;
    case Cmd::CLIENTID::RQCreateRole:
        {
            auto req = pb->parse<Cmd::ReqCreateRole>();
            auto user = (GameUser*)App::World.get(connect);
            if (user)
            {
                auto role = user->getRole(req->index0());
                if (role)
                {
                    Cmd::RetCreateRole ret;

                    auto def = role->getDefine();
                    def->name = req->name().c_str();
                    if (def->exist(def->key2(), def->name.c_str()))
                    {
                        ret.set_error(Cmd::CreateRoleError::CreateRoleError_NameRepeated);
                        SendProtoBuffer(connect->getSocket(), Cmd::RTCreateRole, ret);
                    }
                    else
                    {
                        def->sex = req->sex();
                        def->job = req->job();
                        if (!def->commit(def->name.c_str()))
                        {
                            assert(false);
                        }
                        else
                        {
                            ret.set_roleid(def->id);
                            ret.set_index0(req->index0());
                            ret.set_name(def->name.c_str());
                            ret.set_sex(def->sex);
                            ret.set_job(def->job);
                            ret.set_vip(def->vip);
                            ret.set_error(Cmd::CreateRoleError::CreateRoleError_Sucess);
                            SendProtoBuffer(connect->getSocket(), Cmd::RTCreateRole, ret);
                        }
                    }
                }
            }
        }
        break;
    case Cmd::CLIENTID::RQEnterGame:
        {
            auto user = (GameUser*)App::World.get(connect);
            auto req = pb->parse<Cmd::ReqEnterGame>();
            user->activeRole(req->index0());
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

