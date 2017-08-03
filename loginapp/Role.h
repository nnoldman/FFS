#include "BaseObject.h"
#ifndef Role_h__
#define Role_h__
//-------------------------------------------------------------------------
/**
	@brief role of an account
	@11/7/2015
*/
class  Role :
    public BaseObject {
  public:
    Role();
    ~Role();

    void enterScene();

    virtual void createDefine() override;

};

#endif // Role_h__
