#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

namespace Textures
{
	enum ID { Landscape, Airplane, Missile, Eagle, Raptor};
}

template <typename Resource, typename Identifier>


class ResourceHolder
{
	public:
		ResourceHolder();
		~ResourceHolder();
		void load(Identifier id, const std::string& filename);

		template <typename Parameter>
		void load(Identifier id, const std::string& filename, const Parameter& secondParam); //Overloaded load functions for shaders

		Resource& get(Identifier id);
		const Resource& get(Identifier id) const;

	private:
		std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"