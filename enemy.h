﻿#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <iostream>

class Enemy {
private:
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
public:
	Enemy() {
		texture.loadFromFile("images\\enemy.png");
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3);
		sprite.setScale(0.1,0.1);
	}
	void update( sf::Vector2f pos) {
		float dX = pos.x - sprite.getPosition().x;
		float dY = pos.y - sprite.getPosition().y;
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
		sprite.setRotation(rotation + 90);
		float distance = std::sqrt(dX * dX + dY * dY);
		if (distance > Espeed)
		{
			sprite.move(Espeed * dX / distance, Espeed * dY / distance);
		}
	}

	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};