#include "SpaceShooter.h"

SpaceShooter::SpaceShooter(cocos2d::Scene * scene)
{
	Size vs = Director::getInstance()->getVisibleSize();
	Init();
	m_sprite->setPosition(Vec2(vs.width / 2, vs.height / 2));
	m_sprite->removeFromParent();
	m_sprite->runAction(MoveTo::create(1, Vec2(vs.width /2, 70)));
	scene->addChild(m_sprite, 1);
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
}

void SpaceShooter::Update(float)
{
}

void SpaceShooter::Shoot()
{
}

void SpaceShooter::Collision(std::vector<Rock*>)
{
}
