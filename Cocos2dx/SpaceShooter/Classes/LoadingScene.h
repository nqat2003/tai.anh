#pragma once
#include "cocos2d.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"
using namespace std;
using namespace cocos2d;
class LoadingScene : public cocos2d::Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LoadingScene);
	void update(float) override;
private:
	int loadingPercent;
	Sprite* background;
	Label* loadingLabel;
	Sprite* loadingBarBG;
	Sprite* loadingBarProgress;
};