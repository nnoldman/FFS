#include "stdafx.h"
#include "App.h"

App::App(int narg, const char** args)
    :mCommandLine(narg, args) {

}

App::~App() {
}

bool App::initialize() {
    if (mCommandLine.arg_count()) {
        if (!parseCommandLine()) {
            CXASSERT_RESULT_FALSE(0);
        }
    }

    if (!Config.initialize("..\\..\\config.xml"))
        return false;

    if (!Net.initialize(getNetConfig())) {
        return false;
    }
    if (!DataBase.initialize(getDataBaseConfig())) {
        return false;
    }
    if (!World.initialize())
        return false;
    return true;
}

void App::run() {
    while (true) {
        Net.prosess();
        Platform::sleep(5);
    }
}

void App::finish() {
    //Script.finish();
}

void App::archive() {

}

Basic::CommandLine& App::getCommandLine()  {
    return mCommandLine;
}

int App::Main(App* app) {
    if (!app->initialize()) {
        delete app;
        return 1;
    }
    app->run();
    app->finish();

    delete app;
    return 0;
}

Config App::Config;

DataBase App::DataBase;

NetWork App::Net;

World App::World;

Gate App::Gate;
