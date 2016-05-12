#pragma once
#include "cocos2d.h"
#include "Zanting.h"
using namespace cocos2d;
class MyPlayMenu :public CCLayer
{
public:
	MyPlayMenu(void);
	~MyPlayMenu(void);
	virtual bool init();
	CREATE_FUNC(MyPlayMenu);
private:
	CCSize winsize;
	CCMenuItemSprite* menuitemplay;
	void playmenucallback(CCObject* o);
	/*Zanting* zantinglayer;*/
};

