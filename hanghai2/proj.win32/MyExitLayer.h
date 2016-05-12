#pragma once
#include "cocos2d.h"
#include "MyMenu.h"
using namespace cocos2d;
class MyExitLayer :public CCLayer
{
public:
	MyExitLayer(void);
	~MyExitLayer(void);

	virtual bool init();
	CREATE_FUNC(MyExitLayer);
private:
	void gameno(CCObject* o);
	void gameyes(CCObject* o);
	CCMenuItemImage* spriteNo;
	CCMenuItemImage* spriteYes;
	CCSprite* spriteIsexit;
};

