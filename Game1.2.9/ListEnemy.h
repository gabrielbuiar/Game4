#pragma once
#include"Enemy.h"
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
	void include(Enemy* player);
	void draw(sf::RenderWindow* window);
	void update(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	void update(const float deltaTime, sf::Vector2f position1);
	void checkCollision(Player* other, const float push);
	ListT<Enemy*>::Element<Enemy*>* getFirst() { return enemies.getpFirst(); }
	void save();

private:
	ListT<Enemy*> enemies;

};
