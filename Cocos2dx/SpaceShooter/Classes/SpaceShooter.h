#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "Rock.h"
#include "Bullet.h"
#include "GameOverScene.h"
#include <vector>
#include <iostream>
#define BULLET_N 20
using namespace std;
using namespace cocos2d;
class SpaceShooter : public Objectt
{
private:
	vector<Objectt*> m_bullets;
	int count;
public:
	SpaceShooter(Scene*);
	~SpaceShooter();
	void Init();
	void Update(float);
	void Shoot();
	void Collision(vector<Rock*>);
};
