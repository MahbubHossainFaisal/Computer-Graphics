#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat speed = 0.1f;
void dis();
void display();

void update(int value) {

    if(position <-1.5)
        position = 1.0f;

    position -= speed;

    glutPostRedisplay();


    glutTimerFunc(100,update,0);
}


void update1(int value) {

    if(position1 >1.0)
        position1 = -1.0f;

    position1 += speed;

    glutPostRedisplay();


    glutTimerFunc(100,update1,0);
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void display5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPushMatrix();

//third object
   glBegin(GL_POLYGON);
  glColor3f(0.8f, 0.2f, 0.5f);
   glVertex2f(-0.6f,0.2f);
   glVertex2f(-0.8f, 0.0f);
   glVertex2f(-0.6f, -0.2f);
   glVertex2f(-0.2f,-0.2f);
   glVertex2f(-0.2f,0.2f);
   glEnd();

   //Fourth object
   glBegin(GL_POLYGON);
  glColor3f(0.4f, 0.9f, 0.7f);
   glVertex2f(-0.4f,-0.4f);
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(-0.4f, -0.6f);
   glVertex2f(0.2f,-0.6f);
   glVertex2f(0.3f,-0.5f);
   glVertex2f(0.2f,-0.4f);
   glEnd();
   glTranslatef(position1,0.0f, 0.0f);
    //first object
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, 0.4f);
      glVertex2f( 0.2f, 0.4f);
      glVertex2f( 0.2f,  0.8f);
      glVertex2f(-0.2f,  0.8f);
   glEnd();
   //second object
   glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f(0.5f,-0.2f);
   glVertex2f(0.8f, 0.0f);
   glVertex2f(0.5f, 0.2f);
   glEnd();



   glPopMatrix();

   glFlush();

}

void display4(int val) {

 glutDisplayFunc(display5);


}



void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
   //first object
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, 0.4f);
      glVertex2f( 0.2f, 0.4f);
      glVertex2f( 0.2f,  0.8f);
      glVertex2f(-0.2f,  0.8f);
   glEnd();
   //second object
   glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f(0.5f,-0.2f);
   glVertex2f(0.8f, 0.0f);
   glVertex2f(0.5f, 0.2f);
   glEnd();
    glTranslatef(position,0.0f, 0.0f);
   //third object
   glBegin(GL_POLYGON);
  glColor3f(0.8f, 0.2f, 0.5f);
   glVertex2f(-0.6f,0.2f);
   glVertex2f(-0.8f, 0.0f);
   glVertex2f(-0.6f, -0.2f);
   glVertex2f(-0.2f,-0.2f);
   glVertex2f(-0.2f,0.2f);
   glEnd();

   //Fourth object
   glBegin(GL_POLYGON);
  glColor3f(0.4f, 0.9f, 0.7f);
   glVertex2f(-0.4f,-0.4f);
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(-0.4f, -0.6f);
   glVertex2f(0.2f,-0.6f);
   glVertex2f(0.3f,-0.5f);
   glVertex2f(0.2f,-0.4f);
   glEnd();

   glPopMatrix();

   glFlush();
}

void display2(int val) {

 glutDisplayFunc(display3);


}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



glPushMatrix();
glTranslatef(0.0f,0.0f, 0.0f);
    //first object
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, 0.4f);
      glVertex2f( 0.2f, 0.4f);
      glVertex2f( 0.2f,  0.8f);
      glVertex2f(-0.2f,  0.8f);
   glEnd();
   //second object
   glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.5f, 0.0f);
   glVertex2f(0.5f,-0.2f);
   glVertex2f(0.8f, 0.0f);
   glVertex2f(0.5f, 0.2f);
   glEnd();

   //third object
   glBegin(GL_POLYGON);
  glColor3f(0.8f, 0.2f, 0.5f);
   glVertex2f(-0.6f,0.2f);
   glVertex2f(-0.8f, 0.0f);
   glVertex2f(-0.6f, -0.2f);
   glVertex2f(-0.2f,-0.2f);
   glVertex2f(-0.2f,0.2f);
   glEnd();

   //Fourth object
   glBegin(GL_POLYGON);
  glColor3f(0.4f, 0.9f, 0.7f);
   glVertex2f(-0.4f,-0.4f);
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(-0.4f, -0.6f);
   glVertex2f(0.2f,-0.6f);
   glVertex2f(0.3f,-0.5f);
   glVertex2f(0.2f,-0.4f);
   glEnd();

glPopMatrix();

 //glutTimerFunc(2000,display2,0);
glFlush();

}

void dis()
{

       glutDisplayFunc(display);
}



void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{	glutTimerFunc(500,display2,0);
			}
if (button == GLUT_RIGHT_BUTTON)
	{ glutTimerFunc(500,display4,0);  }
glutPostRedisplay();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(dis);
   glutMouseFunc(handleMouse);
   init();
   glutTimerFunc(100, update, 0);
     glutTimerFunc(100, update1, 0);
   glutMainLoop();
   return 0;
}

