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
	return true;
}

void GamePlayScene::update(float)
{
}

bool GamePlayScene::onTouchBegan(cocos2d::Touch *, cocos2d::Event *)
{
	return false;
}

bool GamePlayScene::onTouchEnded(cocos2d::Touch *, cocos2d::Event *)
{
	return false;
}

void GamePlayScene::onTouchMoved(cocos2d::Touch *, cocos2d::Event *)
{
}
