#include "stdafx.h"
#include "App.h"

App::App(int narg, const char** args)
    :mCommandLine(narg, args)
    ,mQuiting(false) {

}

App::~App() {
}

bool App::initialize() {
    if (mCommandLine.arg_count()) {
        if (!parseCommandLine()) {
            throw new std::logic_error("parseCommandLine Error");
            return false;
        }
    }

    if (!Config.initialize("..\\..\\config.xml"))
        return false;

    if (!Net.initialize(getNetConfig())) {
        return false;
    }

    if (!onInitializeNet())
        return false;

    if (!initializeDataBase())
        return false;

    if (!World.initialize())
        return false;

    return this->onInitializeEnd();
}

void App::run() {
    while (!mQuiting) {
        Net.prosess();
        Platform::sleep(5);
    }
}

bool App::initializeDataBase() {
    if (!DataBase.initialize(getDataBaseConfig())) {
        return false;
    } else {
        auto ret = this->getTableDefines();
        for (auto def : ret) {
            if (!this->DataBase.hasTable(def->tableName.c_str())) {
                stringstream cmd(1024);
                cmd << "create table ";
                cmd << def->tableName.c_str();
                for (auto column : def->columns) {
                    cmd << column.name<<" ";
                    cmd << "type";
                    if (column.length > 0)
                        cmd << "(" << column.length << ")";
                    if (!column.canNull)
                        cmd << "not null";
                    if (column.autoIncrement)
                        cmd << "auto_increment";
                    cmd << ",";
                }
                cmd << "primary key (" << def->primaryKey1 << ")";
                if(def->primaryKey2.length()>0)
                    cmd << "primary key (" << def->primaryKey2 << ")";

                if (!this->DataBase.createTable(def->tableName.c_str(), cmd.str().c_str())) {
                    return false;
                }
            }
        }
    }
    return true;
}

void App::onQuit() {
    archive();
}

void App::archive() {

}

void App::quit() {
    mQuiting = true;
}

bool App::isQuiting() const {
    return mQuiting;
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
    app->onQuit();

    delete app;
    return 0;
}

Config App::Config;

DataBase App::DataBase;

NetWork App::Net;

World App::World;

Gate App::Gate;
