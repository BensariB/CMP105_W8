#include "Ball.h"


Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	move(velocity * dt);
	if (getPosition().x < 0) {
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > 900){ 
		setPosition(900, getPosition().y);
		velocity.x = -velocity.x;
	}
}
void Ball::collisionResponse(GameObject* collider) {
	velocity.x = -velocity.x;
}
