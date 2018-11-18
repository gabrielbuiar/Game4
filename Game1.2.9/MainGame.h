#pragma once
#include "Level.h"
#include "LevelBuilder1.h"
#include "Menu.h"

class MainGame
{
public:
	MainGame();
	~MainGame();
	void Execute();
	//void InitializePlayers();
	//void InitializePlatforms();
	void createLevel_1_1(LevelBuilder& builder);
	void createLevel_1_2(LevelBuilder& builder);
	Level* load();

private:
	const float WINDOW_HEIGHT = 1080.f;
	const float WINDOW_WIDHT = 1920.f;
	LevelBuilder1 builder1;
	Menu* menu;

};
