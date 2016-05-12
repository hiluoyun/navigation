#include "MyExitLayer.h"


MyExitLayer::MyExitLayer(void)
{
}


MyExitLayer::~MyExitLayer(void)
{
}

bool MyExitLayer::init()
{
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	//暂停所有正在运行的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	int i=0;
	CCARRAY_FOREACH(array, object)  
	{  
		i++;
		CCLayer *layer = (CCLayer*) object;  
		layer->onExit();  
	}  
	CCLOG("size=%d",i);
	spriteIsexit=CCSprite::create("image/exit/isexit.png");
	spriteIsexit->setScale(0.6);
	spriteIsexit->setPosition(ccp(winSize.width/2,winSize.height/2));
	addChild(spriteIsexit);

	spriteNo=CCMenuItemImage::create("image/exit/no.png","image/exit/no.png",this,menu_selector(MyExitLayer::gameno));
	spriteNo->setScale(.45f);
	spriteNo->setPosition(winSize.width/2+42,winSize.height/2-76);

	spriteYes=CCMenuItemImage::create("image/exit/yes.png","image/exit/yes.png",this,menu_selector(MyExitLayer::gameyes));;
	spriteYes->setScale(.45f);
	spriteYes->setPosition(winSize.width/2-30,winSize.height/2-76);

    CCMenu* menu=CCMenu::create(spriteNo,spriteYes,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->setPosition(ccp(0,0));
	this->addChild(menu);
	return true;
}
void MyExitLayer::gameno(CCObject* o){
	this->removeFromParent();
	//开启音乐
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
	
	//开启所有被暂停的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	CCARRAY_FOREACH(array, object)  
	{  
		CCLayer* layer = (CCLayer*) object;  
		layer->onEnter();  
	}  
}
void MyExitLayer::gameyes(CCObject* o){
	CCDirector::sharedDirector()->end();
}