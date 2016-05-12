#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class Mysprite :public CCSprite
{
public:
	Mysprite(void);
	~Mysprite(void);

	virtual bool init( void );
	CREATE_FUNC(Mysprite);

	void myjump();
	void myrotate();

	virtual void update( float delta );

	float m_speed;
	CCSequence* se;

};

