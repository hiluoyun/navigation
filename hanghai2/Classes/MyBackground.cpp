#include "MyBackground.h"


MyBackground::MyBackground(void)
{
}


MyBackground::~MyBackground(void)
{
}
bool MyBackground::init(){
	winsize=CCDirector::sharedDirector()->getWinSize();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	/*CCTexture2D* aboutsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/about.png");
	CCTexture2D* exitsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/exit.jpg");
	CCTexture2D* gradesprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/grade.jpg");
	CCTexture2D* helpsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/help.png");
	CCTexture2D* playsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/play.png");
	CCTexture2D* settingsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/setting.png");*/


	CCTexture2D* bgsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/backgroud/backgroud.jpg");

	//加载背景图
	CCSprite* bgsp=CCSprite::createWithTexture(bgsprite);
	this->addChild(bgsp);
	bgsp->setPosition(ccp(winsize.width/2,winsize.height/2));
	//CCLOG("size=%d,%d",bgsp->boundingBox().getMaxX(),bgsp->boundingBox().getMaxY());

	////加载exit按钮
	//CCSprite* exitsp=CCSprite::createWithTexture(exitsprite);
	//CCMenuItemSprite* exitIt=CCMenuItemSprite::create(exitsp,exitsp,this,menu_selector(MyBackground::exitcallback));
	//exitIt->setPosition(ccp((2*origin.x + visibleSize.width)*100/800,(2*origin.y + visibleSize.height)*84/480));

	////加载排行榜
	//CCSprite* gradesp=CCSprite::createWithTexture(gradesprite);
	//CCMenuItemSprite* gradeIt=CCMenuItemSprite::create(gradesp,gradesp,this,menu_selector(MyBackground::gradecallback));
	//gradeIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*160/480));

	////加载关于
	//CCSprite* aboutsp=CCSprite::createWithTexture(aboutsprite);
	//CCMenuItemSprite* aboutIt=CCMenuItemSprite::create(aboutsp,aboutsp,this,menu_selector(MyBackground::aboutcallback));
	//aboutIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*116/480));

	////加载帮助
	//CCSprite* helpsp=CCSprite::createWithTexture(helpsprite);
	//CCMenuItemSprite* helpIt=CCMenuItemSprite::create(helpsp,helpsp,this,menu_selector(MyBackground::helpcallback));
	//helpIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*70/480));

	////加载play
	//CCSprite* playsp=CCSprite::createWithTexture(playsprite);
	//CCMenuItemSprite* playIt=CCMenuItemSprite::create(playsp,playsp,this,menu_selector(MyBackground::playcallback));
	//playIt->setPosition(ccp((2*origin.x + visibleSize.width)*675/800,(2*origin.y + visibleSize.height)*400/480));

	////加载setting
	//CCSprite* settingsp=CCSprite::createWithTexture(settingsprite);
	//CCMenuItemSprite* settingIt=CCMenuItemSprite::create(settingsp,settingsp,this,menu_selector(MyBackground::settingcallbcak));
	//settingIt->setPosition(ccp((2*origin.x + visibleSize.width)*675/800,(2*origin.y + visibleSize.height)*55/480));

	//CCMenu* menu=CCMenu::create(exitIt,gradeIt,aboutIt,helpIt,playIt,settingIt,NULL);
	//menu->setAnchorPoint(ccp(0,0));
	//menu->setPosition(ccp(0,0));
	//this->addChild(menu);
	return true;
}  

void MyBackground::keyBackClicked( void )
{
	//MyExitLayer* exitlayer=NULL;
	//exitlayer=MyExitLayer::create();
	//this->getParent()->addChild(exitlayer);
}


//void MyBackground::exitcallback(CCObject* pSender){
//	CCDirector::sharedDirector()->end();
//}
//void MyBackground::gradecallback(CCObject* pSender){
//
//}
//void MyBackground::aboutcallback(CCObject* pSender){
//
//}
//void MyBackground::helpcallback(CCObject* pSender){
//
//}
//void MyBackground::playcallback(CCObject* pSender){
//
//}
//void MyBackground::settingcallbcak(CCObject* pSender){
//
//}
//CCScene* MyBackground::scene(){
//	CCScene *scene = CCScene::create();
//	MyBackground *layer = MyBackground::create();
//	scene->addChild(layer);
//	return scene;
//}