#pragma once
#include "cocos2d.h"
#include "MyBackgroundScnene.h"
using namespace cocos2d;
class Zanting :public CCLayer
{
public:
	Zanting(void);
	~Zanting(void);
	virtual bool init();
	CREATE_FUNC(Zanting);
private:
	void gameback(CCObject* o);
	void gamecontinue(CCObject* o);
	CCMenuItemImage* spriteNo;
	CCMenuItemImage* spriteYes;
	CCSprite* spriteIsexit;
};

