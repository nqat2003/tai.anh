#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "Rock.h"
#include <vector>
#include <iostream>
class SpaceShooter : public Object
{
private:
	std::list<Object*> m_bullets;
public:
	SpaceShooter(cocos2d::Scene*);
	~SpaceShooter();
	void Init();
	void Update(float);
	void Shoot();
	void Collision(std::vector<Rock*>);
};
