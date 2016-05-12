#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BaseLayer: public CCLayer
{
public:
	CCSize winsize;
	BaseLayer(void);
	~BaseLayer(void);
};

