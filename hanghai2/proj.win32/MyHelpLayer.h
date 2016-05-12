#pragma once
#include "cocos2d.h"
#include "MyMenu.h"

class MyHelpLayer :public CCLayer
{
public:
	MyHelpLayer(void);
	~MyHelpLayer(void);
	virtual bool init();
	CREATE_FUNC(MyHelpLayer);
private:
	void closehelp(CCObject* o);
};

