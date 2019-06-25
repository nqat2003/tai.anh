#pragma once
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
class MainMenuScene : public cocos2d::Scene
{
public:
	static Scene* createScene();
	virtual bool Init();
};