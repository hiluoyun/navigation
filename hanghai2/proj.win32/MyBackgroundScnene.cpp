#include "MyBackgroundScnene.h"
#include "MyActiveLayer.h"

MyBackgroundScnene::MyBackgroundScnene(void)
{
		//��������
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(BG_MUSIC);
}


MyBackgroundScnene::~MyBackgroundScnene(void)
{
	//�л�������ͣ��������
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
bool MyBackgroundScnene::init()
{
	//���ű�������
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
	this->addChild(backgroudLayer,0,1);//���ر���

	menuLayer = MyMenu::create();
	this->addChild(menuLayer,0,2);//���ز˵�

	MyActiveLayer* activity=MyActiveLayer::create();
	this->addChild(activity,1);//���ض���

	return true;
}