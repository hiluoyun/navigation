#include "Mysprite.h"


Mysprite::Mysprite(void)
{
	m_speed=5;
	winsize=CCDirector::sharedDirector()->getWinSize();
}


Mysprite::~Mysprite(void)
{
}

bool Mysprite::init( void )
{
	this->initWithFile("image/person/person.png");
	this->setAnchorPoint(ccp(0,0));
	this->setPosition(ccp(winsize.width*0.20,winsize.height+this->getContentSize().height));
	return true;
}
void Mysprite::myjump(){
	CCPoint p=this->getPosition();
	this->initWithFile("person1.png");
	CCMoveBy* by=CCMoveBy::create(.5f,ccp(0,200));
	CCEaseSineOut* out=CCEaseSineOut::create(by);
	CCSequence* sequence=CCSequence::create(out,out->reverse(),NULL);
	this->runAction(sequence);

}

