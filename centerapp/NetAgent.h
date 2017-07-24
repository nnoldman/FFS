#pragma once
class Account;
class NetAgent: public CallbackObject {
  public:
    NetAgent();
    ~NetAgent();

    virtual void onCallBack(const Delegate& d, uEventArgs* e) override;

  protected:
    bool on_rqCreateAccount(string user, string psd, Connection* con);
    bool on_rqLogin(string user, string psw, Connection* con);
    void onLoginSucess(Account* account);
  private:
    static const char* YW_DB;
    static const char* YW_TABLE_ACCOUNT;
    static const char* YW_TABLE_ACCOUNT_USER;
    static const char* YW_TABLE_ACCOUNT_PSD;
    static const char* YW_TABLE_ACCOUNT_ID;
  private:
    static Map<Connection*, int> mClients;
};

