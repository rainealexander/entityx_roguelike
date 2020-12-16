#pragma once

#include "entityx/entityx.h"
#include "SFML/Graphics.hpp"

namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem>
{
public:
    explicit RenderSystem(sf::RenderTarget& target, sf::Font& font);
	void update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt);

private:
	double last_update_ = 0.0;
	double frame_count_ = 0.0;
	sf::RenderTarget& target_;
	sf::Text text_;
};

