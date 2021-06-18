
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(7.0);


glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(10,80);
glVertex2d(10,75);
glVertex2d(80,75);
glVertex2d(80,80);
glEnd();
//straight quads
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(15,85);
glVertex2d(15,50);
glVertex2d(20,50);
glVertex2d(20,85);
glEnd();
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(70,85);
glVertex2d(70,50);
glVertex2d(75,50);
glVertex2d(75,85);
glEnd();


//Seat
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(10,50);
glVertex2d(5,40);
glVertex2d(85,40);
glVertex2d(80,50);
glEnd();

//Front Legs
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(10,40);
glVertex2d(10,10);
glVertex2d(15,10);
glVertex2d(15,40);
glEnd();
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(80,40);
glVertex2d(75,40);
glVertex2d(75,10);
glVertex2d(80,10);
glEnd();

//Back legs
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);
glVertex2d(20,40);
glVertex2d(20,20);
glVertex2d(25,20);
glVertex2d(25,40);
glEnd();
glBegin(GL_QUADS);
glColor3ub(253, 54, 9);

glVertex2d(65,40);
glVertex2d(65,20);
glVertex2d(70,20);
glVertex2d(70,40);
glEnd();





 glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(550,550); // Set the window's initial width & height
glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title

gluOrtho2D(-100,100,-100,100);
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
