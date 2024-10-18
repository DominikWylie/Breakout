#pragma once
#include <SFML/Graphics.hpp>

#define PARTICLEAMOUNT 10

class BallTrail
{
public:
	BallTrail(sf::RenderWindow* window, float radius);

	void update(float dt, sf::Vector2f ballLocation);

	void render();

private:
	void addTrailParticle();

	sf::RenderWindow* _window;

	float radius;

	sf::CircleShape _trailParticles[PARTICLEAMOUNT];
	float trailParticleGravities[PARTICLEAMOUNT];
	sf::Vector2f ballLocation = sf::Vector2f(0, 0);

	int currentParticle = 0;
	float particleFrequencySeconds = 0.1f;
	float timePassedSinceLastParticle = 0.f;
};

