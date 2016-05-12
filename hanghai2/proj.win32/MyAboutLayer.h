#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class MyAboutLayer :public CCLayer
{
public:
	MyAboutLayer(void);
	~MyAboutLayer(void);
	virtual bool init();
	CREATE_FUNC(MyAboutLayer);
private:
	void closeabout(CCObject* o);
};

