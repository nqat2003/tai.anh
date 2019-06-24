#pragma once
#include "cocos2d.h"
#include "Object.h"
class Bullet : public Object
{
public:
	Bullet(cocos2d::Scene*);
	~Bullet();
	void Init();
	void Update(float);
};