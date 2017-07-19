#ifndef BaseObject_h__
#define BaseObject_h__
class CX_LIB BaseObject {
  public:
    BaseObject();
    virtual ~BaseObject();
    virtual bool init();
    virtual void setGuid(const char* guid);
    string guid();
    void setField(const char* name, string& value);
    void setField(const char* name, const char* value);
    void setField(const char* name, int value);
    void setField(const char* name, u32 value);
    void getField(const char* name, u32& value);
    void getField(const char* name, string& value);
    void getField(const char* name, int& value);
  private:
    string mGUID;
};
#endif // BaseObject_h__

