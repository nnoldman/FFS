#pragma once
class LoginNetAgent;
class LoginApp :
    public App {
  public:
    LoginApp(int narg, const char** args);
    ~LoginApp();
    virtual bool initialize();

  private:
    LoginNetAgent* mNetAgent;
};

