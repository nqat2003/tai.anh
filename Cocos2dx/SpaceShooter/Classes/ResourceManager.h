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
	static ResourceManager* s_instance;
	string m_dataFolderPath;
	map<int, Sprite*> m_sprites;
	map<int, ui::Button*> m_buttons;
	map<int, Label*> m_labels;
	map<int, Sprite*> m_animate;
public:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* GetInstance();
	void Init(const string);
	void Load(string);
	Sprite* GetSpriteById(int);
	ui::Button* GetButtonById(int);
	Label* GetLabelById(int);
	Sprite * DuplicateSprite(Sprite*);
	Sprite * GetAnimateById(int);
};