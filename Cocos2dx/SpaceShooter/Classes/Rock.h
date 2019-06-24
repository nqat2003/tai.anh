#pragma once
#include "cocos2d.h"
#include "Object.h"
class Rock : public Object
{
public:
	Rock(cocos2d::Scene*);
	~Rock();
	void Init();
	void Update(float);
};