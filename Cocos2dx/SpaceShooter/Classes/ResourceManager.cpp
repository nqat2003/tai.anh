#include "ResourceManager.h"

ResourceManager *ResourceManager::s_instance = nullptr;
ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
	if (!s_instance)
	{
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::Init(const string path)
{
	m_dataFolderPath = path;
	Load("res/Data.bin");
}

void ResourceManager::Load(string fileName)
{
	ifstream f;
	f.open(fileName);
	string off;
	int i;
	f >> off;
	f >> i;
	for (register int s = 0; s < i; s++)
	{
		int index;
		string pathSprite;
		f >> off;
		f >> index;
		f >> off;
		f >> pathSprite;
		pathSprite.replace(0, 2, m_dataFolderPath);
		auto pinfo = AutoPolygon::generatePolygon(pathSprite);
		auto sp = Sprite::create(pinfo);
		sp->retain();
		m_sprites.insert(pair<int,Sprite*>(index, sp));
	}
	f >> off;
	f >> i;
	for (register int b = 0; b < i; b++)
	{
		int index;
		string pathButtonNormal;
		string pathButtonPressed;
		f >> off;
		f >> index;
		f >> off;
		f >> pathButtonNormal;
		f >> off;
		f >> pathButtonPressed;
		pathButtonNormal.replace(pathButtonNormal.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		pathButtonPressed.replace(pathButtonPressed.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		ui::Button *bt = ui::Button::create(pathButtonNormal, pathButtonPressed);
		bt->retain();
		m_buttons.insert(pair<int, ui::Button*>(index, bt));
	}
	f >> off;
	f >> i;
	for (register int l = 0; l < i; l++)
	{
		int index;
		string pathFont;
		f >> off;
		f >> index;
		f >> off;
		f >> pathFont;
		pathFont.replace(pathFont.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		Label *lb = Label::createWithTTF("", pathFont, 30);
		lb->retain();
		m_labels.insert(pair<int, Label*>(index, lb));
	}
	f >> off;
	f >> i;
	for (register int a = 0; a < i; a++)
	{
		int index;
		string pathAni;
		f >> off;
		f >> index;
		f >> off;
		f >> pathAni;
		pathAni.replace(pathAni.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		auto sp = Sprite::create(pathAni);
		Vector<SpriteFrame*> animateFrames;
		//animateFrames.reserve(4);
		for (register int i = 0; i < 4; i++)
		{
			animateFrames.pushBack(SpriteFrame::create(pathAni, Rect(115 * i, 0, 115, 107)));
		}
		Animation* animation = Animation::createWithSpriteFrames(animateFrames, 0.2f);
		Animate* animate = Animate::create(animation);
		sp->runAction(RepeatForever::create(animate));
		sp->retain();
		m_animate.insert(pair<int, Sprite*>(index, sp));
	}
	f.close();
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	return m_sprites[id];
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	return m_buttons.at(id);
}

Label * ResourceManager::GetLabelById(int id)
{
	return m_labels.at(id);
}

Sprite * ResourceManager::DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}

Sprite * ResourceManager::GetAnimateById(int id)
{
	return m_animate[id];
}
