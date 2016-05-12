#include "Zanting.h"


Zanting::Zanting(void)
{
}


Zanting::~Zanting(void)
{
}
 bool Zanting::init(){
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
	 spriteIsexit=CCSprite::create("image/pause/muban.png");
	 spriteIsexit->setScale(.6f);
	 spriteIsexit->setPosition(ccp(winSize.width/2,winSize.height/2));
	 addChild(spriteIsexit);

	 spriteNo=CCMenuItemImage::create("image/pause/play.png","image/pause/play.png",this,menu_selector(Zanting::gamecontinue));
	 spriteNo->setScale(.7f);
	 spriteNo->setPosition(winSize.width/2,winSize.height/2+30);

	 spriteYes=CCMenuItemImage::create("image/pause/return.png","image/pause/return.png",this,menu_selector(Zanting::gameback));;
	 spriteYes->setScale(.6f);
	 spriteYes->setPosition(winSize.width/2,winSize.height/2-20);

	 CCMenu* menu=CCMenu::create(spriteNo,spriteYes,NULL);
	 menu->setAnchorPoint(ccp(0,0));
	 menu->setPosition(ccp(0,0));
	 this->addChild(menu);
	 return true;
 }
 void Zanting::gameback(CCObject* o){
	 SimpleAudioEngine::sharedEngine()->stopAllEffects();
	 CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,MyBackgroundScnene::create()));
 }
 void Zanting::gamecontinue(CCObject* o){
	 this->removeFromParent();
	 //开启所有被暂停的场景中的层
	 SimpleAudioEngine::sharedEngine()->resumeAllEffects();
	 CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	 CCObject *object = NULL;  
	 CCARRAY_FOREACH(array, object)  
	 {  
		 CCLayer* layer = (CCLayer*) object;  
		 layer->onEnter();  
	 }  
 }