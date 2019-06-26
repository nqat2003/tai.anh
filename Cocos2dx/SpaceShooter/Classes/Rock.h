#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "ResourceManager.h"
using namespace std;
using namespace cocos2d;
class Rock : public Objectt
{
private:
	Sprite* destroy;
public:
	Rock(Scene*);
	~Rock();
	void Init();
	void Update(float);
	void Destroy();
};