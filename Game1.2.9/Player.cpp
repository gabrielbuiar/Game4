#include "Player.h"



Player::Player(const char* textureFile, float speed, float jumpHeight)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	sf::Vector2u imgCount;
	imgCount.x = 0;
	imgCount.y = 0;

	//	InitializePlayer(position, size, textureFile, imgCount, speed, jumpHeight);
}


Player::~Player()
{
}

void Player::InitializePlayer(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
	//lifei = life;
}

void Player::calcMovement(const float deltaTime)
{
	{
		velocity.x = 0.0f;

		if (sf::Keyboard::isKeyPressed(KeyLeft))
			velocity.x -= speed;
		if (sf::Keyboard::isKeyPressed(KeyRight))
			velocity.x += speed;
		if (sf::Keyboard::isKeyPressed(KeyJump) && canJump)
		{
			canJump = false;
			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}

		velocity.y += 981.0f * deltaTime;

		if (velocity.x == 0)
		{
			row = 0;
			if (velocity.y < -1.0f)
				row = 2;
		}
		else
		{
			row = 1;

			if (velocity.y < -1.0f)
				row = 2;

			if (velocity.x > 0)
				faceRight = true;
			else
				faceRight = false;
		}

		Attacking = false;

		if (sf::Keyboard::isKeyPressed(KeyAttack))
		{
			row = 3;
			Attacking = true;
		}
	}
}

void Player::draw(sf::RenderWindow & window)
{
	if (!dead)
		window.draw(base);

	sf::VertexArray quad(sf::Quads, 4);

	if (!player2)
	{
		quad[0].position = sf::Vector2f(window.getView().getCenter().x - (window.getView().getSize().x / 2.f) + (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
		quad[1].position = sf::Vector2f(window.getView().getCenter().x - (window.getView().getSize().x / 2.f) + (350 * LifePct * window.getSize().x / 1920) + (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
		quad[2].position = sf::Vector2f(window.getView().getCenter().x - (window.getView().getSize().x / 2.f) + (350 * LifePct * window.getSize().x / 1920) + (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);
		quad[3].position = sf::Vector2f(window.getView().getCenter().x - (window.getView().getSize().x / 2.f) + (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);
	}

	else
	{
		quad[0].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
		quad[1].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (350 * LifePct* window.getSize().x / 1920) - (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
		quad[2].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (350 * LifePct* window.getSize().x / 1920) - (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);
		quad[3].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (50 * window.getSize().x / 1920), window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);
	}

	quad[0].color = sf::Color::Red;
	quad[2].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast <sf::Uint8> (255 * LifePct), 0, 255);
	quad[1].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast <sf::Uint8> (255 * LifePct), 0, 255);
	quad[3].color = sf::Color::Red;


	window.draw(quad);

	sf::Font font;
	sf::Text text;
	font.loadFromFile("Textures/whitrabt.ttf");
	std::string s = std::to_string(points);
	text.setString(s);
	text.setFont(font);

	if (!player2)
		text.setPosition(window.getView().getCenter().x - (window.getView().getSize().x / 2.f) + (50 * window.getSize().x / 1920), (30 * window.getSize().y / 1080));
	else
		text.setPosition(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (150 * window.getSize().x / 1920), (30 * window.getSize().y / 1080));

	window.draw(text);

}

