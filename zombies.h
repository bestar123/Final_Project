#pragma once
#include <iostream>
#include <GL/glut.h>


using namespace std;

class zombies {
public:
	zombies();
	zombies(int x, int y);
	~zombies();

	void setPos(int x, int y);
	void setColor();
	void draw();

	int * pos;
	float * color;
};
