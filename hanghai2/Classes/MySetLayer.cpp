#include "MySetLayer.h"


MySetLayer::MySetLayer(void)
{
}


MySetLayer::~MySetLayer(void)
{
}
bool MySetLayer::init()
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

	CCSize size = CCDirector::sharedDirector()->getWinSize(); 
	//获取屏幕大小
	CCSprite *sp1 = CCSprite::create("image/setting/setground.png");
	sp1->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(sp1);
	//close
	CCSprite *sp2 = CCSprite::create("image/setting/X.png");
	CCSprite *sp3 = CCSprite::create("image/setting/X3.png");
	//music
	CCSprite *sp4 = CCSprite::create("image/setting/soundopen.png");
	CCSprite *sp5 = CCSprite::create("image/setting/soundend.png");
	CCMenuItemSprite *ms1 = CCMenuItemSprite::create(sp4,sp4,this,menu_selector(MySetLayer::backclosemusiclayer));
	CCMenuItemSprite *ms2 = CCMenuItemSprite::create(sp5,sp5,this,menu_selector(MySetLayer::backopenmusiclayer));
	//难度
	CCMenuItemImage *sp6 = CCMenuItemImage::create("image/setting/easy.png","image/setting/easy.png",
		this,menu_selector(MySetLayer::easybacklayer));
	CCMenuItemImage *sp7 = CCMenuItemImage::create("image/setting/common.png","image/setting/common.png",
		this,menu_selector(MySetLayer::commonbacklayer));
	CCMenuItemImage *sp8 = CCMenuItemImage::create("image/setting/hard.png","image/setting/hard.png",
		this,menu_selector(MySetLayer::hardbacklayer));
	//CCSprite *sp7 = CCSprite::create("image/setting/common.png");
	//CCSprite *sp8 = CCSprite::create("image/setting/hard.png");

	CCMenuItemSprite *item1 = CCMenuItemSprite::create(sp2,sp3,this,menu_selector(MySetLayer::closesetlayer));
	item1->setPosition(ccp(sp1->getContentSize().width*0.8,sp1->getContentSize().height*0.8));

	CCMenuItemToggle *item2 = CCMenuItemToggle::createWithTarget(this,menu_selector(MySetLayer::menucallback),ms1,ms2,NULL);
	item2->setPosition(ccp(sp1->getContentSize().width*0.64,sp1->getContentSize().height*0.51));
	item2->setScale(0.8);

	CCMenuItemToggle *item3 = CCMenuItemToggle::createWithTarget(this,menu_selector(MySetLayer::menucallback),sp6,sp7,sp8,NULL);
	item3->setPosition(ccp(sp1->getContentSize().width*0.64,sp1->getContentSize().height*0.2));
	item3->setScale(0.8);

	CCMenu *menu = CCMenu::create(item1,item2,item3, NULL);
	menu->setPosition(CCPointZero);
	sp1->addChild(menu);

	return true;
}
void MySetLayer::closesetlayer(CCObject* sp)
{
	//this->removeFromParent();
	//this->setTouchEnabled(false);
	CCHide* h=CCHide::create();
	this->runAction(h);
	//开启back音乐
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();

	//开启所有被暂停的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	CCARRAY_FOREACH(array, object)  
	{  
		CCLayer* layer = (CCLayer*) object;  
		layer->onEnter();  
	}  
}
//关闭音乐
void MySetLayer::backclosemusiclayer(CCObject *sp2)
{
	//SimpleAudioEngine::sharedEngine()->playEffect(BUTTON);
	//SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
//开启音乐
void MySetLayer::backopenmusiclayer(CCObject *sp3)
{
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic(BG_MUSIC);
	//SimpleAudioEngine::sharedEngine()->playEffect(BUTTON);
}
//游戏难度
void MySetLayer::easybacklayer(CCObject *sp3)
{

}
void MySetLayer::commonbacklayer(CCObject *sp4)
{

}
void MySetLayer::hardbacklayer(CCObject *sp5)
{

}
//空的函数返回
void MySetLayer::menucallback(CCObject *sp6)
{
	//SimpleAudioEngine::sharedEngine()->playEffect(BUTTON);
	//SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//SimpleAudioEngine::sharedEngine()->stopAllEffects();
}