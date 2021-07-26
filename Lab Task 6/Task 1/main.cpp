#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>



void dis();
void display();

void update(int value) {

    glutPostRedisplay();
    glutTimerFunc(20,update,0);
}



void init() {
   glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void disback(int val)
{
    glutDisplayFunc(display);
}
void display5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.4f, 0.2f, 0.1f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2d(0.1,0.2);
    glEnd();
   glutTimerFunc(20,disback,0);
   glFlush();

}

void display4(int val) {

 glutDisplayFunc(display5);


}



void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.4f, 0.7f, 0.3f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2d(0.2,0.3);
    glEnd();
   glutTimerFunc(20,display4,0);
   glFlush();
}

void display2(int val) {

 glutDisplayFunc(display3);


}
void display() {
    glClearColor(0.1,0.4,0.5,0);
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
    glBegin(GL_POINTS);
    glVertex2d(0.2,0.5);
    glEnd();


glutTimerFunc(20,display2,0);
glFlush();

}

void dis()
{
       glutDisplayFunc(display);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(dis);
   init();

     glutTimerFunc(20, update, 0);

   glutMainLoop();
   return 0;
}

