#include "MyPlayScene.h"


MyPlayScene::MyPlayScene(void)
{
	SimpleAudioEngine::sharedEngine()->preloadEffect("gamemusic.mp3");
}


MyPlayScene::~MyPlayScene(void)
{
	//SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
bool MyPlayScene::init(){
	SimpleAudioEngine::sharedEngine()->playEffect("gamemusic.mp3");
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5 );
	MyPlayLayer* playbglayer=MyPlayLayer::create();
	MyPlayMenu* playmenulayer=NULL;//游戏中的按钮
	if(!CCScene::init())
	{
		return false;
	}


	this->addChild(playbglayer,0,1);

	playmenulayer = MyPlayMenu::create();
	this->addChild(playmenulayer,0,2);

	return true;
}