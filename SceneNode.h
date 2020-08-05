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
		sf::Transform getWorldTransform() const;
		sf::Vector2f getWorldPosition() const;
		void update(sf::Time dt);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void updateCurrent(sf::Time dt);
		virtual void updateChildren(sf::Time dt);


	private:
		std::vector<Ptr> mChildren;
		SceneNode* mParent;

};