// TestEmbedding.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

#include "stdio.h"
#include "App.h"

int main(int narg, const char** args) {
    App* app = new App(narg, args);

    if (!app->initialize()) {
        delete app;
        return 1;
    }

    app->run();
    app->finish();

    delete app;
    return 0;
}

