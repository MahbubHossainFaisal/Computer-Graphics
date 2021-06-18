
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(7.0);

//Making a tree

glBegin(GL_TRIANGLES);

glColor3ub(70, 117, 1);
glVertex2d(0,50);
glVertex2d(-35,0);
glVertex2d(35,0);
glEnd();
glBegin(GL_TRIANGLES);

glColor3ub(70, 117, 1);
glVertex2d(0,30);
glVertex2d(-35,-15);
glVertex2d(35,-15);
glEnd();


//giving root for tree
glBegin(GL_QUADS);

glColor3ub(147, 50, 3);
glVertex2d(-5,-15);
glVertex2d(-5,-60);
glVertex2d(5,-60);
glVertex2d(5,-15);
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
