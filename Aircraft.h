#pragma once
#include "Entity.h"
#include "ResourceHolder.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

namespace Aircraft_Textures
{
	enum ID
	{
		Eagle,
		Raptor,
	};
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Aircraft : public Entity
{
	public:
		enum Type { Eagle, Raptor,};

	public:
		explicit Aircraft(Type type, const TextureHolder& textures);
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Type mType;
		sf::Sprite mSprite;
};