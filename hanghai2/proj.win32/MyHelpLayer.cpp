#include "MyHelpLayer.h"


MyHelpLayer::MyHelpLayer(void)
{
}


MyHelpLayer::~MyHelpLayer(void)
{
}
bool MyHelpLayer::init()
{
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
	 CCSize size=CCDirector::sharedDirector()->getWinSize();
	 //加载 帮助 图片
	 CCSprite *sp1 = CCSprite::create("image/helpandabout/helpground.png");
	 sp1->setScale(0.8);
	 sp1->setPosition(ccp(size.width/2,0-sp1->getContentSize().height/2));
	 this->addChild(sp1);
	 //关闭菜单
	 CCSprite *sp2 = CCSprite::create("image/helpandabout/X.png");
	 CCSprite *sp3 = CCSprite::create("image/helpandabout/X3.png");

	 CCMoveBy* move1=CCMoveBy::create(1.5f,ccp(0,size.height*0.35+sp1->getContentSize().height/2));
	 CCEaseBounceOut* in=CCEaseBounceOut::create(move1);
	 sp1->runAction(in);

	 CCMenuItemSprite *item = CCMenuItemSprite::create(sp2,sp3,this,menu_selector(MyHelpLayer::closehelp));
	 item->setPosition(ccp(sp1->getPositionX()+sp1->getContentSize().width*0.32,sp1->getPositionY()+sp1->getContentSize().height*0.25));
	 //CCAction* a=CCAction::copy
	 item->runAction((CCActionInterval*)in->copy());

	 CCMenu *menu = CCMenu::create(item,NULL);
	 menu->setPosition(CCPointZero);
	// menu->setAnchorPoint(ccp(0,0));
	 this->addChild(menu);

	 return true;
}
void MyHelpLayer::closehelp(CCObject* o)
{
	//
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