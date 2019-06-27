#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
Scene * MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
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
	m_logo = ResourceManager::GetInstance()->GetSpriteById(1);
	m_logo->setPosition(vs.width / 2, vs.height / 2 + 200);
	addChild(m_logo, 2);
	//-------------------------------------------------------------
	m_start = ResourceManager::GetInstance()->GetButtonById(0);
	m_start->setPosition(Vec2(vs.width / 2, vs.height / 2));
	
	//-------------------------------------------------------------
	m_start->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			//label->setVisible(true);
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto audio = SimpleAudioEngine::getInstance();
			audio->playEffect("confirm.wav", false);
			Director::getInstance()->replaceScene(TransitionFade::create(1, GamePlayScene::createScene(), Color3B(0, 0, 0)));
			break;
		
		}
	});
	addChild(m_start, 2);
	return true;
}
