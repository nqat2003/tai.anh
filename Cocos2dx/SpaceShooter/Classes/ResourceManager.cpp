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

void ResourceManager::Init(const std::string)
{
}

void ResourceManager::Load(std::string)
{
}

cocos2d::Sprite * ResourceManager::GetSpriteById(char)
{
	return nullptr;
}

cocos2d::ui::Button * ResourceManager::GetButtonById(char)
{
	return nullptr;
}

cocos2d::Label * ResourceManager::GetLabelById(char)
{
	return nullptr;
}
