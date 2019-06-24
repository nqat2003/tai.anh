#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "Rock.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace cocos2d;
class SpaceShooter : public Objectt
{
private:
	list<Object*> m_bullets;
public:
	SpaceShooter(Scene*);
	~SpaceShooter();
	void Init();
	void Update(float);
	void Shoot();
	void Collision(vector<Rock*>);
};
