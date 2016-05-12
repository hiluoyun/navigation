#include "MyMenu.h"


MyMenu::MyMenu(void)
{
	SimpleAudioEngine::sharedEngine()->preloadEffect(BUTTON);
}


MyMenu::~MyMenu(void)
{
}
bool MyMenu::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	winsize=CCDirector::sharedDirector()->getWinSize();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	CCTexture2D* aboutsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/about.png");
	CCTexture2D* exitsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/exit.jpg");
	CCTexture2D* gradesprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/grade.jpg");
	CCTexture2D* helpsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/help.png");
	CCTexture2D* playsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/play.png");
	//CCTexture2D* settingsprite=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/setting.png");
	CCTexture2D* settingsprite1=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/setting.png");
	CCTexture2D* settingsprite2=CCTextureCache::sharedTextureCache()->textureForKey("image/Menu/setting2.png");
	//加载exit按钮
	CCSprite* exitsp=CCSprite::createWithTexture(exitsprite);
	exitIt=CCMenuItemSprite::create(exitsp,exitsp,this,menu_selector(MyMenu::menucallback));
	exitIt->setPosition(ccp((2*origin.x + visibleSize.width)*100/800,(2*origin.y + visibleSize.height)*84/480));
	exitIt->setTag(1);

	//加载排行榜
	CCSprite* gradesp=CCSprite::createWithTexture(gradesprite);
	gradeIt=CCMenuItemSprite::create(gradesp,gradesp,this,menu_selector(MyMenu::menucallback));
	gradeIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*160/480));
	gradeIt->setTag(2);

	//加载关于
	CCSprite* aboutsp=CCSprite::createWithTexture(aboutsprite);
	aboutIt=CCMenuItemSprite::create(aboutsp,aboutsp,this,menu_selector(MyMenu::menucallback));
	aboutIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*116/480));
	aboutIt->setTag(3);

	//加载帮助
	CCSprite* helpsp=CCSprite::createWithTexture(helpsprite);
	helpIt=CCMenuItemSprite::create(helpsp,helpsp,this,menu_selector(MyMenu::menucallback));
	helpIt->setPosition(ccp((2*origin.x + visibleSize.width)*560/800,(2*origin.y + visibleSize.height)*70/480));
	helpIt->setTag(4);

	//加载play
	CCSprite* playsp1=CCSprite::createWithTexture(playsprite);
	CCSprite* playsp2=CCSprite::create("image/Menu/play1.png");
	playIt=CCMenuItemSprite::create(playsp1,playsp2,this,menu_selector(MyMenu::menucallback));
	playIt->setPosition(ccp((2*origin.x + visibleSize.width)*675/800,(2*origin.y + visibleSize.height)*400/480));
	playIt->setTag(5);

	//加载setting
	//CCSprite* settingsp=CCSprite::createWithTexture(settingsprite);
	CCSprite* settingsp1=CCSprite::createWithTexture(settingsprite1);
	CCSprite* settingsp2=CCSprite::createWithTexture(settingsprite2);
	settingIt=CCMenuItemSprite::create(settingsp1,settingsp2,this,menu_selector(MyMenu::menucallback));
	settingIt->setPosition(ccp((2*origin.x + visibleSize.width)*675/800,(2*origin.y + visibleSize.height)*55/480));
	settingIt->setTag(6);

	CCMenu* menu=CCMenu::create(exitIt,gradeIt,aboutIt,helpIt,playIt,settingIt,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->setPosition(ccp(0,0));
	this->addChild(menu);
	return true;
}
void MyMenu::menucallback(CCObject* pSender){

	//启用按钮音效
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		int e1 = SimpleAudioEngine::sharedEngine()->playEffect(BUTTON);
	}
	
	CCMenuItemSprite* s=(CCMenuItemSprite*) pSender;
	int tag=s->getTag();
	MyExitLayer *exitlayer=NULL;//搞不懂将其用做成员变量会出错
	MyAboutLayer *aboutlayer = NULL;//关于 类对象
	MyHelpLayer *helplayer = NULL;//帮助 类对象
	MySetLayer *setlayer = NULL;//设置 类对象
	MyRankLayer *ranklayer = NULL;//排行 类对象
	switch (tag)
	{
	case 1:
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		exitlayer = MyExitLayer::create();
		this->getParent()->addChild(exitlayer,2);
		break;
	case 2:
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		ranklayer = MyRankLayer::create();
		this->getParent()->addChild(ranklayer,2);
		break;
	case 3:
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		aboutlayer = MyAboutLayer::create();
		this->getParent()->addChild(aboutlayer,2);
		break;
	case 4:
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		helplayer = MyHelpLayer::create();
		this->getParent()->addChild(helplayer,2);
		break;
	case 5:
		//CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,MyPlayScene::create()));
		CCDirector::sharedDirector()->replaceScene(CCTransitionFadeBL::create(.2f,MyPlayScene::create()));
		break;
	case 6:
		setlayer = MySetLayer::create();
		this->getParent()->addChild(setlayer,2);
		break;
	default:
		
		break;
	}
}