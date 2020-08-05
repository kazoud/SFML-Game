#pragma once
#include "ResourceHolder.h"
#include "ResourceHolder.inl"
#include "World.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	//void setPlayer(sf::Sprite sprite);
private:
	sf::RenderWindow mWindow;
	//sf::Sprite mBackground;
	//sf::Sprite mPlayer;
	//bool mIsMovingUp = false;
	//bool mIsMovingDown = false;
	//bool mIsMovingLeft = false;
	//bool mIsMovingRight = false;
	World mWorld;
};


