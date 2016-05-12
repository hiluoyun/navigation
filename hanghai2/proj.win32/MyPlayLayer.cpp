#include "MyPlayLayer.h"


MyPlayLayer::MyPlayLayer(void)
{
	srand(time(NULL));
	collision_1=NULL;
	collision_2=NULL;
	collision_3=NULL;
	collision_4=NULL;
	collision_5=NULL;
	sprite=NULL;
	collisionsArrayContatct=NULL;
	collisions=NULL;
	progressFrom=100;
	progressTo=100;
	flag=false;
	score=0;
	label=NULL;
	repeat=0;
	speed_score=10;
	winsize=CCDirector::sharedDirector()->getWinSize();	
	/*SimpleAudioEngine::sharedEngine()->playEffect("gamemusic.wav",true);*/
}


MyPlayLayer::~MyPlayLayer(void)
{
	unscheduleAllSelectors();
}

//初始化操作
bool MyPlayLayer::init()
{
	scheduleUpdate();
	this->setTouchEnabled(true);
	sprite=Mysprite::create();
	CCMoveTo* move=CCMoveTo::create(1.2f,ccp(winsize.width*0.20,winsize.height/6));
	CCEaseBounceOut* out=CCEaseBounceOut::create(move);
	sprite->runAction(out);
	this->addChild(sprite,2);
	loadBackground();

	label = CCLabelBMFont::create("Score:0","fonts/futura-48.fnt");
	label->setScale(.7f);
	label->setOpacity(150);
	addChild(label,1);
	label->setColor(ccc3(255,230,0));
	label->setPosition(ccp(winsize.width/2,winsize.height*0.85f));

	return true;
}

//按屏幕所触发的事件
void MyPlayLayer::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
	if (sprite->getPositionY()==winsize.height/6)
	{
		if(CCUserDefault::sharedUserDefault()->getBoolForKey(EFFECT))
		{
			int e3 = SimpleAudioEngine::sharedEngine()->playEffect("jump.wav");
		}
		sprite->myjump();
	}
}

//加载下一张背景图片
void MyPlayLayer::loadNextMap(){
	int mapId=CCRANDOM_0_1()*10+1;
	CCLOG("id=%d",mapId);
	char map[30]={0};
	sprintf(map,"image/playbackground/bg%d.png",mapId);
	this->next_bg=CCSprite::create(map);
	next_bg->setPosition(CCPoint(cur_bg->getPositionX()+next_bg->getContentSize().width,winsize.height/2));
	this->addChild(next_bg,0);
} 

//load加载整个背景
void MyPlayLayer::loadBackground(){
	cur_bg=CCSprite::create("image/playbackground/bg1.png");
	cur_bg->setPosition(ccp(winsize.width/2,winsize.height/2));
	this->addChild(cur_bg,0);

	loadNextMap();
	addCollisions();
}

//add添加障碍物到背景中
void MyPlayLayer::addCollisions(){
	collision_1=CCSprite::create("image/playbackground/collision1.png");
	collision_1->setPosition(ccp(winsize.width*1.2f,winsize.height/6));
	this->addChild(collision_1,1);

	collision_2=CCSprite::create("image/playbackground/collision2.png");
	collision_2->setPosition(ccp(winsize.width*2.5f,winsize.height/6));
	this->addChild(collision_2,1);

	collision_3=CCSprite::create("image/playbackground/collision3.png");
	collision_3->setPosition(ccp(winsize.width*3.5f,winsize.height/6));
	this->addChild(collision_3,1);

	collision_4=CCSprite::create("image/playbackground/collision4.png");
	collision_4->setPosition(ccp(winsize.width*4.2f,winsize.height/6));
	this->addChild(collision_4,1);

	collision_5=CCSprite::create("image/playbackground/collision5.png");
	collision_5->setPosition(ccp(winsize.width*4.8f,winsize.height/6));
	this->addChild(collision_5,1);

}

//move移动障碍物根据首页中设置的难度设置障碍物的间距
void MyPlayLayer::moveCollisions(){
	float Id=0;
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey("hard"))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey("hard",1);
	}
	int hard=CCUserDefault::sharedUserDefault()->getIntegerForKey("hard");
	collisions=CCArray::create(collision_1,collision_2,collision_3,collision_4,collision_5,NULL);
	for (int i=0;i<collisions->count();i++)
	{
		CCSprite* last_sprite;
		CCSprite* cur_sprite=(CCSprite*)collisions->objectAtIndex(i);
		if (cur_sprite->getPositionX()+cur_sprite->getContentSize().width<0)
		{
			if (cur_sprite==collisions->objectAtIndex(0))
			{
				last_sprite=(CCSprite*)collisions->objectAtIndex(4);
			}else{
				last_sprite=(CCSprite*)collisions->objectAtIndex(i-1);
			}
			float last_position=last_sprite->getPositionX();
			Id=CCRANDOM_0_1();
			//根据首页中设置的难度设置障碍物的间距
			switch (hard)
			{
			case 1:
				cur_sprite->setPositionX((last_position+winsize.width*0.5+winsize.width*2*Id));
				break;
			case 2:
				cur_sprite->setPositionX((last_position+winsize.width*0.4+winsize.width*2*Id));
				break;
			default:
				cur_sprite->setPositionX((last_position+winsize.width*0.3+winsize.width*2*Id));
				break;
			}
			
		}else
			{
				cur_sprite->setPositionX(cur_sprite->getPositionX()-sprite->m_speed);
			}
	}

}
//updata更新下一张背景图片,1/60秒调用一次
void MyPlayLayer::update(float dt)
{
	contactBegein();
	changeHard();
	moveCollisions();
	setScore();
	cur_bg->setPositionX(cur_bg->getPositionX()-sprite->m_speed);
	next_bg->setPositionX(next_bg->getPositionX()-sprite->m_speed);
	if (next_bg->getPositionX()<=winsize.width/2)
	{
		cur_bg=next_bg;
		loadNextMap();
	}
	
}

