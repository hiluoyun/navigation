#include "MyActiveLayer.h"


MyActiveLayer::MyActiveLayer(void)
{
}


MyActiveLayer::~MyActiveLayer(void)
{
}
bool MyActiveLayer::init()
{
	winsize=CCDirector::sharedDirector()->getWinSize();
	sp1 = CCSprite::create("image/jieke/jie01.png");
	sp2 = CCSprite::create("image/jieke/hb.png");//»¬°åÍ¼Æ¬
		
	sp1->setPosition(ccp(winsize.width*0.3,winsize.height+sp1->getContentSize().height/2));
	sp2->setPosition(ccp(winsize.width*0.45,winsize.height+sp1->getContentSize().height/2));

	sp1->setScale(0.8);
	sp2->setScale(0.5);
	this->addChild(sp1,1);
	this->addChild(sp2,0);
	//this->addChild(sp3);


	scheduleOnce(schedule_selector(MyActiveLayer::scheduleback1),1);
	scheduleOnce(schedule_selector(MyActiveLayer::scheduleback2),1.8);//»¬°åÑÓ³Ù1.8ÃëÏÂÂä

	//scheduleOnce(schedule_selector(MyBackground::scheduleback3),2.4);
	scheduleOnce(schedule_selector(MyActiveLayer::scheduleback4),2.5);

	return true;
}
void MyActiveLayer::scheduleback1(float a1)
{
	CCMoveBy *move1 = CCMoveBy::create(0.8f,ccp(0,-winsize.height*0.7-sp1->getContentSize().height/2));
	sp1->runAction(CCEaseElasticOut::create(move1));
}
void MyActiveLayer::scheduleback2(float a2)
{
	CCMoveBy *move2 = CCMoveBy::create(0.5f,ccp(0,-winsize.height*0.75-sp2->getContentSize().height/2));
	sp2->runAction(CCEaseElasticOut::create(move2));
}
void MyActiveLayer::scheduleback3(float a3)
{
	//sp1->removeAllComponents();
}
void MyActiveLayer::scheduleback4(float a4)
{
	anni = CCAnimation::create();
	char str[25]={0};
	for(int i=1;i<=8;i++)
	{
		sprintf(str,"image/jieke/jie%02d.png",i);
		anni->addSpriteFrameWithFileName(str);
	}
	anni->setDelayPerUnit(2.0f/6);
	anni->setRestoreOriginalFrame(true);
	CCMoveBy *move3 =CCMoveBy::create(1,ccp(0-sp1->getContentSize().width/2,0));
	CCMoveBy *move4 =CCMoveBy::create(1.5,ccp(winsize.width,0));
	CCMoveBy *move5 =CCMoveBy::create(1.5,ccp(sp1->getContentSize().width/2-winsize.width,0));
	CCSequence *seque = CCSequence::create(move3,move4,move5,NULL);
	sp1->runAction(CCRepeatForever::create(seque));
	sp1->runAction(CCRepeatForever::create(CCAnimate::create(anni)));
}