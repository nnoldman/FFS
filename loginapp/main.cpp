#include "stdafx.h"
#include "vld.h"
#include "LoginApp.h"
BOOL WINAPI onControl(DWORD CtrlType)
{
    if (CTRL_CLOSE_EVENT == CtrlType)
    {
        App::Instance->quit();
        while (App::Instance)
            Platform::sleep(5);
    }
    return TRUE;
}

int main(int argc, const char** argv)
{
    //freopen("game.loginapp.txt", "w", stdout);
    freopen("COUT", "w", stdout);
    SetConsoleCtrlHandler(onControl, TRUE);
    LoginApp app(argc, argv);
    auto ret = App::Main(&app);
    return ret;
}

