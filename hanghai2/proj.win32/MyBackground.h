#pragma once
#include "cocos2d.h"

using namespace cocos2d;
class MyBackground : public CCLayer
{
public:
	MyBackground(void);
	~MyBackground(void);
	virtual bool init();  
	/*static CCScene* scene();*/
	CREATE_FUNC(MyBackground);

	virtual void keyBackClicked( void );

private:
	CCSize winsize;
	/*void exitcallback(CCObject* pSender);
	void gradecallback(CCObject* pSender);
	void aboutcallback(CCObject* pSender);
	void helpcallback(CCObject* pSender);
	void playcallback(CCObject* pSender);
	void settingcallbcak(CCObject* pSender);*/
};

