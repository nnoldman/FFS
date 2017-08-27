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
    App::Net.onMessage.remove(&::CenterNetAgent::onMessage, this);
    App::Net.onDisconnect.remove(&::CenterNetAgent::onDisconnect, this);
}

bool CenterNetAgent::initialize()
{
    App::Net.onMessage.add(&::CenterNetAgent::onMessage, this);
    App::Net.onDisconnect.add(&::CenterNetAgent::onDisconnect, this);
    return true;
}

void CenterNetAgent::onDisconnect(Connection* connection)
{
    App::World.reclaimAccount(connection);
}

void CenterNetAgent::onMessage(ProtocoBuffer* pb, Connection* connect)
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
            user->initialize();
            user->setGlobalID(req->accountid());
            user->onEnterGate();

            auto role = user->getRole();
            auto gameRole = ret.mutable_role();
            auto def = role->getDefine();
            gameRole->set_id(def->id);
            if (role->valid())
            {
                gameRole->set_vip(def->vip);
                gameRole->set_level(def->level);
                gameRole->set_job(def->job);
                gameRole->set_sex(def->sex);
                gameRole->set_name(def->name.c_str());
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
            auto role = user->getRole();
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
        user->activeRole();
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

