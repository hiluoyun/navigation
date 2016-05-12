#pragma once
#include "cocos2d.h"
#include "MyMenu.h"
#define EFFECT "effect_key"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

class MySetLayer :public CCLayer
{
public:
	MySetLayer(void);
	~MySetLayer(void);
	virtual bool init();
	CREATE_FUNC(MySetLayer);
	CCMenuItemToggle *item2;

private:
	void closesetlayer(CCObject* sp1);

	void backclosemusiclayer(CCObject *sp2);
	void backopenmusiclayer(CCObject *sp3);

	void easybacklayer(CCObject *sp3);
	void commonbacklayer(CCObject *sp4);
	void hardbacklayer(CCObject *sp5);

	void menucallback1(CCObject *sp6);

	void menucallback2(CCObject *sp7);
};

