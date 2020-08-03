#pragma once
#include <iostream>
#include "ResourceHolder.h"
#include "Game.h"
#include <assert.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>



template <typename Resource, typename Identifier>

ResourceHolder<Resource, Identifier>::ResourceHolder()
{
	std::cout << "The resource holder has been created." << std::endl;
}

template <typename Resource, typename Identifier>

ResourceHolder<Resource, Identifier>::~ResourceHolder()
{
	std::cout << "The resource holder has been deleted" << std::endl;
}


template <typename Resource, typename Identifier>

void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());

	resource->loadFromFile(filename);

	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

	assert(inserted.second);
	std::cout << "File has been loaded from " << filename << std::endl;
}

template<typename Resource, typename Identifier>
template<typename Parameter>

void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());

	resource->loadFromFile(filename, secondParam);

	if (!resource->loadFromFile(filename, secondParam))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

	assert(inserted.second);
	std::cout << "File has been loaded from " << filename << std::endl;
}

template <typename Resource, typename Identifier>

const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>

Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

