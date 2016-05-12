#include "MyRankLayer.h"


MyRankLayer::MyRankLayer(void)
{
}


MyRankLayer::~MyRankLayer(void)
{
}
bool MyRankLayer::init()
{
	
	//��ͣ�����������еĳ����еĲ�
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	int i=0;
	CCARRAY_FOREACH(array, object)  
	{  
		i++;
		CCLayer *layer = (CCLayer*) object;  
		layer->onExit();  
	}  

	CCSize size = CCDirector::sharedDirector()->getWinSize();//��ȡ��ǰ��Ļ��С

	CCSprite *sp1 = CCSprite::create("image/ranking/paihang.png");
	sp1->setPosition(ccp(size.width/2,size.height+sp1->getContentSize().height/2));

	this->addChild(sp1);
	CCMoveBy *move = CCMoveBy::create(0.3,ccp(0,-size.height*0.58-sp1->getContentSize().height/2));
	CCEaseSineIn *exp = CCEaseSineIn::create(move);
	sp1->runAction(exp);

	CCMenuItemImage *item = CCMenuItemImage::create("image/ranking/X.png","image/ranking/X3.png",this,menu_selector(MyRankLayer::rankbacklayer));
	item->setPosition(ccp(sp1->getPositionX()+sp1->getContentSize().width*0.08,sp1->getPositionY()+sp1->getContentSize().height*0.42));
	item->setScale(0.8);
	item->runAction((CCActionInterval*)move->copy());

	CCMenu *menu = CCMenu::create(item,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu);



	return true;
}
void MyRankLayer::rankbacklayer(CCObject* sp)
{
	//�ָ���������
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();

	this->removeFromParent();
	//�������б���ͣ�ĳ����еĲ�
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	CCARRAY_FOREACH(array, object)  
	{  
		CCLayer* layer = (CCLayer*) object;  
		layer->onEnter();  
	}  
}