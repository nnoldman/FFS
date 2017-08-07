#include "stdafx.h"
#include "DBTableDefine.h"
#include "SQLHelper.h"

bool DBTableDefine::generateCreateTableString(stringstream& cmd)const {
    cmd << "create table ";
    cmd << this->tableName.c_str()<<"(";
    for (auto column : this->columns) {
        cmd << column.name << " ";
        cmd << SQLHelper::getSQLType(column.type)<<" ";
        if (column.length > 0)
            cmd << "(" << column.length << ")";
        if (!column.canNull)
            cmd << " not null";
        if (column.autoIncrement)
            cmd << " auto_increment";
        cmd << ",";
    }
    if (this->primaryKey2.length() > 0)
        cmd << "primary key (" << this->primaryKey1 <<","<< this->primaryKey2 << ")";
    else
        cmd << "primary key (" << this->primaryKey1 << ")";

    cmd << ");";
    return true;
}
