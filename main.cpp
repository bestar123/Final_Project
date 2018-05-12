#include "player.h"
#include "zombies.h"
#include <Windows.h>
#include <time.h>

#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height
#define X 500
#define Y 500

player pl (X/2,Y/2);
vector <zombies> zvec;


zombies z(30, 30);

int sp_key;				// special key
int zom_num = 5;			// zombie number
int delay = 1;

void init() {

	srand((unsigned int)time(NULL));

	for (int i = 0; i < zom_num;i++) {
		zombies z (rand() % X, rand() % Y);
		zvec.push_back(z);
	} // Initialize Zombies Randomly

}

void grid() {
	// drawing grid 

	glPointSize(1.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			glColor3f(1, 1, 1);
			glVertex2i(i, j);
		}
	}
	glEnd();
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: {
		sp_key = 1;
		break;
	}
	case GLUT_KEY_DOWN: {
		sp_key = 2;
		break;
	}
	case GLUT_KEY_LEFT: {
		sp_key = 3;
		break;
	}
	case GLUT_KEY_RIGHT: {
		sp_key = 4;
		break;
	}
	}
}

void moveplayer (player pl) {
	float x, y;
	x = pl.pos[0];
	y = pl.pos[1];

	switch (sp_key) {
	case 1: {
		
		if (y < Y) {
			pl.setPos(x, y + 1);
		}
		break;
	}
	case 2: {
		
		if (y > 0) {
			pl.setPos(x, y - 1);
		}
		break;
	}
	case 3: {
		
		if (x > 0) {
			pl.setPos(x - 1, y);
		}
		break;
	}
	case 4: {
		
		if (x < X) {
			pl.setPos(x + 1, y);
		}
		break;
	}
	}
	Sleep(delay);
	glutPostRedisplay();
}

void movezombie(zombies z) {

	int randnum,x,y;
	
	randnum = rand() % 4 + 1;
	x = z.pos[0];
	y = z.pos[1];

	switch (randnum) {
	case 1: {
		if (y < Y) {
			z.setPos(x, y + 1);
		}
		break;
	}
	case 2: {
		
		if (y > 0) {
			z.setPos(x, y - 1);
		}
		break;
	}
	case 3: {
		
		if (x > 0) {
			z.setPos(x - 1, y);
		}
		break;
	}
	case 4: {
		
		if (x < X) {
			z.setPos(x + 1, y);
		}
		break;
	}
	}
	Sleep(delay);
	glutPostRedisplay();

}

void idle() {


	moveplayer(pl);
	for (int i = 0; i < zvec.size(); i++) {
		movezombie(zvec[i]);
	}
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//grid();
	pl.draw();
	for (int i = 0; i < zvec.size(); i++) {
		zvec[i].draw();
	}

	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Final Project");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, X, 0, Y);

	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
