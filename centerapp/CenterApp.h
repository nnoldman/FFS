#pragma once
class NetAgent;
class CenterApp :
    public App
{
public:
    CenterApp(int narg, const char** args);
    ~CenterApp();
    virtual const NetConfig& getNetConfig() override;

    virtual const DBConfig& getDataBaseConfig() override;

    virtual bool parseCommandLine() override;

private:
    int mServerID;
private:
    NetAgent* mNetAgent;
protected:
    virtual void archive() override;


    virtual bool onInitializeEnd() override;


    virtual bool onInitializeNet() override;

    virtual const vector<const DBTableDefine*>& getTableDefines() const override;
};

