#pragma once
#include "cocos2d.h"
#include "MyPlayLayer.h"
using namespace cocos2d;
class GameOver :public CCLayer
{
public:
	GameOver(void);
	~GameOver(void);
	virtual bool init();
	CREATE_FUNC(GameOver);
private:
	void gameRestart(CCObject* o);
	void gameComeBack(CCObject* o);
	CCMenuItemImage* menu_restart;
	CCMenuItemImage* menu_comeback;
	CCSprite* sprite_rank;
	CCLabelTTF* sprite_grade;
};

