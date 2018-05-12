#include <GL/glut.h>

using namespace std;


#define WIDTH 600		// window's width
#define HEIGHT 600		// window's height

int sp_key;				// special key


void processSpecialKeys(int key, int x, int y) {
	/* Implement: Set key input */
}

void idle() {
	/* Implement: Move the square */
}

void renderScene() {
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Final Project");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
