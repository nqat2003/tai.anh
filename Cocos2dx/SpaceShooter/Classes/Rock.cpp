#include "Rock.h"

Rock::Rock(cocos2d::Scene * scene)
{
	Init();
	m_sprite->removeFromParent();
	scene->addChild(m_sprite, 1);
}

Rock::~Rock()
{
}

void Rock::Init()
{
	m_sprite = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById(3));
	destroy = ResourceManager::GetInstance()->DuplicateSprite(ResourceManager::GetInstance()->GetSpriteAnimeById(1));
}

void Rock::Update(float dt)
{
	this->m_sprite->setPositionY(m_sprite->getPositionY() - 5);
	if (this->m_sprite->getPositionY() < 0)
	{
		this->m_sprite->setVisible(false);
	}
}

void Rock::Destroy()
{
	destroy->removeFromParent();
	destroy->setPosition(m_sprite->getPosition());
}
