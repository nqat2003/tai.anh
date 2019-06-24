#pragma once
#include "cocos2d.h"
#include "Rock.h"
#include "SpaceShooter.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace cocos2d;
class GamePlayScene : public cocos2d::Scene
{
private:
	vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
public:
	Scene* createScene();
	virtual bool Init();
	void update(float);
	bool onTouchBegan(Touch*, Event*);
	bool onTouchEnded(Touch*, Event*);
	void onTouchMoved(Touch*, Event*);
};