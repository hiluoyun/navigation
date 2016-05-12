#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class MyActiveLayer :public CCLayer
{
public:
	MyActiveLayer(void);
	~MyActiveLayer(void);
	virtual bool init();
	CCSize winsize;
	CREATE_FUNC(MyActiveLayer);
private:

	void scheduleback1(float a1);
	void scheduleback2(float a2);
	void scheduleback3(float a3);
	void scheduleback4(float a4);
	CCSprite *sp2;
	CCSprite *sp1;
	CCSprite *sp3;
	CCAnimation *anni;
};

