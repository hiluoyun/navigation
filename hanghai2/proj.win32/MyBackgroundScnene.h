#pragma once
#include "cocos2d.h"
#include "MyBackground.h"
#include "MyMenu.h"
#include "SimpleAudioEngine.h"
#define BG_MUSIC "backmusic.wav"

using namespace CocosDenshion;

using namespace cocos2d;
class MyBackgroundScnene :public CCScene
{
public:
	MyBackgroundScnene(void);
	~MyBackgroundScnene(void);
	virtual bool init();	
	CREATE_FUNC(MyBackgroundScnene);

//private:
//	MyBackground *backgroudLayer;
	/*MyMenu *menuLayer;*/
};

