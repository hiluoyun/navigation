#include "MyBackgroundScnene.h"


MyBackgroundScnene::MyBackgroundScnene(void)
{
		//¼ÓÔØÒôÀÖ
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(BG_MUSIC);
}


MyBackgroundScnene::~MyBackgroundScnene(void)
{
	//ÇĞ»»³¡¾°ÔİÍ£±³¾°ÒôÀÖ
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
bool MyBackgroundScnene::init()
{
	//²¥·Å±³¾°ÒôÀÖ
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(BG_MUSIC);

	MyBackground *backgroudLayer=NULL;
	MyMenu *menuLayer=NULL;
	if(!CCScene::init())
	{
		return false;
	}

	backgroudLayer = MyBackground::create();
	this->addChild(backgroudLayer,0,1);

	menuLayer = MyMenu::create();
	this->addChild(menuLayer,0,2);

	return true;
}