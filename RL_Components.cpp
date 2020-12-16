#include <vector>
#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <entityx/Entity.h>

namespace ex = entityx;

enum matter_state { solid, liquid, gas, plasma };

struct position : public ex::Component<position>
{
	explicit position(const sf::Vector2f coords) : coords(coords) {}
	sf::Vector2f coords;
};

struct direction : public ex::Component<direction>
{
	explicit direction(const sf::Vector2f dir) : dir(dir) {}
	sf::Vector2f dir;
};

struct temperature : public ex::Component<temperature>
{
	explicit temperature(const float celsius) : celsius(celsius) {}
	float celsius;
};

struct weight : public ex::Component<weight>
{
	explicit weight(const float grams) : grams(grams) {}
	float grams;
};

struct hardness : public ex::Component<hardness>
{
	explicit hardness(const float absolute = 1.0)
		: absolute(absolute) {}

	// material hardness based on absolute hardness, a.k.a. Rosiwal hardness
	float absolute;
};
//note: 3 responses to force - elasticity, plasticity, fracture
//TODO: research hardening of metals

struct elasticity : public ex::Component<elasticity>
{
	explicit elasticity(float elastic) : elastic(elastic) {}
	float elastic;
};

struct uni_char : public ex::Component<uni_char>
{
	explicit uni_char(const std::wstring u_char) : u_char(u_char) {}	
	std::wstring u_char;
};

struct tile : public ex::Component<tile>
{
	tile(position& position, uni_char& character)
		: position(position), character(character) {}

	position position;
	uni_char character;
};

struct material : public ex::Component<material>
{
	material(const std::wstring name, temperature& melt_point, temperature& boil_point, hardness& absolute)
		: name(name), melt_point(melt_point), boil_point(boil_point), absolute(absolute) {}

	std::wstring name;
	temperature melt_point;
	temperature boil_point;
	hardness absolute;
};