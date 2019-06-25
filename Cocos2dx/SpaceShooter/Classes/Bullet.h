#pragma once
#include "cocos2d.h"
#include "Object.h"
#include "ResourceManager.h"
using namespace std;
using namespace cocos2d;
class Bullet : public Objectt
{
public:
	Bullet(Scene*);
	~Bullet();
	void Init();
	void Update(float);
};