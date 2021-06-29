#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#include<bits/stdc++.h>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void card()
{
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2d(-125,100);
    glVertex2d(-150,70);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2d(-150,70);
    glVertex2d(-150,-100);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2d(-150,-100);
    glVertex2d(150,-100);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2d(150,-100);
    glVertex2d(150,100);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2d(150,100);
    glVertex2d(-125,100);
    glEnd();


}

void square()
{
glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2d(-125,80);
    glVertex2d(-125,20);
    glVertex2d(-65,20);
    glVertex2d(-65,80);
    glEnd();

}
void triangleTwo()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2d(-115,70);
    glVertex2d(-115,30);
    glVertex2d(-70,50);
    glEnd();
}

void Trapezoid()
{
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex2d(-55,60);
    glVertex2d(-55,-60);

    glVertex2d(30,-80);
    glVertex2d(30,80);

    glEnd();
}
void hexagon()
{
    glBegin(GL_POLYGON);
    glColor3ub(255,140,0);
    glVertex2d(50,60);
    glVertex2d(35,30);

    glVertex2d(50,0);
    glVertex2d(120,0);
    glVertex2d(135,30);
    glVertex2d(120,60);

    glEnd();
}
void triangleOne()
{

    glBegin(GL_TRIANGLES);
    glColor3ub(255,0,0);
    glVertex2d(90,-20);
    glVertex2d(40,-80);
    glVertex2d(140,-80);
    glEnd();
}

void display() {
glClearColor(255.0f, 255.0f, 255.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(7.0);
//card
card();
square();
triangleTwo();
Trapezoid();
hexagon();
triangleOne();
 glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(550,550); // Set the window's initial width & height
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

gluOrtho2D(-200,200,-200,200);
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
