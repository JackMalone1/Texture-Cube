#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Vector3.h>
#include <Matrix3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>



class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void processEvents(sf::Event t_event);

	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;

	double m_angle = 0.5;

	const int m_NUM_POINTS = 36;

	const int m_NUM_TRIANGLE_POINTS = 3;

	const int m_NUM_VERTICES = 24;
};

#endif