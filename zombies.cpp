#include "zombies.h"

zombies::zombies()
{
	pos = new int[2];
	setPos(0, 0);
	color = new float[3];
	setColor();
}

zombies::zombies(int x, int y)
{
	pos = new int[2];
	setPos(x,y);
	color = new float[3];
	setColor();
}

zombies::~zombies()
{
}

void zombies::setPos(int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

void zombies::setColor()
{
	for (int i = 0; i < 3; i++) {
		color[i] = (float)(rand() % 1000) / 1000;
	}
}

void zombies::draw()
{
	glPointSize(10.0f);
	glColor3f(color[0],color[1],color[2]);
	glBegin(GL_POINTS);
	glVertex2i(pos[0], pos[1]);
	glEnd();
}
