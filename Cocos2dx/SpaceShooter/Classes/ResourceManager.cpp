#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager ResourceManager::GetInstance()
{
	return ResourceManager();
}

void ResourceManager::Init(const string path)
{
	m_dataFolderPath = path;
}

void ResourceManager::Load(string fileName)
{
	ifstream f;
	f.open(fileName);
	string off;
	int i;
	f >> off;
	f >> i;
	cout << i << endl;
	for (register int s = 0; s < i; s++)
	{
		char index;
		string pathSprite;
		f >> off;
		f >> index;
		f >> off;
		f >> pathSprite;
		pathSprite.replace(pathSprite.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		m_sprites.insert(pair<char,Sprite*>(index, Sprite::create(pathSprite)));
	}
	f >> off;
	f >> i;
	for (register int b = 0; b < i; b++)
	{
		char index;
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
		m_buttons.insert(pair<char, ui::Button*>(index, ui::Button::create(pathButtonNormal, pathButtonPressed)));
	}
	f >> off;
	f >> i;
	for (register int l = 0; l < i; l++)
	{
		char index;
		string pathFont;
		f >> off;
		f >> index;
		f >> off;
		f >> pathFont;
		pathFont.replace(pathFont.find("%s"), sizeof("%s") - 1, m_dataFolderPath);
		m_labels.insert(pair<char, Label*>(index, Label::createWithTTF(pathFont, "")));
	}
	f.close();
}

Sprite * ResourceManager::GetSpriteById(char id)
{
	return nullptr;
}

ui::Button * ResourceManager::GetButtonById(char id)
{
	return nullptr;
}

Label * ResourceManager::GetLabelById(char id)
{
	return nullptr;
}
