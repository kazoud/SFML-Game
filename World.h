#pragma once

#include "Game.h"
#include "ResourceHolder.h"
#include "ResourceHolder.inl"
#include "Aircraft.h"
#include "SpriteNode.h"

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class World: sf::NonCopyable
{
	public:
		explicit World(sf::RenderWindow& window);
		void update(sf::Time dt);
		void draw();

	private:
		void loadTextures();
		void buildScene();

	private:
		enum Layer { Background, Air, LayerCount};

	private:
		sf::RenderWindow& mWindow;
		sf::View mWorldView; // The view is what the player sees at any given time.
		TextureHolder mTextures;
		SceneNode mSceneGraph;
		std::array<SceneNode*, LayerCount> mSceneLayers;

		sf::FloatRect mWorldBounds; //The WorldBounds is the bigger rectangle across which the View scrolls.
		sf::Vector2f mSpawnPosition;// The spawn position of the window view
		float mScrollSpeed;
		Aircraft* mPlayerAircraft;
};