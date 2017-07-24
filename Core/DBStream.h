#pragma once
#include <list>
class DBStream {
  public:
    DBStream();
    ~DBStream();
    DBStream& operator << (u8 var);
    DBStream& operator << (u16 var);
    DBStream& operator << (u32 var);
    DBStream& operator << (u64 var);
    DBStream& operator << (char var);
    DBStream& operator << (s16 var);
    DBStream& operator << (int var);
    DBStream& operator << (s64 var);
    DBStream& operator << (bool var);
    DBStream& operator << (string var);
    DBStream& operator << (float var);
    DBStream& operator << (double var);

    DBStream& operator >> (u8& var);
    DBStream& operator >> (u16& var);
    DBStream& operator >> (u32& var);
    DBStream& operator >> (u64& var);
    DBStream& operator >> (char& var);
    DBStream& operator >> (s16& var);
    DBStream& operator >> (int& var);
    DBStream& operator >> (s64& var);
    DBStream& operator >> (bool& var);
    DBStream& operator >> (string& var);
    DBStream& operator >> (float& var);
    DBStream& operator >> (double& var);

    template<int N>
    inline DBStream& operator << (CharBuffer<N>& var);
    template<int N>
    inline DBStream& operator >> (CharBuffer<N>& var);
    void set(vector<string>& values);
  private:
    std::vector<string> contents_;
};

template<int N>
inline DBStream& DBStream::operator >> (CharBuffer<N>& var) {
    string container = contents_.back();
    var.setString(container.c_str());
    contents_.pop_back();
    return *this;
}

template<int N>
inline DBStream& DBStream::operator<<(CharBuffer<N>& var) {
    string container = var.getString();
    contents_.push_back(container);
    return *this;
}
