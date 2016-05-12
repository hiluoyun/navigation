#include "MyBackgroundScnene.h"
#include "MyActiveLayer.h"

MyBackgroundScnene::MyBackgroundScnene(void)
{
		//º”‘ÿ“Ù¿÷
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(BG_MUSIC);
}


MyBackgroundScnene::~MyBackgroundScnene(void)
{
	//«–ªª≥°æ∞‘›Õ£±≥æ∞“Ù¿÷
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
bool MyBackgroundScnene::init()
{
	//≤•∑≈±≥æ∞“Ù¿÷
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(BG_MUSIC,true);
	}

	MyBackground *backgroudLayer=NULL;
	MyMenu *menuLayer=NULL;
	if(!CCScene::init())
	{
		return false;
	}

	backgroudLayer = MyBackground::create();
	this->addChild(backgroudLayer,0,1);//º”‘ÿ±≥æ∞

	menuLayer = MyMenu::create();
	this->addChild(menuLayer,0,2);//º”‘ÿ≤Àµ•

	MyActiveLayer* activity=MyActiveLayer::create();
	this->addChild(activity,1);//º”‘ÿ∂Øª≠

	return true;
}