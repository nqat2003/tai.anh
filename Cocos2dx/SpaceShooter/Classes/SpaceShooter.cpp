#include "SpaceShooter.h"
#include "GamePlayScene.h"
SpaceShooter::SpaceShooter(cocos2d::Scene * scene)
{
	audio = SimpleAudioEngine::getInstance();
	Size vs = Director::getInstance()->getVisibleSize();
	Init();
	m_sprite->setPosition(Vec2(vs.width / 2, vs.height / 2));
	//m_sprite->setAnchorPoint(Vec2(0.5f,0.5f));
	m_sprite->removeFromParent();
	m_sprite->runAction(MoveTo::create(1, Vec2(vs.width /2, 70)));
	scene->addChild(m_sprite, 1);
	for (register int i = 0; i < BULLET_N; i++)
	{
		m_bullets.push_back(new Bullet(scene));
	}
	this->scene = scene;
	count = 0;
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	this->m_sprite = ResourceManager::GetInstance()->GetAnimateById(0);
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
			if (rocks[j]->getSprite()->isVisible())
			{
				Rect bullet = m_bullets[i]->getSprite()->getBoundingBox();
				Rect rock = rocks[j]->getSprite()->getBoundingBox();
				//Check collision between bullet and rock
				if (bullet.intersectsRect(rock))
				{
					auto *expl = ParticleSystemQuad::create("MeteorExplosion.plist");
					expl->setVisible(true);
					expl->setPosition(rocks[j]->getSprite()->getPosition());
					scene->addChild(expl);
					audio->playEffect("explosion_asteroid.wav", false);
					audio->setEffectsVolume(1.0f);
					rocks[j]->getSprite()->setVisible(false);
				}
				Rect plane = m_sprite->getBoundingBox();
				//Check collision between rock and spaceship
				if (plane.intersectsRect(rock))
				{
					auto *expl = ParticleSystemQuad::create("PlayerShipExplosion.plist");
					expl->setVisible(true);
					expl->setPosition(m_sprite->getPosition());
					scene->addChild(expl);
					m_sprite->setVisible(false);
					i = j = 5000;
				}
				//Check collision with distance formula
				//float xA = m_sprite->getPositionX();
				//float xB = m_sprite->getPositionY();
				//float yA = rocks[j]->getSprite()->getPositionX();
				//float yB = rocks[j]->getSprite()->getPositionY();
				//float rA = m_sprite->getContentSize().width / 2;
				//float rB = rocks[j]->getSprite()->getContentSize().width / 2;
				//bool check_space_collision = ((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB)) < ((rA + rB)*(rA + rB));
				//if (check_space_collision)
				//{
				//	m_sprite->setVisible(false);
				//	//Exit loop
				//	i = j = 50000;
				//}
			}
		}
	}
}
