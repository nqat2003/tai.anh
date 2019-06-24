#pragma once
#include "cocos2d.h"
#include "Rock.h"
#include "SpaceShooter.h"
#include <iostream>
#include <vector>
class GamePlayScene : public cocos2d::Scene
{
private:
	std::vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
public:
	cocos2d::Scene* createScene();
	virtual bool Init();
	void update(float);
	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	bool onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
};