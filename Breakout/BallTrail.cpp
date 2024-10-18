#include "BallTrail.h"
#include <iostream>

BallTrail::BallTrail(sf::RenderWindow* window, float radius)
{
	this->radius = radius;
	_window = window;

	//for (int i = 0; i < sizeof(_trailSprites); i++) {

	//}

	sf::CircleShape _tempParticle(3.5f, 4);

	_tempParticle.setFillColor(sf::Color::White);
	_tempParticle.setPosition(sf::Vector2f(-20, -20));

	for (sf::CircleShape &_particle: _trailParticles) {
		_particle = _tempParticle;
	}

	for (float& trailParticleGravity : trailParticleGravities) {
		trailParticleGravity = 0;
	}
}

void BallTrail::update(float dt, sf::Vector2f bLocation)
{
	ballLocation = bLocation;

	timePassedSinceLastParticle += dt;
	if (timePassedSinceLastParticle > particleFrequencySeconds) {
		addTrailParticle();
		timePassedSinceLastParticle = 0;
	}

	for (float& trailParticleGravity : trailParticleGravities) {
		trailParticleGravity += dt / 7;
	}

	//std::cout << "timepased - " << timePassedSinceLastParticle << "\n";

	//beginRenderTrail(ballLocation);
}

void BallTrail::addTrailParticle()
{
	_trailParticles[currentParticle].setPosition(ballLocation);
	trailParticleGravities[currentParticle] = 0;
	currentParticle++;
	if (currentParticle >= PARTICLEAMOUNT) {
		currentParticle = 0;
	}
}

void BallTrail::render()
{
	for (int i = 0; i < PARTICLEAMOUNT; i++) {
		_trailParticles[i].move(sf::Vector2f(0, trailParticleGravities[i]));
		_window->draw(_trailParticles[i]);
	}

	//for (sf::CircleShape &_particle : _trailParticles) {
	//	_particle.move()
	//	_window->draw(_particle);
	//}
}
