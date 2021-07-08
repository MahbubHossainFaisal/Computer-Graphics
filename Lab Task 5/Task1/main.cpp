#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;
float _move1=-1.5;
float _move2=1.5;



void object_1()
{
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move1, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.1f, 0.2);
glEnd();
glPopMatrix();
}



void object_2()
{
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move2, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.3f, 0.0f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.1f, 0.2);
glEnd();
glPopMatrix();
}







void update1(int value) {
_move1 += .01;
if(_move1 > 1.5)
{
_move1 = -1.5;
}
glutPostRedisplay();
glutTimerFunc(20, update1, 0);
}


void update2(int value) {
_move2 -= .01;
if(_move2 < -1.5)
{
_move2 = 1.5;
}
glutPostRedisplay();
glutTimerFunc(20, update2, 0);
}



void drawScene() {
glClear(GL_COLOR_BUFFER_BIT);
object_1();
object_2();
glutSwapBuffers();
}




int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutCreateWindow("Transformation");
glutDisplayFunc(drawScene);
gluOrtho2D(-2,2,-2,2);
glutTimerFunc(20, update1, 0);
glutTimerFunc(20, update2, 0); //Add a timer
glutMainLoop();
return 0;
}
