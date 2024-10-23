#include "BallTrail.h"
#include <iostream>

BallTrail::BallTrail(sf::RenderWindow* window, float radius)
{
	this->radius = radius;
	_window = window;

	//for (int i = 0; i < sizeof(_trailSprites); i++) {

	//}

	sf::CircleShape _tempParticle(3.5f, 4);

	_tempParticle.setFillColor(sf::Color::Red);
	_tempParticle.setPosition(sf::Vector2f(-20, -20));

	for (sf::CircleShape &_particle: _trailParticles) {
		_particle = _tempParticle;
	}

	for (float& trailParticleGravity : trailParticleGravities) {
		trailParticleGravity = 0;
	}

	srand(time(NULL));
}

void BallTrail::update(float dt, sf::Vector2f bLocation)
{
	ballLocation = bLocation;

	timePassedSinceLastParticle += dt;
	if (timePassedSinceLastParticle > particleFrequencySeconds) {
		addTrailParticle();
		timePassedSinceLastParticle = 0;
	}

		//for (sf::CircleShape& _particle : _trailParticles) {
		//	sf::Color particleColour = _particle.getFillColor();
		//	_particle.setFillColor(sf::Color(
		//		particleColour.r - 2,
		//		particleColour.g - 2,
		//		particleColour.b - 2
		//	));
		//}

	for (float& trailParticleGravity : trailParticleGravities) {
		trailParticleGravity += dt * gravityMultiplier;
	}



	//std::cout << "timepased - " << timePassedSinceLastParticle << "\n";

	//beginRenderTrail(ballLocation);
}

void BallTrail::addTrailParticle()
{
	int particleBleed = 15;

	float randPosInx = rand() % (int)(radius + particleBleed) + 1;
	float randPosIny = rand() % (int)(radius + particleBleed) + 1;

	randPosInx -= particleBleed / 2;
	randPosIny -= particleBleed / 2;

	_trailParticles[currentParticle].setPosition(ballLocation + sf::Vector2f(randPosInx, randPosIny));
	trailParticleGravities[currentParticle] = 0;
	//_trailParticles[currentParticle].setFillColor(defautColor);
	currentParticle++;
	if (currentParticle >= PARTICLEAMOUNT) {
		currentParticle = 0;
	}
}

void BallTrail::render()
{
	////jitter
	//float jitter = rand() % 100 + 1;

	////value between -50 and 50
	//jitter -= 50;
	////now its inbetween -1 and 1;
	//jitter /= 50.f;

	for (int i = 0; i < PARTICLEAMOUNT; i++) {

		//jitter
		float jitter = rand() % 100 + 1;

		//value between -50 and 50
		jitter -= 50;
		//now its inbetween -1 and 1;
		jitter /= 50.f;

		jitter *= jitterMultiplier;

		_trailParticles[i].move(sf::Vector2f(jitter, trailParticleGravities[i]));
		_window->draw(_trailParticles[i]);
	}

	//for (sf::CircleShape &_particle : _trailParticles) {
	//	_particle.move()
	//	_window->draw(_particle);
	//}
}
