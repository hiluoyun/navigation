#pragma once
#include "cocos2d.h"
#include "MyMenu.h"
#include "SimpleAudioEngine.h"
#define BG_MUSIC "backmusic.mp3"

using namespace CocosDenshion;

class MySetLayer :public CCLayer
{
public:
	MySetLayer(void);
	~MySetLayer(void);
	virtual bool init();
	CREATE_FUNC(MySetLayer);
private:
	void closesetlayer(CCObject* sp1);//关闭设置菜单

	void backclosemusiclayer(CCObject *sp2);//关闭音乐
	void backopenmusiclayer(CCObject *sp3);//开启音乐

	void easybacklayer(CCObject *sp3);//设置简单模式  默认
	void commonbacklayer(CCObject *sp4);//设置一般模式
	void hardbacklayer(CCObject *sp5);//设置困难模式

	void menucallback(CCObject *sp6);//
};

