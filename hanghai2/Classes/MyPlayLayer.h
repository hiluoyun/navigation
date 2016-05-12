#pragma once
#include "cocos2d.h"
#include "MyPlayMenu.h"
#include "Mysprite.h"

using namespace cocos2d;
class MyPlayLayer :public CCLayer
{
public:
	MyPlayLayer(void);
	~MyPlayLayer(void);
	virtual bool init();
	CREATE_FUNC(MyPlayLayer);

	virtual void ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent );

	virtual void ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent );

	virtual void keyBackClicked( void );

	virtual void keyMenuClicked( void );

	virtual void update(float dt);
	float y;
	CCSize winsize;
	Mysprite* spr;
	CCTMXTiledMap* mymap1;
	CCTMXTiledMap* mymap2;
};

