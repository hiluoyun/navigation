#include "MyAboutLayer.h"
#include "SimpleAudioEngine.h"
#define EFFECT "effect_key"
using namespace CocosDenshion;

MyAboutLayer::MyAboutLayer(void)
{
}


MyAboutLayer::~MyAboutLayer(void)
{
}
 bool MyAboutLayer::init()
 {
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	int i=0;
	CCARRAY_FOREACH(array, object)  
	{  
		i++;
		CCLayer *layer = (CCLayer*) object;  
		layer->onExit();  
	}  
	 CCSize size=CCDirector::sharedDirector()->getWinSize();
	 //加载 关于 图片
	 CCSprite *sp1 = CCSprite::create("image/helpandabout/aboutphoto.png");
	 sp1->setScale(0.8);
	 sp1->setPosition(ccp(size.width/2,-size.width*0.01));
	 sp1->setAnchorPoint(ccp(.5f,0));
	 sp1->setRotation(-40);
	 this->addChild(sp1);

	 CCRotateBy* move1=CCRotateBy::create(1.5,40);
	 CCEaseElasticOut * in = CCEaseElasticOut::create(move1);
	 sp1->runAction(in);
	 //关闭菜单
	 CCSprite *sp2 = CCSprite::create("image/helpandabout/X.png");
	 CCSprite *sp3 = CCSprite::create("image/helpandabout/X3.png");

	 CCMenuItemSprite *item = CCMenuItemSprite::create(sp2,sp3,this,menu_selector(MyAboutLayer::closeabout));
	 item->setScale(1.2);
     item->setPosition(ccp(sp1->getPositionX()+sp1->getContentSize().width*0.23,sp1->getPositionY()+sp1->getContentSize().height*0.82));

	 CCMenu *menu = CCMenu::create(item,NULL);
	 menu->setPosition(CCPointZero);
	// menu->setAnchorPoint(ccp(0,0));
	 sp1->addChild(menu);
	/* this->addChild(menu);*/

	 return true;
 }
 void MyAboutLayer::closeabout(CCObject* o)
 {
	 if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	 {
		 SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	 }
	

	this->removeFromParent();
	//开启所有被暂停的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	CCARRAY_FOREACH(array, object)  
	{  
		CCLayer* layer = (CCLayer*) object;  
		layer->onEnter();  
	}  
 }