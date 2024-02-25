#ifndef GAME_H
#define GAME_H

#include "State.h"


class Game {
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;

	float dt;
	sf::Clock dtClock;

	void initWindow();

public:
	Game();
	virtual ~Game();

	void update();
	void updateDt();
	void updateSFMLEvents();
	void render();
	void run();
};

#endif