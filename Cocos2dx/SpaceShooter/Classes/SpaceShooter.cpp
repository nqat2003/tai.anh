#include "SpaceShooter.h"
#include "GamePlayScene.h"

SpaceShooter::SpaceShooter(cocos2d::Scene * scene)
{
	Size vs = Director::getInstance()->getVisibleSize();
	Init();
	m_sprite->setPosition(Vec2(vs.width / 2, vs.height / 2));
	m_sprite->setAnchorPoint(Vec2(0.5f,0.5f));
	m_sprite->removeFromParent();
	m_sprite->runAction(MoveTo::create(1, Vec2(vs.width /2, 70)));
	scene->addChild(m_sprite, 1);
	for (register int i = 0; i < BULLET_N; i++)
	{
		m_bullets.push_back(new Bullet(scene));
	}
	count = 0;
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	m_sprite = ResourceManager::GetInstance()->GetSpriteById(4);
}

void SpaceShooter::Update(float dt)
{
	if (count == 10)
	{
		Shoot();
		count = 0;
	}
	else {
		count++;
	}
	for (register int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->getSprite()->isVisible())
		{
			m_bullets[i]->Update(dt);
		}
	}
}

void SpaceShooter::Shoot()
{
	for (register int i = 0; i < m_bullets.size(); i++)
	{
		if (!m_bullets[i]->getSprite()->isVisible())
		{
			m_bullets[i]->getSprite()->setVisible(true);
			m_bullets[i]->getSprite()->setPosition(Vec2(m_sprite->getPositionX(), m_sprite->getPositionY()));
			break;
		}
	}
}

void SpaceShooter::Collision(vector<Rock*> rocks)
{
	for (register int i = 0; i < m_bullets.size(); i++)
	{
		for (register int j = 0; j < rocks.size(); j++)
		{
			Rect bullet = m_bullets[i]->getSprite()->getBoundingBox();
			Rect rock = rocks[j]->getSprite()->getBoundingBox();
			//Check collision between bullet and rock
			if (bullet.intersectsRect(rock) && rocks[j]->getSprite()->isVisible())
			{
				rocks[j]->getSprite()->setVisible(false);
			}
			Rect plane = m_sprite->getBoundingBox();
			//Check collision between rock and spaceship
			if (plane.intersectsRect(rock) && rocks[j]->getSprite()->isVisible())
			{
				m_sprite->setVisible(false);
				i = j = 5000;
			}
			//Check collision with distance formula
			//int xA = m_sprite->getPositionX();
			//int xB = m_sprite->getPositionY();
			//int yA = rocks[j]->getSprite()->getPositionX();
			//int yB = rocks[j]->getSprite()->getPositionY();
			//int rA = m_sprite->getContentSize().width / 2;
			//int rB = rocks[j]->getSprite()->getContentSize().width / 2;
			//bool check_space_collision = ((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB)) < ((rA + rB)*(rA + rB));
			//if (check_space_collision)
			//{
			//	//log("collision");
			//	if (rocks[j]->getSprite()->isVisible())
			//	{
			//		m_sprite->setVisible(false);
			//	}
			//	
			//	i = j = 50000;
			//}
		}
	}
}
