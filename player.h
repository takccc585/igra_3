#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <iostream>

class Player {
private:
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Mouse mouse;
	float angle;
	float speedx, speedy;
public:
	Player() {
		texture.loadFromFile("images\\spaceShips_002.png");
		sprite.setTexture(texture);
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
	void update() {

		float dX = mouse.getPosition().x - sprite.getPosition().x;
		float dY = mouse.getPosition().y - sprite.getPosition().y;
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
		sprite.setRotation(rotation + 90);
		float distance = std::sqrt(dX * dX + dY * dY);
		if (distance > Pspeed)
		{
			sprite.move(Pspeed * dX / distance, Pspeed * dY / distance);
		}
	}

	sf::Sprite getSprite() { return sprite; }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds();}
};