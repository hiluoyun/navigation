#pragma once
#include "cocos2d.h"
#include "MyBackgroundScnene.h"

using namespace cocos2d;

class MyLoading : public CCLayer
{
public:
	MyLoading(void);
	~MyLoading(void);
	CCSize winsize;
	virtual bool init();  
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(MyLoading);

	void loadingjin(CCNode* sender);
	void changetobg();
private:
	CCLabelBMFont* label1;
	CCLabelBMFont* percentlabel;
	int numberOfSprites;
	int numberOfloadSprites;
	CCProgressTimer* timer;

	void updatapercent(CCObject* o);
};

