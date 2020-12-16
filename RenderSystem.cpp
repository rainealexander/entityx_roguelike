#include "RenderSystem.h"


RenderSystem::RenderSystem(sf::RenderTarget& target, sf::Font& font)
	: target_(target) {
        text_.setFont(font);
        text_.setPosition(sf::Vector2f(rand() % target.getSize().x, rand() % target.getSize().y));
        text_.setCharacterSize(16);
        text_.setFillColor(sf::Color::White);
    
}

void RenderSystem::update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt)
{
}

