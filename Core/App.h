#pragma once
#include "Config.h"
#include "NetWork.h"
#include "DataBase.h"
#include "World.h"
#include "Gate.h"

class COREAPI App {
  public:
    enum APP_TYPE {
        APP_TYPE_LOGIN,
        APP_TYPE_CENTER,
        APP_TYPE_BASE,
    };
  public:
	static Config Config;
    static DataBase DataBase;
    static NetWork	Net;
    static World World;
    static Gate Gate;
  public:
    App(int narg, const char** args);
    virtual ~App();

    virtual bool initialize();

    void run();

    void finish();

    void archive();

  protected:

    bool InitNet();

    bool InitDataBase();

    bool InitScript();

  private:
    APP_TYPE mType;
    int mServerID;
    CommandLine mCommandLine;
  public:
    static int Main(App* app);
};
