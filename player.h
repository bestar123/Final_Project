#pragma once

#include <vector>
#include <GL/glut.h>
#include <iostream>

using namespace std;

class player {
public:
	player();
	player(int x, int y);
	~player();

	void setPos(int x, int y);
	void floodfill();
	void wincheck();
	void updatebound();
	void draw();


	int life;
	int * pos;
	int ** area;
	float ratio;

	vector<vector<int>> trace;
	vector<int*> boundary;
};