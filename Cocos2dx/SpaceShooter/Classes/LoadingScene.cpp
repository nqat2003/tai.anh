#include "LoadingScene.h"

Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 or = Director::getInstance()->getVisibleOrigin();
	//-------------------------------------------------------------
	background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->removeFromParent();
	background->setAnchorPoint(Vec2(0,0));
	background->setScale(vs.width / background->getContentSize().width, vs.height / background->getContentSize().width);
	addChild(background, -999);
	//-------------------------------------------------------------
	loadingLabel = ResourceManager::GetInstance()->GetLabelById(0);
	loadingLabel->setString("Loading...");
	loadingLabel->setPosition(Vec2(vs.width / 2, vs.height / 2));
	addChild(loadingLabel, 0);
	//-------------------------------------------------------------
	loadingBarBG = ResourceManager::GetInstance()->GetSpriteById(5);
	loadingBarBG->setPosition(Vec2(vs.width / 4, vs.height / 2 - 50));
	loadingBarBG->setAnchorPoint(Vec2(0, 0.5f));
	//loadingBarBG->setScaleX(0.95f);
	addChild(loadingBarBG, 2);
	//-------------------------------------------------------------
	loadingBarProgress = ResourceManager::GetInstance()->GetSpriteById(6);
	loadingBarProgress->setPosition(Vec2(vs.width / 4, vs.height / 2 - 50));
	loadingBarProgress->setAnchorPoint(Vec2(0, 0.5f));
	loadingBarProgress->setScaleX(0.1f);
	addChild(loadingBarProgress, 1);
	auto sb = ScaleBy::create(3, 10.0f, 1);
	loadingBarProgress->runAction(sb);
	//-------------------------------------------------------------
	loadingPercent = 0;
	//-------------------------------------------------------------
	scheduleUpdate();
	return true;
}

void LoadingScene::update(float dt)
{
	loadingPercent += 1;
	if (loadingPercent == 180)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1, MainMenuScene::createScene(), Color3B(0, 0, 0)));
	}
}
