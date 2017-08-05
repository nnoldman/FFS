#pragma once
class NetAgent;
class CenterApp :
    public App {
  public:
    CenterApp(int narg, const char** args);
    ~CenterApp();
    virtual bool initialize();

    virtual const NetConfig& getNetConfig() override;

    virtual const DBConfig& getDataBaseConfig() override;

    virtual bool parseCommandLine() override;

  private:
    int mServerID;
  private:
    NetAgent* mNetAgent;
};

