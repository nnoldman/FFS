#ifndef SQLExecuter_h__
#define SQLExecuter_h__

#include "ConfigInfo.h"
typedef std::vector<std::string> stringVector;

class DBExecuter {
  public:

    virtual bool initialize(const DBConfig& config) = 0;

    virtual void queryBegin(const char* cmd) const = 0;

    virtual bool queryEnd(stringVector& result) = 0;

    virtual bool queryEnd(std::vector<shared_ptr<stringVector>>& result) = 0;

    virtual bool queryEnd() = 0;

    virtual unsigned long count() = 0;

    virtual void use(const char* dataBaseName) const = 0;
};
#endif // SQLExecuter_h__
