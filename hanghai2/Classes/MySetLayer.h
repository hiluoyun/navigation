#pragma once
#include "cocos2d.h"
#include "MyMenu.h"
#include "SimpleAudioEngine.h"
#define BG_MUSIC "backmusic.mp3"

using namespace CocosDenshion;

class MySetLayer :public CCLayer
{
public:
	MySetLayer(void);
	~MySetLayer(void);
	virtual bool init();
	CREATE_FUNC(MySetLayer);
private:
	void closesetlayer(CCObject* sp1);//�ر����ò˵�

	void backclosemusiclayer(CCObject *sp2);//�ر�����
	void backopenmusiclayer(CCObject *sp3);//��������

	void easybacklayer(CCObject *sp3);//���ü�ģʽ  Ĭ��
	void commonbacklayer(CCObject *sp4);//����һ��ģʽ
	void hardbacklayer(CCObject *sp5);//��������ģʽ

	void menucallback(CCObject *sp6);//
};

