#pragma once
class LoginNetAgent;
class LoginApp :
    public App {
  public:
    LoginApp(int narg, const char** args);
    ~LoginApp();
    virtual const NetConfig& getNetConfig() override;
    virtual const DBConfig& getDataBaseConfig() override;
    virtual bool parseCommandLine() override;
  private:
    LoginNetAgent* mNetAgent;
  protected:

    virtual void archive() override;


    virtual bool onInitializeEnd() override;

    virtual bool onInitializeNet() override;


    virtual const vector<const DBTableDefine*> getTableDefines() override;

};

