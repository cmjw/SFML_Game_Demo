#ifndef GAME_H
#define GAME_H

#include "GameState.h"


class Game {
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;

	float dt;
	sf::Clock dtClock;

	// state is abstract, can only create ptrs
	std::stack<State*> states;

	void initWindow();
	void initStates();

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