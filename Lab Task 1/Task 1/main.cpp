#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(4.0);
// Draw a Red 1x1 Square centered at origin
glBegin(GL_LINES);
//glColor3f(1.0f,0.0f,0.0f);
glColor3ub(247, 220, 111);
glVertex2f(0.0f,0.0f);
//glColor3ub(240, 200, 11);
glVertex2f(0.0f,8.0f);
glVertex2f(14.0f,8.0f);
glVertex2f(14.0f,0.0f);
glVertex2f(0.0f,0.0f);
glVertex2f(14.0f,0.0f);
glVertex2f(0.0f,8.0f);
glVertex2f(14.0f,8.0f);
glEnd();

 glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
glutInitWindowSize(620, 420); // Set the window's initial width & height
gluOrtho2D(-15,15,-15,15);
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
