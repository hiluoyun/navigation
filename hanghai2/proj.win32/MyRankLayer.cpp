#include "MyRankLayer.h"


MyRankLayer::MyRankLayer(void)
{
}


MyRankLayer::~MyRankLayer(void)
{
}
bool MyRankLayer::init()
{
	
	//暂停所有正在运行的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	int i=0;
	CCARRAY_FOREACH(array, object)  
	{  
		i++;
		CCLayer *layer = (CCLayer*) object;  
		layer->onExit();  
	}  

	CCSize size = CCDirector::sharedDirector()->getWinSize();//获取当前屏幕大小
	CCSize winSize=size;

	//排行榜
	CCSprite *sp1 = CCSprite::create("image/ranking/paihang.png");
	sp1->setPosition(ccp(size.width/2,size.height+sp1->getContentSize().height/2));
	this->addChild(sp1);
	CCMoveBy *move = CCMoveBy::create(0.3f,ccp(0,-size.height*0.58-sp1->getContentSize().height/2));
	CCEaseSineIn *exp = CCEaseSineIn::create(move);
	sp1->runAction(exp);

	//退出按钮
	CCMenuItemImage *item = CCMenuItemImage::create("image/ranking/X.png","image/ranking/X3.png",this,menu_selector(MyRankLayer::rankbacklayer));
	item->setPosition(ccp(sp1->getPositionX()+sp1->getContentSize().width*0.08,sp1->getPositionY()+sp1->getContentSize().height*0.42));
	item->setScale(0.8);
	item->runAction((CCActionInterval*)move->copy());

	CCMenu *menu = CCMenu::create(item,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu);

	//排行榜数据
	char grade5[10]={0};
	sprintf(grade5,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_5"));
	CCLabelBMFont* grade_5= CCLabelBMFont::create(grade5,"fonts/futura-48.fnt");
	grade_5->setScale(.5f);
	grade_5->setPosition(ccp(-20,winSize.height/2));
	CCMoveTo* move5=CCMoveTo::create(1.0f,ccp(winSize.width*376/800,winSize.height*224/480));
	CCRotateBy* ro5=CCRotateBy::create(1.0f,360);
	CCSpawn* spaw5=CCSpawn::create(move5,ro5,NULL);
	grade_5->runAction(spaw5);
	this->addChild(grade_5);

	char grade4[10]={0};
	sprintf(grade4,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_4"));
	CCLabelBMFont* grade_4= CCLabelBMFont::create(grade4,"fonts/futura-48.fnt");
	grade_4->setScale(.5f);
	grade_4->setPosition(ccp(winSize.width/2,winSize.height+20));
	CCMoveTo* move4=CCMoveTo::create(1.0f,ccp(winSize.width*376/800,winSize.height*183/480));
	CCRotateBy* ro4=CCRotateBy::create(1.0f,360);
	CCSpawn* spaw4=CCSpawn::create(move4,ro4,NULL);
	grade_4->runAction(spaw4);
	this->addChild(grade_4);

	char grade3[10]={0};
	sprintf(grade3,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_3"));
	CCLabelBMFont* grade_3= CCLabelBMFont::create(grade3,"fonts/futura-48.fnt");
	grade_3->setScale(.5f);

	grade_3->setPosition(ccp(winSize.width+20,winSize.height/2));
	CCMoveTo* move3=CCMoveTo::create(1.0f,ccp(winSize.width*376/800,winSize.height*142/480));
	CCRotateBy* ro3=CCRotateBy::create(1.0f,360);
	CCSpawn* spaw3=CCSpawn::create(move3,ro3,NULL);
	grade_3->runAction(spaw3);
	this->addChild(grade_3);

	char grade2[10]={0};
	sprintf(grade2,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_2"));
	CCLabelBMFont* grade_2= CCLabelBMFont::create(grade2,"fonts/futura-48.fnt");
	grade_2->setScale(.5f);
	grade_2->setPosition(ccp(winSize.width/2,-20));

	CCMoveTo* move2=CCMoveTo::create(1.0f,ccp(winSize.width*376/800,winSize.height*100/480));
	CCRotateBy* ro2=CCRotateBy::create(1.0f,360);
	CCSpawn* spaw2=CCSpawn::create(move2,ro2,NULL);
	grade_2->runAction(spaw2);
	this->addChild(grade_2);

	char grade1[10]={0};
	sprintf(grade1,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_1"));
	CCLabelBMFont* grade_1= CCLabelBMFont::create(grade1,"fonts/futura-48.fnt");
	grade_1->setScale(.5f);
	grade_1->setPosition(ccp(-20,winSize.height+20));

	CCMoveTo* move1=CCMoveTo::create(1.0f,ccp(winSize.width*376/800,winSize.height*59/480));
	CCRotateBy* ro1=CCRotateBy::create(1.0f,360);
	CCSpawn* spaw1=CCSpawn::create(move1,ro1,NULL);
	grade_1->runAction(spaw1);
	this->addChild(grade_1);




	return true;
}
void MyRankLayer::rankbacklayer(CCObject* sp)
{
	//恢复背景音乐
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
	

	this->removeFromParent();
	//开启所有被暂停的场景中的层
	CCArray *array = CCDirector::sharedDirector()->getRunningScene()->getChildren();  
	CCObject *object = NULL;  
	CCARRAY_FOREACH(array, object)  
	{  
		CCLayer* layer = (CCLayer*) object;  
		layer->onEnter();  
	}  
}