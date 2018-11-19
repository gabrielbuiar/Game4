#pragma once
#include"Obstacle1.h"
#include"ListT.h"

class ListObstacles
{
public:
	ListObstacles();
	~ListObstacles();
	void include(Obstacle* obstacle) { if (obstacle  != NULL) obstacles.include(obstacle); }
	void include(Obstacle1* obstacle) { if (obstacle != NULL) obstacles1.include(obstacle); }
	void draw(sf::RenderWindow* window);
	void update(const float deltaTime);
	void checkCollision(Character* other, const float push);
	void checkCollision(Entity* other, const float push);
	ListT<Obstacle*>::Element<Obstacle*>* getFirst1() { return obstacles.getpFirst(); }
	ListT<Obstacle1*>::Element<Obstacle1*>* getFirst2() { return obstacles1.getpFirst(); }
	void save();

private:
	ListT<Obstacle*> obstacles;
	ListT<Obstacle1*> obstacles1;

};