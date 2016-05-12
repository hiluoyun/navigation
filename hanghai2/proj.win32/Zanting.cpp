#include "Zanting.h"


Zanting::Zanting(void)
{
}


Zanting::~Zanting(void)
{
}
 bool Zanting::init(){

		 SimpleAudioEngine::sharedEngine()->pauseAllEffects();//��ͣ��Ч

	 CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	 //��ͣ�����������еĳ����еĲ�
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

	 spriteNo=CCMenuItemImage::create("image/pause/continue.png","image/pause/continue.png",this,menu_selector(Zanting::gamecontinue));
	 spriteNo->setScale(.5f);
	 spriteNo->setPosition(winSize.width/2,winSize.height/2+30);

	 spriteYes=CCMenuItemImage::create("image/pause/return.png","image/pause/return.png",this,menu_selector(Zanting::gameback));;
	 spriteYes->setScale(.5f);
	 spriteYes->setPosition(winSize.width/2,winSize.height/2-20);

	 CCMenu* menu=CCMenu::create(spriteNo,spriteYes,NULL);
	 menu->setAnchorPoint(ccp(0,0));
	 menu->setPosition(ccp(0,0));
	 this->addChild(menu);
	 return true;
 }
 void Zanting::gameback(CCObject* o){
	 CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,MyBackgroundScnene::create()));
 }
 void Zanting::gamecontinue(CCObject* o){
	 if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	 {
		 SimpleAudioEngine::sharedEngine()->resumeAllEffects();	
	 }
	 this->removeFromParent();
	 //�������б���ͣ�ĳ����еĲ�
	 CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	 CCObject *object = NULL;  
	 CCARRAY_FOREACH(array, object)  
	 {  
		 CCLayer* layer = (CCLayer*) object;  
		 layer->onEnter();  
	 }  
 }