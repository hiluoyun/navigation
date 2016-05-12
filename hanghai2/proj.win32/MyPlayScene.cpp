#include "MyPlayScene.h"
#define GM_MUSIC "gamemusic.wav"

MyPlayScene::MyPlayScene(void)
{

	SimpleAudioEngine::sharedEngine()->preloadEffect(GM_MUSIC);
	SimpleAudioEngine::sharedEngine()->preloadEffect("jump.wav");
    SimpleAudioEngine::sharedEngine()->preloadEffect("GameOver.mp3");
}


MyPlayScene::~MyPlayScene(void)
{
	SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
bool MyPlayScene::init()
{
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		SimpleAudioEngine::sharedEngine()->playEffect(GM_MUSIC,true);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("effect2",SimpleAudioEngine::sharedEngine()->playEffect(GM_MUSIC,true));
		//SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.4f);
	}
	MyPlayLayer* playbglayer=NULL;
	MyPlayMenu* playmenulayer=NULL;
	if(!CCScene::init())
	{
		return false;
	}

	playbglayer = MyPlayLayer::create();
	
	this->addChild(playbglayer,0,1);

	playmenulayer = MyPlayMenu::create();
	this->addChild(playmenulayer,0,2);

	return true;
}