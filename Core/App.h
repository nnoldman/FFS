#pragma once
#include "Config.h"
#include "NetWork.h"
#include "DataBase.h"
#include "World.h"
#include "Gate.h"

class COREAPI App {
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
    virtual	const NetConfig& getNetConfig() = 0;
    virtual	const DBConfig& getDataBaseConfig() = 0;
    virtual	bool parseCommandLine() = 0;

    void run();

    void finish();

    void archive();

  public:
    CommandLine& getCommandLine();
  private:
    CommandLine mCommandLine;
  public:
    static int Main(App* app);
};
