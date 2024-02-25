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

void Game::initStates() {
	this->states.push(new GameState(this->window));
}


// constructors, destructors

Game::Game() {
	this->initWindow();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {
			// save something, play animation before quitting
			this->states.top()->endState();

			delete this->states.top();
			this->states.pop();
		}
	}

	// application end
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render() {
	window->clear();

	if (!this->states.empty()) {
		this->states.top()->render();
	}

	window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();

		this->update();
		this->render();

	}
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

void Game::endApplication() {
	std::cout << "Ending Application" << "\n";
}




