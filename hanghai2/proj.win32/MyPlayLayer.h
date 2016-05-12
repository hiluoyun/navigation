#pragma once
#include "cocos2d.h"
#include "MyPlayMenu.h"
#include "Mysprite.h"
#include "GameOver.h"
#include "algorithm"
#include "vector"

using namespace cocos2d;
class MyPlayLayer :public CCLayer
{
public:
	MyPlayLayer(void);
	~MyPlayLayer(void);
	virtual bool init();
	CREATE_FUNC(MyPlayLayer);

	virtual void ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent );

	virtual void keyBackClicked( void );

	virtual void keyMenuClicked( void );

	virtual void update(float dt);

	void loadNextMap();

	void loadBackground();

	void addCollisions();

	void moveCollisions();

	void contactBegein();

	void spriteLife();

	void setScore();

	void savaScore();
	
	void changeHard();
	float y;
	CCSize winsize;
	Mysprite* sprite;//ÓÎÏ·Ö÷½Ç
	CCSprite* cur_bg;
	CCSprite* next_bg;
	CCSprite* collision_1;
	CCSprite* collision_2;
	CCSprite* collision_3;
	CCSprite* collision_4;
	CCSprite* collision_5;
	CCArray* collisionsArrayContatct;
	CCArray* collisions;
	CCProgressTimer* timer;
	CCSprite* bg;
	float progressFrom;
	float progressTo;
	bool flag;
	CCLabelBMFont* label;
	int score;
	int repeat;
	std::vector<int> vec;
	int speed_score;
};

