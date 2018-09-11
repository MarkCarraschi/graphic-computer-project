

//Basics translations and rotations forms

#include "pch.h"
#include <iostream>
#include <glut.h>
#include "Example.h"

using namespace std;

Example classTest;

static int shoulder = 45.0, elbow = 0;

void init(void) {
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0,0.4,1.0);
	glutWireCube(1.0);
	glPopMatrix();


	////First screw --> Sphere
	glPushMatrix();
	//glTranslatef(1.0, 0.0, 0.0);
	//glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	//glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glutWireSphere(0.350, 30, 20);
	glPopMatrix();

	////Second screw --> Sphere
	glPushMatrix();
	//glTranslatef(1.0, 0.0, 0.0);
	//glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(45.0, 0.0, 0.0);
	//glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glutWireSphere(0.350, 30, 20);
	glPopMatrix();

	/*glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0,0.0,0.0);
	glPushMatrix();
	glScalef(2.0,0.4,1.0);
	glutWireCube(1.0);
	glPopMatrix();*/

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		cout << "X: " << shoulder << "	Y:" << elbow<< endl;
		break;
	case 'a':
		shoulder = (shoulder - 5) % 360;
		cout << "X: " << shoulder << "	Y:" << elbow << endl;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}