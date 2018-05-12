#include "player.h"

player::player()
{
	pos = new int [2];
	setPos(0, 0);
}

player::player(int x, int y)
{
	pos = new int[2];
	setPos(x, y);
	life = 3;
}

player::~player()
{
}

void player::draw()
{
	//draw player's position
	glPointSize(10.0f);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(pos[0], pos[1]);
	glVertex2i(500, 500);
	glEnd();
	//draw player's trace

}

void player::setPos(int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

void player::floodfill()
{
}

void player::wincheck()
{
}

void player::updatebound()
{
}
