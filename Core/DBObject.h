#pragma once
#include "BaseObject.h"
class COREAPI DBObject :
    public BaseObject {
  public:
    DBObject();
    ~DBObject();

    bool fetchByField(const char* field);

    void sync(string data);

    bool fetch();

    bool saveToDB();

    bool createAndInsertToDB();

    void requireGUID();

};

