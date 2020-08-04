#pragma once
#include "ResourceHolder.h"
#include "ResourceHolder.inl"
#include "SceneNode.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class Entity: public SceneNode
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
	
private:
	sf::Vector2f mVelocity;
	virtual void updateCurrent(sf::Time dt);
};
