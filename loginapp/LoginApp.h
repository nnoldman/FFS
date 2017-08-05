#pragma once
class LoginNetAgent;
class LoginApp :
    public App {
  public:
    LoginApp(int narg, const char** args);
    ~LoginApp();
    virtual bool initialize();
    virtual const NetConfig& getNetConfig() override;
    virtual const DBConfig& getDataBaseConfig() override;
    virtual bool parseCommandLine() override;

  private:
    LoginNetAgent* mNetAgent;
};

