#pragma once
#include "cocos2d.h"
#include "Rock.h"
#include "SpaceShooter.h"
#include "ResourceManager.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace cocos2d;
class GamePlayScene : public cocos2d::Scene
{
private:
	vector<Rock*> m_rocks;
	SpaceShooter* m_spaceShip;
	Sprite* m_background;
	Label* m_lbScore;
	int score;
	int count;
public:
	
	static Scene* createScene();
	virtual bool init();
	void update(float);
	CREATE_FUNC(GamePlayScene);
	void generateRock();
	bool onTouchBegan(Touch*, Event*);
	bool onTouchEnded(Touch*, Event*);
	void onTouchMoved(Touch*, Event*);
	int getScore();
	void setScore(int);
};