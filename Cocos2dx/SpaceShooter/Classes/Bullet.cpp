#include "Bullet.h"

Bullet::Bullet(cocos2d::Scene * scene)
{
	Init();
	m_sprite->removeFromParent();
	scene->addChild(m_sprite, 0);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(2));

}

void Bullet::Update(float dt)
{
	Size vs = Director::getInstance()->getVisibleSize();
	this->m_sprite->setPositionY(m_sprite->getPositionY() + 10);
	if (m_sprite->getPositionY() > vs.height)
	{
		m_sprite->setVisible(false);
	}
}
