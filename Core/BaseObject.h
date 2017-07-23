#ifndef BaseObject_h__
#define BaseObject_h__
class DBDefine;
class CX_LIB BaseObject {
  public:
    BaseObject();
    virtual ~BaseObject();
    virtual bool initialize();
    virtual void setGuid(const char* guid);
    const char* guid() const;
    virtual void createDefine() = 0;
    DBDefine* getDBInterface() const;
    void setField(const char* key, Value value);
  protected:
    DBDefine* mDBInterface;
  private:
    string mGUID;
};
#endif // BaseObject_h__

