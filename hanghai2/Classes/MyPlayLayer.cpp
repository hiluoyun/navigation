#include "MyPlayLayer.h"


MyPlayLayer::MyPlayLayer(void)
{
}


MyPlayLayer::~MyPlayLayer(void)
{
	unscheduleAllSelectors();
}

bool MyPlayLayer::init()
{
	scheduleUpdate();
	this->setTouchEnabled(true);
	winsize=CCDirector::sharedDirector()->getWinSize();
	/*CCSprite* bg=CCSprite::create("image/play/play_backgroud.jpg");
	bg->setAnchorPoint(CCPointZero);
	this->addChild(bg);*/

	mymap1=CCTMXTiledMap::create("image/playbackground/background_6.tmx");
	this->addChild(mymap1);


	mymap2=CCTMXTiledMap::create("image/playbackground/background_6.tmx");
	this->addChild(mymap2);
	mymap2->setPosition(ccp(mymap1->getContentSize().width,0));

	CCTMXObjectGroup* ob=mymap1->objectGroupNamed("road");

	CCDictionary* dic=ob->objectNamed("qidian");
	float x=dic->valueForKey("x")->floatValue();
	y=dic->valueForKey("y")->floatValue();
	int i=dic->count();
	CCLOG("y=%f,i=%d",y,i);

	spr=Mysprite::create();
	spr->initWithFile("image/person/person.png");
	spr->setAnchorPoint(CCPointZero);
	spr->setPositionY(y);
	this->addChild(spr);
	return true;
}

void MyPlayLayer::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
	//CCPoint* point=(CCPoint*)pTouches->anyObject();
	if (spr->getPositionY()==y)
	{
		spr->myjump();
	}
	
	
}

void MyPlayLayer::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
	//spr->myrotate();
}

void MyPlayLayer::keyBackClicked( void )
{
	Zanting* zantinglayer=NULL;
	zantinglayer=Zanting::create();
	this->getParent()->addChild(zantinglayer);
}

void MyPlayLayer::keyMenuClicked( void )
{
	Zanting* zantinglayer=NULL;
	zantinglayer=Zanting::create();
	this->getParent()->addChild(zantinglayer);
}

void MyPlayLayer::update(float dt)
{
	
	mymap1->setPositionX(mymap1->getPositionX()-spr->m_speed);
	mymap2->setPositionX(mymap2->getPositionX()-spr->m_speed);

	if (mymap1->getPositionX()+mymap1->getContentSize().width<=0)
	{
	mymap1->setPositionX(mymap2->getPositionX()+mymap2->getContentSize().width);
	}
	if (mymap2->getPositionX()+mymap2->getContentSize().width<=0)
	{
	mymap2->setPositionX(mymap1->getPositionX()+mymap1->getContentSize().width);
	}

	
	
		
	
}
