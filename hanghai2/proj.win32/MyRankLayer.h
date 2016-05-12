#pragma once
#include "cocos2d.h"
#include "MyMenu.h"
#include "SimpleAudioEngine.h"
#define BG_MUSIC "backmusic.mp3"

using namespace CocosDenshion;

class MyRankLayer :public CCLayer
{
public:
	MyRankLayer(void);
	~MyRankLayer(void);
	virtual bool init();
	CREATE_FUNC(MyRankLayer);
private:
	void rankbacklayer(CCObject* sp);//πÿ±’…Ë÷√≤Àµ•
};

