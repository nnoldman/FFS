#include "stdafx.h"
#include "CenterApp.h"

int main(int argc, const char** argv) {
    CenterApp* app = new CenterApp(argc, argv);
    return App::Main(app);
}
