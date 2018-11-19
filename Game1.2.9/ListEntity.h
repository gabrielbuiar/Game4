#pragma once
#include "ListT.h"
#include "Character.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Platform.h"
#include "Player.h"
#include "Background.h"
#include <fstream>

class ListEntity
{
public:
	ListEntity();
	~ListEntity();
	void include(Character& character) { Entities.include(static_cast<Entity*> (&character)); }
	void include(Enemy& enemy) { Entities.include(static_cast<Entity*> (&enemy)); }
	void include(Obstacle& obstacle) { Entities.include(static_cast<Entity*> (&obstacle)); }
	void include(Platform& platform) { Entities.include(static_cast<Entity*> (&platform)); }
	void include(Background& background) { Entities.include(static_cast<Entity*> (&background)); }
	void includePlayer(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	void includePlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	void Draw(sf::RenderWindow* window);
	void Update(const float daltaTime);
	void move(sf::Vector2f position, float speed);
	void CheckCollision(Character* other, const float push);
	ListT<Entity*>::Element<Entity*>* getFirst() { return Entities.getpFirst(); }
	void save();

private:
	ListT<Entity*> Entities;

};