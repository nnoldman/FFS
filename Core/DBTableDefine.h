#pragma once
#include "mysql.h"
//ID   INT              NOT NULL,
//SALARY   DECIMAL(18, 2) DEFAULT 5000.00,
//PRIMARY KEY(ID)
struct DBCloumn {
    const char* name = nullptr;
    enum_field_types type = enum_field_types::MYSQL_TYPE_DECIMAL;
    u16 length = 0;
    bool autoIncrement = false;
    bool canNull = false;
    Value defaultValue;
};

struct DBTableDefine {
    string tableName;
    string primaryKey1;
    string primaryKey2;
    vector<DBCloumn> columns;

    DBTableDefine(const DBTableDefine& def) {
        this->tableName = def.tableName;
        this->primaryKey1 = def.primaryKey1;
        this->primaryKey2 = def.primaryKey2;
        this->columns = def.columns;
    }

    DBTableDefine(const char* name,const char* key1, const char* key2, const initializer_list<DBCloumn>& array) {
        tableName = name;
        primaryKey1 = key1;
        if (key2 != nullptr)
            primaryKey2 = key2;
        for (auto iter : array) {
            columns.push_back(iter);
        }
    }
    ~DBTableDefine() {
    }
};

