#ifndef BaseObject_h__
#define BaseObject_h__
class DBDefine;
class CX_LIB BaseObject {
  public:
    BaseObject();
    virtual ~BaseObject();
    virtual bool initialize();
    virtual void setGlobalID(int globalID);
    virtual void createDefine() = 0;
    DBDefine* getDBInterface() const;
    //void setField(const char* key, Value value);
    inline int globalID()const;
  protected:
    DBDefine* mDBInterface;
  private:
    int mGlobalID;
};
inline int BaseObject::globalID() const {
    return mGlobalID;
}
inline DBDefine* BaseObject::getDBInterface() const {
    return mDBInterface;
}
#endif // BaseObject_h__

