#include "Bullet.h"

Bullet::Bullet(cocos2d::Scene * scene)
{
	Init();
	m_sprite->removeFromParent();
	scene->addChild(m_sprite, 1);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	m_sprite = ResourceManager::GetInstance()->GetSpriteById(2);

}

void Bullet::Update(float dt)
{
	Size vs = Director::getInstance()->getVisibleSize();
	auto mv = MoveBy::create(1.5, Vec2(m_sprite->getPositionX(), vs.height + 100));
	auto sq = Sequence::create(mv, nullptr);
	m_sprite->runAction(sq);
	if (m_sprite->getPositionY() > vs.height)
	{
		m_sprite->setVisible(false);
	}
}
