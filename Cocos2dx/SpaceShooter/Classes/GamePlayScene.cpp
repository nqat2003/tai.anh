#include "GamePlayScene.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

int score = 0;
cocos2d::Scene * GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 or = Director::getInstance()->getVisibleOrigin();
	//-------------------------------------------------------------
	auto audio = SimpleAudioEngine::getInstance();
	// set the background music and continuously play it.
	audio->playBackgroundMusic("ingame.mp3", true);
	audio->setEffectsVolume(0.6f);
	//-------------------------------------------------------------
	m_background = ResourceManager::GetInstance()->GetSpriteById(0);
	m_background->setAnchorPoint(Vec2(0, 0));
	m_background->setScale(vs.width / m_background->getContentSize().width, vs.height / m_background->getContentSize().width);
	m_background->removeFromParent();
	addChild(m_background, -999);
	//-------------------------------------------------------------
	m_lbScore = ResourceManager::GetInstance()->GetLabelById(0);
	string label = "Your Score: " + to_string(GamePlayScene::getScore());
	m_lbScore->setString(label);
	m_lbScore->setPosition(Vec2(vs.width - 100, vs.height - 50));
	m_lbScore->removeFromParent();
	addChild(m_lbScore, 3);
	//-------------------------------------------------------------
	m_spaceShip = new SpaceShooter(this);
	m_spaceShip->getSprite()->setVisible(true);
	//-------------------------------------------------------------
	for (register int i = 0; i < 10; i++)
	{
		m_rocks.push_back(new Rock(this));
	}
	//-------------------------------------------------------------
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	//-------------------------------------------------------------
	count = 0;
	scheduleUpdate();
	//-------------------------------------------------------------
	return true;
}

void GamePlayScene::update(float dt)
{
	if (!m_spaceShip->getSprite()->isVisible())
	{
		Director::getInstance()->getRunningScene()->pause();
		Director::getInstance()->replaceScene(TransitionCrossFade::create(2.0f, GameOverScene::createScene()));
	}
	if (count == 10)
	{
		generateRock();
		score++;
		count = 0;
	}
	else {
		count++;
	}
	for (register int i = 0; i < m_rocks.size(); i++)
	{
		if (m_rocks[i]->getSprite()->isVisible())
		{
			m_rocks[i]->Update(dt);
		}
	}
	m_spaceShip->Update(dt);
	string labelText = "Your Score: ";
	labelText += to_string(score);
	m_lbScore->setString(labelText);
	m_spaceShip->Collision(m_rocks);
}

void GamePlayScene::generateRock()
{
	Size vs = Director::getInstance()->getVisibleSize();
	int maxWidth = vs.width;
	for (register int i = 0; i < m_rocks.size(); i++)
	{
		if (!m_rocks[i]->getSprite()->isVisible())
		{
			m_rocks[i]->getSprite()->setVisible(true);
			m_rocks[i]->getSprite()->setPosition(Vec2(random(0, maxWidth), vs.height + 50));
			m_rocks[i]->getSprite()->setScale(random(1, 2)*(3/2));
			m_rocks[i]->getSprite()->setRotation(random(0, 90));
			break;
		}
	}
}

bool GamePlayScene::onTouchBegan(cocos2d::Touch * t, cocos2d::Event * e)
{
	//m_spaceShip->getSprite()->setPosition(t->getLocation());
	if (m_spaceShip->getSprite()->getBoundingBox().containsPoint(t->getLocation()))
	{
		return true;
	}
	return false;
}

bool GamePlayScene::onTouchEnded(cocos2d::Touch *, cocos2d::Event *)
{
	return false;
}

void GamePlayScene::onTouchMoved(cocos2d::Touch * t, cocos2d::Event * e)
{
	Size vs = Director::getInstance()->getVisibleSize();
	if (t->getLocation().x < vs.width && t->getLocation().x > 0)
	{
		if (t->getLocation().y < vs.height && t->getLocation().y > 0)
		{
			m_spaceShip->getSprite()->setPosition(t->getLocation());
		}
	}
}

int GamePlayScene::getScore()
{
	return this->score;
}

void GamePlayScene::setScore(int score)
{
	this->score += score;
}
