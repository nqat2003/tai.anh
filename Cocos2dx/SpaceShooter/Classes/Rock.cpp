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
}

void Rock::Update(float dt)
{
	Size vs = Director::getInstance()->getVisibleSize();
	auto mv = MoveTo::create(1.5, Vec2(vs.width / 2, 0));
	auto sq = Sequence::create(mv, nullptr);
	m_sprite->runAction(sq);
	log("Dropped");
	if (m_sprite->getPositionY() < 0)
	{
		m_sprite->setVisible(false);
	}
}
