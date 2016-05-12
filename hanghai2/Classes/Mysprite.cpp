#include "Mysprite.h"


Mysprite::Mysprite(void)
{
	m_speed=5;
}


Mysprite::~Mysprite(void)
{
}

bool Mysprite::init( void )
{
	CCSize winsize=CCDirector::sharedDirector()->getWinSize();
	//this->scheduleUpdate();
	this->setPositionX(winsize.width*0.20);
	return true;
}
void Mysprite::myjump(){
	CCPoint p=this->getPosition();
	//CCJumpBy* ju=CCJumpBy::create(1,ccp(p.x+30,p.y),0,1);
	ccBezierConfig  beziercofig;  
	beziercofig.controlPoint_1 = p;  
	beziercofig.controlPoint_2 = ccp(p.x,p.y+250);  
	beziercofig.endPosition = ccp(p.x,p.y);  

	CCActionInterval *forward = CCBezierTo::create(1, beziercofig);
	CCEaseSineInOut *out= CCEaseSineInOut::create(forward);
	se=CCSequence::create(forward,NULL);

	this->runAction(out);

}
void Mysprite::myrotate(){
	CCRotateBy* rotate=CCRotateBy::create(1,360);
	this->runAction(rotate);
};

void Mysprite::update( float delta )
{
	CCPoint cur_p=this->getPosition();
	this->setPosition(ccp(cur_p.x+m_speed,cur_p.y));
}
