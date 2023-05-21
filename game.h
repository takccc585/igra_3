#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <vector>
#include "meteor.h"
#include "player.h"
#include "background.h"
#include "enemy.h"

class Game {
private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteors;
	Player player;
	Enemy enemy;
	Background background;
public:
	Game() {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, "game", sf::Style::Fullscreen);
		window.setFramerateLimit(FPS);
	}

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
	}
	void update() {
		player.update();
		enemy.update(player.getPosition());
	}

	void checkColisions() {
		sf::FloatRect playerBounds = player.getHitBox();
			sf::FloatRect enemyBounds = enemy.getHitBox();
			if (enemyBounds.intersects(playerBounds)) {
				window.close();
			}
	}

	void draw() {
		window.clear();
		window.draw(background.getSprite());
		window.draw(enemy.getSprite());
		window.draw(player.getSprite());
		window.display();
	}

	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkColisions();
			draw();
		}
	}
};