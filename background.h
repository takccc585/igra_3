#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <iostream>

class Background {
private:
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Mouse mouse;
	float angle;
	float speedx, speedy;
public:
	Background() {
		texture.loadFromFile("images\\backg.jpg");
		sprite.setTexture(texture);
	}
	void update() {}
	sf::Sprite getSprite() { return sprite; }
};