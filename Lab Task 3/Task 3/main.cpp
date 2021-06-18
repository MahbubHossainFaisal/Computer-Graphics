
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(7.0);

glBegin(GL_QUADS);
glColor3ub(147, 50, 3);
glVertex2d(-10,-20);
glVertex2d(-15,-25);
glVertex2d(15,-25);
glVertex2d(10,-20);
glEnd();

glBegin(GL_QUADS);
glColor3ub(147, 50, 3);
glVertex2d(-15,-25);
glVertex2d(-15,-55);
glVertex2d(15,-55);
glVertex2d(15,-25);
glEnd();
glBegin(GL_QUADS);
glColor3ub(147, 50, 3);
glVertex2d(-20,-55);
glVertex2d(-20,-65);
glVertex2d(20,-65);
glVertex2d(20,-55);
glEnd();

//middle of the lamp post
glBegin(GL_QUADS);
glColor3ub(147, 50, 3);
glVertex2d(-4,-20);
glVertex2d(4,-20);
glVertex2d(4,50);
glVertex2d(-4,50);
glEnd();

//Head of the lamp post
glBegin(GL_POLYGON);
glColor3ub(255,255,0);
glVertex2d(-4,50);
glVertex2d(4,50);
glVertex2d(20,75);
glVertex2d(0,95);
glVertex2d(-20,75);
glEnd();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2d(-20,75);
glVertex2d(20,75);
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
