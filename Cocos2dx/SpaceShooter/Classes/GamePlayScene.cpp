#include "GamePlayScene.h"

cocos2d::Scene * GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 or = Director::getInstance()->getVisibleOrigin();
	//-------------------------------------------------------------
	m_background = ResourceManager::GetInstance()->GetSpriteById(0);
	m_background->setAnchorPoint(Vec2(0, 0));
	m_background->setScale(vs.width / m_background->getContentSize().width, vs.height / m_background->getContentSize().width);
	m_background->removeFromParent();
	addChild(m_background, -999);
	//-------------------------------------------------------------
	m_spaceShip = new SpaceShooter(this);
	//-------------------------------------------------------------
	for (register int i = 0; i < 10; i++)
	{
		m_rocks.push_back(new Rock(this));
	}
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	//scheduleUpdate();
	return true;
}

void GamePlayScene::update(float dt)
{
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 or = Director::getInstance()->getVisibleOrigin();
	for (register int i = 0; i < m_rocks.size(); i++)
	{
		generateRock(m_rocks[i]);
		m_rocks[i]->Update(dt);
	}
	
}

void GamePlayScene::generateRock(Rock* rock)
{
	Size vs = Director::getInstance()->getVisibleSize();
	int maxWidth = vs.width;
	rock->getSprite()->setVisible(true);
	rock->getSprite()->setPosition(Vec2(random(10, maxWidth), vs.height + 20));
}

bool GamePlayScene::onTouchBegan(cocos2d::Touch * t, cocos2d::Event * e)
{
	//m_spaceShip->getSprite()->setPosition(t->getLocation());
	return true;
}

bool GamePlayScene::onTouchEnded(cocos2d::Touch *, cocos2d::Event *)
{
	return false;
}

void GamePlayScene::onTouchMoved(cocos2d::Touch * t, cocos2d::Event * e)
{
	m_spaceShip->getSprite()->setPosition(t->getLocation());
}
