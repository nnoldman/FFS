#include "stdafx.h"
#include "GameApp.h"

int main(int argc, const char** argv)
{
    GameApp* app = new GameApp(argc, argv);
    return App::Main(app);
}
