#ifndef DBExecuter_h__
#define DBExecuter_h__

#include "DBExecuter.h"
#include "mysql.h"

class MySQLExecuter:public DBExecuter {
  public:

    MySQLExecuter();

    ~MySQLExecuter();

    bool initialize(const DBConfig& config);

    void queryBegin(const char* cmd);

    /*
    	Only return first record or nothing.
    */
    bool queryEnd(stringVector& result);

    /*
    	return all eligible records.
    */
    bool queryEnd(std::vector<shared_ptr<stringVector>>& result);

    bool queryEnd();

    virtual unsigned long count() override;

  private:

    DBConfig mConfig;

    MYSQL* mConnection;
};




#endif // DBExecuter_h__
