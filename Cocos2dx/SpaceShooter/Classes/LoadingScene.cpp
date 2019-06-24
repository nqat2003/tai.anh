#include "LoadingScene.h"

Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 or = Director::getInstance()->getVisibleOrigin();
	auto background = ResourceManager::GetInstance()->GetSpriteById(0);
	background->removeFromParent();
	background->setAnchorPoint(Vec2(0,0));
	background->setScale(vs.width / background->getContentSize().width, vs.height / background->getContentSize().width);
	addChild(background, -999);
	auto loadingLabel = ResourceManager::GetInstance()->GetLabelById(0);
	loadingLabel->setString("Loading...");
	loadingLabel->setPosition(Vec2(vs.width / 2, vs.height / 2));
	addChild(loadingLabel, 0);
	return true;
}

void LoadingScene::update(float)
{
}
