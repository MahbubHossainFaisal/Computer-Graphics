
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(4.0);
// Draw a Red 1x1 Square centered at origin

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-80.0,70.0);
glVertex2d(-80.0,60.0);
glVertex2d(-70.0,60.0);
glVertex2d(-70.0,70.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-70.0,70.0);
glVertex2d(-70.0,60.0);
glVertex2d(-60.0,60.0);
glVertex2d(-60.0,70.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-60.0,70.0);
glVertex2d(-60.0,60.0);
glVertex2d(-50.0,60.0);
glVertex2d(-50.0,70.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-50.0,70.0);
glVertex2d(-50.0,60.0);
glVertex2d(-40.0,60.0);
glVertex2d(-40.0,70.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-80.0,60.0);
glVertex2d(-80.0,50.0);
glVertex2d(-70.0,50.0);
glVertex2d(-70.0,60.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-70.0,60.0);
glVertex2d(-70.0,50.0);
glVertex2d(-60.0,50.0);
glVertex2d(-60.0,60.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-60.0,60.0);
glVertex2d(-60.0,50.0);
glVertex2d(-50.0,50.0);
glVertex2d(-50.0,60.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-50.0,60.0);
glVertex2d(-50.0,50.0);
glVertex2d(-40.0,50.0);
glVertex2d(-40.0,60.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-80.0,50.0);
glVertex2d(-80.0,40.0);
glVertex2d(-70.0,40.0);
glVertex2d(-70.0,50.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-70.0,50.0);
glVertex2d(-70.0,40.0);
glVertex2d(-60.0,40.0);
glVertex2d(-60.0,50.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-60.0,50.0);
glVertex2d(-60.0,40.0);
glVertex2d(-50.0,40.0);
glVertex2d(-50.0,50.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-50.0,50.0);
glVertex2d(-50.0,40.0);
glVertex2d(-40.0,40.0);
glVertex2d(-40.0,50.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-80.0,40.0);
glVertex2d(-80.0,30.0);
glVertex2d(-70.0,30.0);
glVertex2d(-70.0,40.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-70.0,40.0);
glVertex2d(-70.0,30.0);
glVertex2d(-60.0,30.0);
glVertex2d(-60.0,40.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(-60.0,40.0);
glVertex2d(-60.0,30.0);
glVertex2d(-50.0,30.0);
glVertex2d(-50.0,40.0);
glEnd();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(-50.0,40.0);
glVertex2d(-50.0,30.0);
glVertex2d(-40.0,30.0);
glVertex2d(-40.0,40.0);
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
