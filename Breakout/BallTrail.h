#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

#define PARTICLEAMOUNT 70

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
	float particleFrequencySeconds = 0.01f;
	float timePassedSinceLastParticle = 0.f;

	float gravityMultiplier = -0.05f;
	float jitterMultiplier = 0.05f;
	int fadeframeStutter = 0, framesForStutterElapped = 0;

	sf::Color defautColor = sf::Color::White;
};

