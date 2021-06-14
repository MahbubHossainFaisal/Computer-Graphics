
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(4.0);
// Draw a Red 1x1 Square centered at origin
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2d(55.0,55.0);
glVertex2d(-55.0,55.0);
glVertex2d(-80.0,35.0);
glVertex2d(-80.0,-5.0);
glVertex2d(-55.0,-25.0);
glVertex2d(55.0,-25.0);
glVertex2d(80.0,35.0);
glVertex2d(80.0,-5.0);
glVertex2d(55.0,-25.0);




glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,0);
glVertex2d(50.0,50.0);
glVertex2d(-50.0,50.0);
glVertex2d(-75.0,30.0);
glVertex2d(-75.0,0.0);
glVertex2d(-50.0,-20.0);
glVertex2d(50.0,-20.0);
glVertex2d(75.0,30.0);
glVertex2d(75.0,0.0);
glVertex2d(50.0,-20.0);
glEnd();

glBegin(GL_POLYGON);

glColor3ub(0,0,0);

glVertex2d(10,40);
glVertex2d(10,20);
glVertex2d(-10,20);
glVertex2d(-10,40);
glVertex2d(-15,40);
glVertex2d(-15,10);
glVertex2d(-30,10);
glVertex2d(-30,15);
glVertex2d(-40,15);
glVertex2d(-40,30);
glVertex2d(-45,25);
glVertex2d(-45,20);
glVertex2d(-50,20);
glVertex2d(-50,-10);
glVertex2d(-45,-10);
glVertex2d(-45,-5);
glVertex2d(-35,-5);
glVertex2d(0,-17);
glVertex2d(35,-5);
glVertex2d(45,-5);
glVertex2d(45,-10);
glVertex2d(50,-10);
glVertex2d(50,20);
glVertex2d(45,20);
glVertex2d(45,25);
glVertex2d(40,30);
glVertex2d(40,15);
glVertex2d(30,15);
glVertex2d(30,10);
glVertex2d(15,10);
glVertex2d(15,40);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(255,255,0);
glVertex2d(10,40);
glVertex2d(-10,40);
glVertex2d(-10,30);
glVertex2d(10,30);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,255,0);
glVertex2d(30,40);
glVertex2d(15,40);
glVertex2d(15,20);
glVertex2d(30,20);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(255,255,0);
glVertex2d(-30,40);
glVertex2d(-15,40);
glVertex2d(-15,20);
glVertex2d(-30,20);
glEnd();

 glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(520, 520); // Set the window's initial width & height
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

gluOrtho2D(-100,100,-100,100);
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
