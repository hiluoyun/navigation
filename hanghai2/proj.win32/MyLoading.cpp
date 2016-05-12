#include "MyLoading.h"


MyLoading::MyLoading(void)
{
}


MyLoading::~MyLoading(void)
{
}
bool MyLoading::init(){
	winsize=CCDirector::sharedDirector()->getWinSize();//��ȡ��Ļ��С
	CCSprite* loadsprit=CCSprite::create("image/loading/logo.jpg");
	loadsprit->setScale(0);
	this->addChild(loadsprit);
	loadsprit->setPosition(ccp(winsize.width/2,winsize.height/2));//

	CCScaleTo* scaleto=CCScaleTo::create(1.0f,1);//���Ŷ���
	CCRotateBy* rotateBy=CCRotateBy::create(1.0f, 360);//��ת����
	CCSpawn* spawn=CCSpawn::create(rotateBy, scaleto,NULL);//�������
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
	
	timer->setBarChangeRate(ccp(1,0));//���ý������ı仯����
	timer->setType(kCCProgressTimerTypeBar);//����Ϊ��������
	timer->setPosition(ccp(winsize.width/2,winsize.height*0.08));
	timer->setBarChangeRate(ccp(1,0));//�����˶���x��Ϊ1,y��Ϊ0���൱��boolֵ
	timer->setMidpoint(ccp(0,0));//�����˶�����xΪ0ʱ�����������ƶ���������yֵ�����壬��Ϊ�Ѿ��趨Ϊ�����˶�
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

	//������ʾloading...
	label1=CCLabelBMFont::create("loading...","fonts/futura-48.fnt");//����loading������
	label1->setAnchorPoint(ccp(0,0));
	label1->setScale(.4f);//����0.4��
	label1->setPosition(ccp(winsize.width/2-label1->getContentSize().width/3,timer->getPosition().y+timer->getContentSize().height/2));
	this->addChild(label1);
	//label1->setColor(ccc3(0,0,0));

	//���ȼ��ذٷֱ�
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