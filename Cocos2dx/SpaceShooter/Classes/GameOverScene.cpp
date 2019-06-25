#include "GameOverScene.h"

cocos2d::Scene * GameOverScene::createScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
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
	m_gameOver = ResourceManager::GetInstance()->GetLabelById(1);
	m_gameOver->setString("GAME OVER");
	m_gameOver->setScale(1.5f);
	m_gameOver->setPosition(Vec2(vs.width / 2, vs.height / 2 + 150));
	m_gameOver->enableOutline(Color4B::MAGENTA, 2);
	m_gameOver->enableShadow();
	m_gameOver->removeFromParent();
	addChild(m_gameOver, 0);
	//-------------------------------------------------------------
	m_score = ResourceManager::GetInstance()->GetLabelById(0);
	m_score->setString("Your score: 3");
	m_score->setPosition(Vec2(vs.width / 2, vs.height / 2 + 70));
	m_score->removeFromParent();
	addChild(m_score, 0);
	//-------------------------------------------------------------
	m_btnAgain = ResourceManager::GetInstance()->GetButtonById(1);
	m_btnAgain->setPosition(Vec2(vs.width / 3, vs.height / 3));
	m_btnAgain->setScale(0.69999998f);
	m_btnAgain->removeFromParent();
	addChild(m_btnAgain, 0);
	m_btnAgain->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(1, GamePlayScene::createScene(), Color3B(0, 0, 0)));
			break;
		default:
			break;
		}
	});
	//-------------------------------------------------------------
	m_btnHome = ResourceManager::GetInstance()->GetButtonById(2);
	m_btnHome->setPosition(Vec2(vs.width * 2 / 3, vs.height / 3));
	m_btnHome->removeFromParent();
	addChild(m_btnHome);
	m_btnHome->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(1, MainMenuScene::createScene(), Color3B(0, 0, 0)));
			break;
		default:
			break;
		}
	});
	return true;
}
