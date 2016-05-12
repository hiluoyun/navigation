#pragma once
#include "cocos2d.h"

class MyCloseLayer :public CCLayer
{
public:
	MyCloseLayer(void);
	~MyCloseLayer(void);
	CREATE_FUNC(MyCloseLayer);
private:
	void pause();
	void reclose();
};

