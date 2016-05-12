#pragma once
#include "cocos2d.h"
#include "MyPlayLayer.h"
#include "Mysprite.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
class MyPlayScene :public CCScene
{
public:
	MyPlayScene(void);
	~MyPlayScene(void);
	virtual bool init();	
	CREATE_FUNC(MyPlayScene);
private:
	Mysprite* sp;//当前的大白先生
	//MyPlayMenu* playmenulayer;//游戏中的按钮
	/*MyPlayLayer* playbglayer;*///游戏中的背景

};

