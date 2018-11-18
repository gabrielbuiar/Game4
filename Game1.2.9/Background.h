#pragma once
#include "Entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Background :
	public Entity
{
public:
	Background(const char* textureFile = NULL, const float increment = 0, const float incrementScale = 0);
	~Background();
	void Initialize(sf::Vector2f position, sf::Vector2f size, const char* textureFile, const float increment, const float incrementScale);
	void Draw(sf::RenderWindow* window) { window->draw(back); }
	void setTexture(const char* textureFile);
	void move(sf::Vector2f playerPosition, float speed);
	bool checkCollision(Entity& other, sf::Vector2f& direction, float push) { return false; }
	void Stand() { stand = true; }
	void save(std::ofstream& Save) { Save << id << ' ' << position.x << ' ' << position.y << ' ' << size.x << ' ' << size.y<< ' ' << textureFile << ' ' << increment0 << ' ' << incrementScale0 << std::endl; }

private:
	float increment;
	float incrementScale;
	float inc;
	sf::Sprite back;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Vector2f iposition;
	bool stand = false;
	float increment0;
	float incrementScale0;

};