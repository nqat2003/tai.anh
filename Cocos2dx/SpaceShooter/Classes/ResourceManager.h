#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <iostream>
class ResourceManager
{
private:
	ResourceManager* s_instance;
	std::string m_dataFolderPath;
	std::map<char, cocos2d::Sprite*> m_sprites;
	std::map<char, cocos2d::ui::Button*> m_buttons;
	std::map<char, cocos2d::Label*> m_labels;
public:
	ResourceManager();
	~ResourceManager();
	ResourceManager GetInstance();
	void Init(const std::string);
	void Load(std::string);
	cocos2d::Sprite* GetSpriteById(char);
	cocos2d::ui::Button* GetButtonById(char);
	cocos2d::Label* GetLabelById(char);
};