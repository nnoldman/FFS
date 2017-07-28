#pragma once
class DBObject;
class CX_LIB Gate {
  public:
    Gate();
    ~Gate();
    void onEnter(DBObject* account);
};

