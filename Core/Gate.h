#pragma once
class Account;
class Gate {
  public:
    Gate();
    ~Gate();
    void onEnter(Account* account);
};

