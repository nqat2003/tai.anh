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
		m_sprites.insert(pair<int,Sprite*>(index, Sprite::create(pathSprite)));
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
		m_labels.insert(pair<int, Label*>(index, lb));
	}
	f.close();
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	m_sprites[id]->retain();
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
