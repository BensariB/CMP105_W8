#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 2; i ++) {
		ball[i].setTexture(&texture);
		ball[i].setPosition(sf::Vector2f(i * 800, 300));
		ball[i].setSize(sf::Vector2f(100, 100));
		ball[i].setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	}
	ball[0].setVelocity(sf::Vector2f(100, 0));
	ball[1].setVelocity(sf::Vector2f(-100, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	for (int i = 0; i < 2; i++) {
		ball[i].update(dt);
	}
	if (Collision::checkBoundingBox(&ball[0], &ball[1])) {
		ball[0].collisionResponse(NULL);
		ball[1].collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	for (int i = 0; i < 2; i++) {
		window->draw(ball[i]);
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}