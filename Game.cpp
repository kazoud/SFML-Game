#pragma once
#include "Game.h"
#include "ResourceHolder.h"
#include "ResourceHolder.inl"
#include "Aircraft.h"
#include "SpriteNode.h"
#include "World.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
float power = 50.f;
Game::Game() : mWindow(sf::VideoMode(640, 480), "Zoodini's game", sf::Style::Close), mWorld(mWindow)
{
	printf("The game has been created\n");
}

Game::~Game()
{
	printf("The game is being deleted");
}

void Game::run()
{	//Creating the window and the data structure that holds the resrouces

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}	
	
		render();
	}
}

/*void Game::setPlayer(sf::Sprite sprite)
{
	mPlayer = sprite;
}*/

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	/*if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;*/
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw(); 
	mWindow.display();
}