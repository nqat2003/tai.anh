#pragma once
#include "cocos2d.h"
class Object
{
private:
	cocos2d::Sprite m_sprite;
public:
	Object();
	~Object();
	virtual void Init() = 0;
	virtual void Update(float) = 0;
};