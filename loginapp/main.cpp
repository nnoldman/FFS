#include "stdafx.h"
#include "App.h"
#include "LoginApp.h"

int main(int argc, const char** argv) {
    LoginApp* app = new LoginApp(argc, argv);
    return App::Main(app);
}