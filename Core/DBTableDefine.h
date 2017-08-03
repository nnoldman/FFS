#pragma once
#include "mysql.h"
//ID   INT              NOT NULL,
//SALARY   DECIMAL(18, 2) DEFAULT 5000.00,
//PRIMARY KEY(ID)
struct DBCloumn {
    const char* name;
    enum_field_types type;
    bool primaryKey;
    bool canNull;
    Value defaultValue;
};

struct DBTableDefine {
    string primaryKey1;
    string primaryKey2;
    DBCloumn* columns = nullptr;
    ~DBTableDefine() {
        dSafeDelete(columns);
    }
};