//改变游戏难度，越到后面速度越快，分数加倍速率越快
void MyPlayLayer::changeHard(){
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey("hard"))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey("hard",1);
	}
	int hard=CCUserDefault::sharedUserDefault()->getIntegerForKey("hard");
	if (!(score>100))
	{
		switch (hard)
		{
		case 1:
			speed_score=10;
			sprite->m_speed=5;
			break;
		case 2:
			speed_score=5;
			sprite->m_speed=7;
			break;
		default:
			speed_score=4;
			sprite->m_speed=8;
			break;
		}
	}
	switch (this->score)
	{

	case 100:
		speed_score=speed_score<8?speed_score:8;
		sprite->m_speed=6>sprite->m_speed?6:sprite->m_speed;
		break;
	case 300:
		speed_score=speed_score<6?speed_score:6;
		sprite->m_speed=7>sprite->m_speed?7:sprite->m_speed;
		break;
	case 400:
		speed_score=speed_score<5?speed_score:5;
		sprite->m_speed=8>sprite->m_speed?8:sprite->m_speed;
		break;
	case 500:
		speed_score=speed_score<4?speed_score:4;
		sprite->m_speed=9>sprite->m_speed?9:sprite->m_speed;
		break;
	case 600:
		speed_score=speed_score<3?speed_score:3;
		sprite->m_speed=10>sprite->m_speed?10:sprite->m_speed;
		break;
	case 700:
		speed_score=speed_score<2?speed_score:2;
		sprite->m_speed=11>sprite->m_speed?11:sprite->m_speed;
		break;

	case 1500:
		speed_score=speed_score<1?speed_score:1;
		sprite->m_speed=15>sprite->m_speed?15:sprite->m_speed;
		break;
	}
	CCLOG("speed_score=%d",speed_score);
}

//设置分数
void MyPlayLayer::setScore(){
	repeat++;
	if (repeat==speed_score)
	{
		this->score+=1;
		repeat=0;
	}
	char str[100]={0};
	sprintf(str,"Score:%d",score);
	label->setString(str);
	
}

//contact当主角与障碍物碰撞时调用
void MyPlayLayer::contactBegein(){
	GameOver* gameVoer;
	collisionsArrayContatct=CCArray::create(collision_1,collision_2,collision_3,collision_4,collision_5,NULL);
	for (int i=0;i<collisionsArrayContatct->count();i++)
	{
		CCSprite* cur_sprite=(CCSprite*)collisionsArrayContatct->objectAtIndex(i);
		if (sprite->boundingBox().intersectsRect(cur_sprite->boundingBox())&&!flag)
		{

			savaScore();
			cur_sprite->setColor(ccc3(255,0,0));
			gameVoer = GameOver::create();

			

			this->getParent()->addChild(gameVoer);
			CCLOG("... layer touch");
			/*progressTo=timer->getPercentage()-25;
			progressFrom=timer->getPercentage();
			flag=true;*/
		}
	}
}

//保存当前分数
void MyPlayLayer::savaScore(){
	char c[10]={0};
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey("curent_score"))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey("curent_score",0);
	}
	CCUserDefault::sharedUserDefault()->setIntegerForKey("curent_score",score);
	for (int i=0;i<5;i++)
	{
		
		sprintf(c,"grade_%d",i+1);
		if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(c))
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey(c,0);
		}
		vec.push_back(CCUserDefault::sharedUserDefault()->getIntegerForKey(c));
	}
	
	vec.push_back(CCUserDefault::sharedUserDefault()->getIntegerForKey("curent_score",0));
	CCLOG("vec.size=%d, cur_score=%d",vec.size(),vec.at(vec.size()-1));
	sort(vec.begin(),vec.end());
	for (int j=1;j<vec.size();j++)
	{
		CCLOG("num1=%d",vec.at(j));
		sprintf(c,"grade_%d",j);
		CCUserDefault::sharedUserDefault()->setIntegerForKey(c,vec.at(j));
	}
	
}

void MyPlayLayer::keyBackClicked( void )
{
	Zanting* zantinglayer=NULL;
	zantinglayer=Zanting::create();
	this->getParent()->addChild(zantinglayer);
}

void MyPlayLayer::keyMenuClicked( void )
{
	Zanting* zantinglayer=NULL;
	zantinglayer=Zanting::create();
	this->getParent()->addChild(zantinglayer);
}