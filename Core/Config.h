#pragma once
#include "ConfigInfo.h"
class COREAPI Config {
  public:
    Config();

    ~Config();
  public:
    LoginConfig login;
    CenterConfig center;
  public:

    bool initialize(const char* file);
};

