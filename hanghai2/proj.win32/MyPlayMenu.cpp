#include "MyPlayMenu.h"


MyPlayMenu::MyPlayMenu(void)
{
}


MyPlayMenu::~MyPlayMenu(void)
{
}
bool MyPlayMenu::init(){

	winsize=CCDirector::sharedDirector()->getWinSize();
	CCSprite *spr=CCSprite::create("image/pause/pause.png");
	spr->setScale(.5f);
	menuitemplay=CCMenuItemSprite::create(spr,spr,this,menu_selector(MyPlayMenu::playmenucallback));
	menuitemplay->setPosition(ccp(winsize.width*0.9,winsize.height*0.9));

	CCMenu *m=CCMenu::create(menuitemplay,NULL);
	m->setAnchorPoint(CCPointZero);
	m->setPosition(CCPointZero);
	this->addChild(m);
	return true;
}
void MyPlayMenu::playmenucallback(CCObject* o){
	Zanting* zantinglayer=NULL;
	zantinglayer=Zanting::create();
	this->getParent()->addChild(zantinglayer);
}