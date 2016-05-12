#pragma once
#include "cocos2d.h"
#include "MyExitLayer.h"
#include "MyPlayScene.h"
#include "MyAboutLayer.h"
#include "MyHelpLayer.h"
#include "MySetLayer.h"
#include "MyRankLayer.h"
#include "SimpleAudioEngine.h"
#define BG_MUSIC "backmusic.mp3"
#define BUTTON "button.wav"

using namespace CocosDenshion;

using namespace cocos2d;
class MyMenu :public CCLayer
{
public:
	MyMenu(void);
	~MyMenu(void);
	virtual bool init();
	CREATE_FUNC(MyMenu);

private:
	CCSize winsize;
	CCMenuItemSprite* exitIt;
	CCMenuItemSprite* gradeIt;
	CCMenuItemSprite* aboutIt;
	CCMenuItemSprite* helpIt;
	CCMenuItemSprite* playIt;
	CCMenuItemSprite* settingIt;
	/*MyExitLayer *exitlayer;*/
	void menucallback(CCObject* pSender);
};

