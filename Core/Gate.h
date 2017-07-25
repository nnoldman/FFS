#pragma once
class Account;
class CX_LIB Gate {
  public:
    Gate();
    ~Gate();
    void onEnter(Account* account);
};

