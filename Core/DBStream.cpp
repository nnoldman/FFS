#include "stdafx.h"
#include "DBStream.h"


DBStream::DBStream() {
}


DBStream::~DBStream() {
}
DBStream& DBStream::operator<<(float var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream & DBStream::operator<<(double var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream & DBStream::operator >> (u8 & var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream & DBStream::operator >> (u16 & var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (u32& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (u64& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (char& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;

}

DBStream& DBStream::operator >> (s16& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (int& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (s64& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (bool& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (string& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (float& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

DBStream& DBStream::operator >> (double& var) {
    string container = contents_.back();
    StringHelper::setValue(container.c_str(), &var);
    contents_.pop_back();
    return *this;
}

void DBStream::set(vector<string>& values) {
    contents_ = values;
}

DBStream& DBStream::operator<<(string var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(bool var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(s64 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(int var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(s16 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(char var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(u64 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(u32 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream& DBStream::operator<<(u8 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}

DBStream & DBStream::operator<<(u16 var) {
    string container;
    StringHelper::toString(container, &var);
    contents_.insert(contents_.begin(),container);
    return *this;
}
