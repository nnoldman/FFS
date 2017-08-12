#pragma once
class Account;
class NetAgent
{
public:
    NetAgent();
    ~NetAgent();

    bool initialize();
protected:
    void onDisconnect(Connection* connection);
    void OnMessage(ProtocoBuffer* pb, Connection* connection);
protected:

    bool on_rqCreateAccount(const string& user, const string& password, Connection* con);
    bool on_rqLoginAccount(string user, string psw, Connection* con);
    void onLoginSucess(Account* account);
private:
    Map<Connection*, int> mClients;
};

