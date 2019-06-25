#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"
using namespace std;
using namespace cocos2d;
class GameOverScene : public cocos2d::Scene
{
private:
	Label* m_gameOver, *m_score;
	ui::Button* m_btnAgain, *m_btnHome;
	Sprite* m_background;
public:
	static Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(GameOverScene);
};