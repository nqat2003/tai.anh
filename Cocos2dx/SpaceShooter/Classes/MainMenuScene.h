#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ResourceManager.h"
using namespace std;
using namespace cocos2d;
class MainMenuScene : public cocos2d::Scene
{
private:
	Sprite* m_background;
	Sprite* m_logo;
	ui::Button* m_start;
public:
	static Scene* createScene();
	virtual bool init() override; 
	CREATE_FUNC(MainMenuScene);
};