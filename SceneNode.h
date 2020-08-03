#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

class SceneNode: public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

	public:
		SceneNode();

	public:
		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::vector<Ptr> mChildren;
		SceneNode* mParent;

};