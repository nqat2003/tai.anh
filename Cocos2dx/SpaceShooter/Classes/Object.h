#pragma once
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
class Objectt
{
private:
	Sprite m_sprite;
public:
	Objectt();
	~Objectt();
	virtual void Init() = 0;
	virtual void Update(float) = 0;
};