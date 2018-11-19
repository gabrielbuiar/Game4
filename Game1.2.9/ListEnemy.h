#pragma once
#include"Enemy.h"
#include"Enemy1.h"
#include"Enemy2.h"
#include"ListT.h"
#include"Player.h"
#include<SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class ListEnemy
{
public:
	ListEnemy();
	~ListEnemy();
	void include (Enemy1* enemy) { if (enemy != NULL) enemies1.include(enemy); }
	void include(Enemy2* enemy) { if (enemy != NULL) enemies2.include(enemy); }
	void draw(sf::RenderWindow* window);
	void update(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	void update(const float deltaTime, sf::Vector2f position1);
	void checkCollision(Player* other, const float push);
	ListT<Enemy1*>::Element<Enemy1*>* getFirst1() { return enemies1.getpFirst(); }
	ListT<Enemy2*>::Element<Enemy2*>* getFirst2() { return enemies2.getpFirst(); }
	void save();

private:
	ListT<Enemy1*> enemies1;
	ListT<Enemy2*> enemies2;

};
