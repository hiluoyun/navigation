#include "MyLoading.h"


MyLoading::MyLoading(void)
{
}


MyLoading::~MyLoading(void)
{
}
bool MyLoading::init(){
	winsize=CCDirector::sharedDirector()->getWinSize();//获取屏幕大小
	CCSprite* loadsprit=CCSprite::create("image/loading/logo.jpg");
	loadsprit->setScale(0);
	this->addChild(loadsprit);
	loadsprit->setPosition(ccp(winsize.width/2,winsize.height/2));//

	CCScaleTo* scaleto=CCScaleTo::create(1.0f,1);//缩放动作
	CCRotateBy* rotateBy=CCRotateBy::create(1.0f, 360);//旋转动作
	CCSpawn* spawn=CCSpawn::create(rotateBy, scaleto,NULL);//动作组合
	CCCallFuncN* fun1=CCCallFuncN::create(this,callfuncN_selector(MyLoading::loadingjin));
	CCSequence* sequence=CCSequence::create(spawn,CCDelayTime::create(.8f),fun1,NULL);
	loadsprit->runAction(sequence);

	return true;
}  

void MyLoading::loadingjin(CCNode* sender){
	CCSprite* sprite3=CCSprite::create("image/loading/jindu/n01.png");
	sprite3->setPosition(ccp(winsize.width/2,winsize.height*0.08));
	this->addChild(sprite3);
	CCProgressFromTo* to=CCProgressFromTo::create(1,15,100);

	timer=CCProgressTimer::create(CCSprite::create("image/loading/jindu/n11.png"));
	
	timer->setBarChangeRate(ccp(1,0));//设置进度条的变化速率
	timer->setType(kCCProgressTimerTypeBar);//设置为条形类型
	timer->setPosition(ccp(winsize.width/2,winsize.height*0.08));
	timer->setBarChangeRate(ccp(1,0));//横向运动的x设为1,y设为0，相当于bool值
	timer->setMidpoint(ccp(0,0));//决定运动方向，x为0时，从左往右移动，这里设y值无意义，因为已经设定为横向运动
	//float percentage=timer->getPercentage();
	//CCRepeatForever* fore=CCRepeatForever::create(to);
	this->addChild(timer,1);
	timer->runAction(to);

	numberOfSprites=80;
	numberOfloadSprites=0;
	for (int i=0;i<10;i++)
	{
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/about.png",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/exit.jpg",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/grade.jpg",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/help.png",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/play.png",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/setting.png",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/Menu/setting2.png",this,callfuncO_selector(MyLoading::updatapercent));
		CCTextureCache::sharedTextureCache()->addImageAsync("image/backgroud/backgroud.jpg",this,callfuncO_selector(MyLoading::updatapercent));
	}

	//设置提示loading...
	label1=CCLabelBMFont::create("loading...","fonts/futura-48.fnt");//设置loading的文字
	label1->setAnchorPoint(ccp(0,0));
	label1->setScale(.4f);//缩放0.4倍
	label1->setPosition(ccp(winsize.width/2-label1->getContentSize().width/3,timer->getPosition().y+timer->getContentSize().height/2));
	this->addChild(label1);
	//label1->setColor(ccc3(0,0,0));

	//进度加载百分比
	percentlabel=CCLabelBMFont::create("0%","fonts/futura-48.fnt");
	percentlabel->setAnchorPoint(ccp(0,0));
	percentlabel->setScale(.4f);
	percentlabel->setPosition(ccp(winsize.width*420/800,timer->getPosition().y+timer->getContentSize().height/2));
	this->addChild(percentlabel);
	//percentlabel->setColor(ccc3(0,0,0));

	
}
void MyLoading::updatapercent(CCObject* o){
	numberOfloadSprites++;
	float val=((float)numberOfloadSprites/numberOfSprites)*100;
	char tmp[10]={0};
	sprintf(tmp,"%d%%",(int)val);
	percentlabel->setString(tmp);
	timer->setPercentage(val);
	if (numberOfSprites==numberOfloadSprites)
	{
		CCCallFunc* f=CCCallFunc::create(this,callfunc_selector(MyLoading::changetobg));
		CCSequence* s=CCSequence::create(CCDelayTime::create(.5f),f,NULL);
		timer->runAction(s);
	}
	
}
void MyLoading::changetobg(){
	CCScene *scene1=MyBackgroundScnene::create();
	CCDirector::sharedDirector()->replaceScene(scene1);
}

CCScene* MyLoading::scene(){
	CCScene *scene = CCScene::create();
	MyLoading *layer = MyLoading::create();
	scene->addChild(layer);
	return scene;
}