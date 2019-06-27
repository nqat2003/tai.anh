#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "Rock.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

#include "SimpleAudioEngine.h"
#define BULLET_N 20
using namespace CocosDenshion;
using namespace std;
using namespace cocos2d;
class SpaceShooter : public Objectt
{
private:
	vector<Objectt*> m_bullets;
	int count;
	Scene* scene;
	SimpleAudioEngine *audio;
public:
	SpaceShooter(Scene*);
	~SpaceShooter();
	void Init();
	void Update(float);
	void Shoot();
	void Collision(vector<Rock*>);
};
