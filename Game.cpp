#include "Game.h"


// static functions



// initializer functions

void Game::initWindow() {
	std::ifstream ifs("Config/window.ini");

	sf::VideoMode window_bounds(800, 600);
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vert_sync = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vert_sync;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vert_sync);
}


// constructors, destructors

Game::Game() {
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

void Game::update() {
	this->updateSFMLEvents();

}

/*
* Update dt with time taken to update and render one frame
*/
void Game::updateDt() {
	this ->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
	while (window->pollEvent(sfEvent)) {
		if (sfEvent.type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game::render() {
	window->clear();

	window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();

		this->update();
		this->render();

	}
}


