#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;


float _angle1 = 0.0f;
float _angle2 = 0.0f;

void carBody()
{
    glColor3ub(255,255,0);
    //car head
    glBegin(GL_QUADS);
    glVertex2f(-0.4,0.3f);
    glVertex2f(-0.6f,0.1f);
    glVertex2f(0.2f,0.1f);
    glVertex2f(0.0f,0.3f);
    glEnd();
    //car body
    glBegin(GL_QUADS);
    glVertex2f(-0.9f,0.1f);
    glVertex2f(-0.9f,-0.1f);
    glVertex2f(0.5f,-0.1f);
    glVertex2f(0.5f,0.1f);
    glEnd();
    //left guard
    glBegin(GL_QUADS);
    glVertex2f(-0.9f,-0.1f);
    glVertex2f(-0.9f,-0.15f);
    glVertex2f(-0.7f,-0.15f);
    glVertex2f(-0.7f,-0.1f);
    glEnd();
    //front guard
    glBegin(GL_QUADS);
    glVertex2f(0.3f,-0.1f);
    glVertex2f(0.3f,-0.15f);
    glVertex2f(0.5f,-0.15f);
    glVertex2f(0.5f,-0.1f);
    glEnd();
    //left upper guard
    glBegin(GL_QUADS);
    glVertex2f(-0.9f,0.1f);
    glVertex2f(-0.9f,0.15f);
    glVertex2f(-0.5f,0.15f);
    glVertex2f(-0.5f,0.1f);
    glEnd();


}

void tier1()
{
glPushMatrix();
glTranslatef(-0.6f,-0.2f,0.0f);
glRotatef(_angle1, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.09;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.08;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();


glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}





void tier2()
{
glPushMatrix();
glTranslatef(0.2f,-0.2f,0.0f);
glRotatef(_angle2, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.09;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();

glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.08;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}
void drawScene() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);

carBody();
tier1();


tier2();


 glutSwapBuffers();
}

void update1(int value) {

 _angle1+=1.0f;
if(_angle1 > 360.0)
{
_angle1-=360;
}
glutPostRedisplay(); //Notify GLUT that the display has changed

 glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update2(int value) {

 _angle2+=1.0f;
if(_angle2 > 360.0)
{
_angle2-=360;
}
glutPostRedisplay(); //Notify GLUT that the display has changed

 //Notify GLUT to call update again in 25 milliseconds
 glutTimerFunc(20, update2, 0);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutCreateWindow("Transformation");
glutDisplayFunc(drawScene);
glutTimerFunc(20, update1, 0); //Add a timer
glutTimerFunc(20,update2,0);
glutMainLoop();
return 0;
}