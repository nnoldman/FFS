#ifndef World_h__
#define World_h__
class DBObject;
class Connection;

class COREAPI World {
  public:
    World();
    virtual ~World();

    Delegate1<void, DBObject*> onAccountEnterWorld;
    Delegate1<void, DBObject*> onAccountLeaveWorld;

    bool initialize();

  public:

    void reclaimAccount(DBObject* account);

    void onEnterWorld(DBObject* account);

    void sync(int account_guid, string cmd);

    virtual void onDisconnect(Connection* connection);
  private:
    Map<int, DBObject*> mAccounts;
};

#endif // World_h__
