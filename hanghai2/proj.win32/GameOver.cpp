#include "GameOver.h"

GameOver::GameOver(void)
{
}


GameOver::~GameOver(void)
{
}
bool GameOver::init()
{
	if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
	{
		SimpleAudioEngine::sharedEngine()->stopEffect(CCUserDefault::sharedUserDefault()->getIntegerForKey("effect2"));
		SimpleAudioEngine::sharedEngine()->playEffect("GameOver.mp3");

		//SimpleAudioEngine::sharedEngine()->end();
	}
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	
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
	CCLOG("size=%d",i);


	//本次得分和排行榜
	sprite_rank=CCSprite::create("image/gameover/gameover.png");
	sprite_rank->setPosition(ccp(winSize.width/2,winSize.height*0.5));
	addChild(sprite_rank,0);

	//本次得分
	char str[10]={0};
	sprintf(str,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("curent_score"));
	CCLabelBMFont* label= CCLabelBMFont::create(str,"fonts/futura-48.fnt");
	label->setScale(.5f);
	label->setPosition(ccp(winSize.width/2,winSize.height*0.72f));
	this->addChild(label);
	//返回主页
	menu_comeback=CCMenuItemImage::create("image/gameover/comeback.png","image/gameover/comeback.png",this,menu_selector(GameOver::gameComeBack));
	menu_comeback->setPosition(ccp(winSize.width*450/800,winSize.height*80/450));

	//重新开始
	menu_restart=CCMenuItemImage::create("image/gameover/restart.png","image/gameover/restart.png",this,menu_selector(GameOver::gameRestart));;
	menu_restart->setPosition(ccp(winSize.width*360/800,winSize.height*80/450));

	CCMenu* menu=CCMenu::create(menu_restart,menu_comeback,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->setPosition(ccp(0,0));
	this->addChild(menu);

	//排行榜
	char grade5[10]={0};
	sprintf(grade5,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_5"));
	CCLabelBMFont* grade_5= CCLabelBMFont::create(grade5,"fonts/futura-48.fnt");
	grade_5->setScale(.5f);
	grade_5->setPosition(ccp(winSize.width*430/800,winSize.height*260/480));
	this->addChild(grade_5);

	char grade4[10]={0};
	sprintf(grade4,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_4"));
	CCLabelBMFont* grade_4= CCLabelBMFont::create(grade4,"fonts/futura-48.fnt");
	grade_4->setScale(.5f);
	grade_4->setPosition(ccp(winSize.width*430/800,winSize.height*228/480));
	this->addChild(grade_4);

	char grade3[10]={0};
	sprintf(grade3,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_3"));
	CCLabelBMFont* grade_3= CCLabelBMFont::create(grade3,"fonts/futura-48.fnt");
	grade_3->setScale(.5f);
	grade_3->setPosition(ccp(winSize.width*430/800,winSize.height*196/480));
	this->addChild(grade_3);

	char grade2[10]={0};
	sprintf(grade2,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_2"));
	CCLabelBMFont* grade_2= CCLabelBMFont::create(grade2,"fonts/futura-48.fnt");
	grade_2->setScale(.5f);
	grade_2->setPosition(ccp(winSize.width*430/800,winSize.height*164/480));
	this->addChild(grade_2);

	char grade1[10]={0};
	sprintf(grade1,"%d",CCUserDefault::sharedUserDefault()->getIntegerForKey("grade_1"));
	CCLabelBMFont* grade_1= CCLabelBMFont::create(grade1,"fonts/futura-48.fnt");
	grade_1->setScale(.5f);
	grade_1->setPosition(ccp(winSize.width*430/800,winSize.height*132/480));
	this->addChild(grade_1);

	return true;
}
void GameOver::gameRestart(CCObject* o)
{
	this->removeFromParent();
	//SimpleAudioEngine::sharedEngine()->unloadEffect("gamemusic.wav");
	//SimpleAudioEngine::sharedEngine()->stopAllEffects();
	MyPlayScene * pl = MyPlayScene::create();
	CCTransitionFadeBL *tr = CCTransitionFadeBL::create(.2f,pl);
	CCDirector::sharedDirector()->replaceScene(tr);
}
void GameOver::gameComeBack(CCObject* o){
	CCScene *scene1=MyBackgroundScnene::create();
	CCDirector::sharedDirector()->replaceScene(scene1);
}