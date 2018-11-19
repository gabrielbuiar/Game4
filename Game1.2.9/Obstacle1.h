#pragma once
#include "Obstacle.h"
#include "Character.h"
#include "ListT.h"
#include <vector>

class Obstacle1 :
	public Obstacle
{
public:
	Obstacle1();
	~Obstacle1();
	void Update(const float deltaTime);
	void draw(sf::RenderWindow& window);
	bool bulletCheckCollision(Entity& other, sf::RectangleShape paux);
	bool bulletCheckCollision(Character & other, sf::RectangleShape paux);
	bool checkCollision(Character& other, sf::Vector2f& direction, float push);
	bool checkCollision(Entity& other, sf::Vector2f& direction, float push);
	void setBulletDamage(const float damage) { bulletDamage = damage; }
	void setBulletSpeed(const float speed) { bulletSpeed = speed; }
	void save(std::ofstream& Save) {
		Save << id << ' ' << base.getPosition().x << ' ' << base.getPosition().y << ' ' << base.getSize().x << ' ' << base.getSize().y << ' ' << bulletSpeed << ' ' << bulletDamage << ' ' << std::endl;
	}

private:
	float activatedTime = 2.f;
	float notActivatedTime = 2.f;
	float totalTime = 0.f;
	float bulletSpeed;
	float bulletDamage;
	int delay = 0;
	bool activated = true;
	//ListT<sf::RectangleShape*> bullets;
	std::vector<sf::RectangleShape*> bullets;

};