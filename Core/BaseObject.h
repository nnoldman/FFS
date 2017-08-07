#include "Connection.h"
#ifndef BaseObject_h__
#define BaseObject_h__
class DBDefine;
class COREAPI BaseObject {
  public:
    BaseObject();
    virtual ~BaseObject();
    virtual bool initialize();
    virtual void setGlobalID(int globalID);
    virtual void createDefine() = 0;
    DBDefine* getDBInterface() const;
    inline void setConnection(Connection* connect);
    void sendDBToClient(string data);
    //void setField(const char* key, Value value);
    inline int globalID()const;
    inline Connection* getNetInterface();
  protected:
    DBDefine* mDBInterface;
    Connection* mNetInterface;
  private:
    int mGlobalID;
};
inline int BaseObject::globalID() const {
    return mGlobalID;
}
inline DBDefine* BaseObject::getDBInterface() const {
    return mDBInterface;
}
inline void BaseObject::setConnection(Connection* connect) {
    mNetInterface = connect;
}

inline Connection* BaseObject::getNetInterface() {
    return mNetInterface;
}

#endif // BaseObject_h__

