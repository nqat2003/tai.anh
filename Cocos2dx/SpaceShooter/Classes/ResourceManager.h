#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <iostream>
#include <fstream>
#include <ui/CocosGUI.h>
using namespace std;
using namespace cocos2d;
class ResourceManager
{
private:
	ResourceManager* s_instance;
	string m_dataFolderPath;
	map<char, Sprite*> m_sprites;
	map<char, ui::Button*> m_buttons;
	map<char, Label*> m_labels;
public:
	ResourceManager();
	~ResourceManager();
	ResourceManager GetInstance();
	void Init(const string);
	void Load(string);
	Sprite* GetSpriteById(char);
	ui::Button* GetButtonById(char);
	Label* GetLabelById(char);
};