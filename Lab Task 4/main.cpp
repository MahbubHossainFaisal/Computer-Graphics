#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#include<bits/stdc++.h>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void horizontalCar1()
{
    glBegin(GL_QUADS);
        //roof
        glColor3ub(255,255,0);
        glVertex2d(-100,40);
        glVertex2d(-105,35);
        glVertex2d(-80,35);
        glVertex2d(-85,40);
        //body
        glVertex2d(-115,35);
        glVertex2d(-115,25);
        glVertex2d(-65,25);
        glVertex2d(-65,35);

    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
         glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-75,y+25);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
         glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-100,y+25);
    }
    glEnd();
}


void horizontalCar2()
{
    glBegin(GL_QUADS);
        //roof
        glColor3ub(255,255,0);
        glVertex2d(60,40);
        glVertex2d(55,35);
        glVertex2d(90,35);
        glVertex2d(85,40);
        //body
        glVertex2d(45,35);
        glVertex2d(45,25);
        glVertex2d(95,25);
        glVertex2d(95,35);

    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
         glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+55,y+25);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
         glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+85,y+25);
    }
    glEnd();
}

void circle(int a,int b1,int r,int g,int b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
         glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+a,y+b1);
    }
    glEnd();

}

void Boards(int a,int b,int c, int d,int e,int f,int g, int h){
glBegin(GL_QUADS);
glColor3ub(128,128,128);
glVertex2d(a,b);
glVertex2d(c,d);
glVertex2d(e,f);
glVertex2d(g,h);
glEnd();
}

void BlackBoards(int a,int b,int c, int d,int e,int f,int g, int h){
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2d(a,b);
glVertex2d(c,d);
glVertex2d(e,f);
glVertex2d(g,h);
glEnd();
}

void RoadLines(int a,int b,int c, int d,int e,int f,int g, int h){
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(a,b);
glVertex2d(c,d);
glVertex2d(e,f);
glVertex2d(g,h);
glEnd();
}
void display() {
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(7.0);

//Boards
Boards(-200,60,-100,60,-100,200,-200,200);
Boards(-200,-60,-100,-60,-100,-200,-200,-200);
Boards(100,200,100,60,200,60,200,200);
Boards(100,-60,100,-200,200,-200,200,-60);
//Traffic boards
BlackBoards(-180,70,-125,70,-125,190,-180,190);
BlackBoards(180,70,125,70,125,190,180,190);
BlackBoards(180,-70,125,-70,125,-190,180,-190);
BlackBoards(-180,-70,-125,-70,-125,-190,-180,-190);

//Vertical lines
RoadLines(-10,190,-10,160,10,160,10,190);
RoadLines(-10,150,-10,110,10,110,10,150);
RoadLines(-10,100,-10,60,10,60,10,100);
RoadLines(-10,50,-10,10,10,10,10,50);
RoadLines(-10,0,-10,-40,10,-40,10,0);
RoadLines(-10,-50,-10,-90,10,-90,10,-50);
RoadLines(-10,-100,-10,-140,10,-140,10,-100);
RoadLines(-10,-150,-10,-190,10,-190,10,-150);

//Horizontal lines
RoadLines(-190,0,-190,-10,-160,-10,-160,0);
RoadLines(-150,0,-150,-10,-110,-10,-110,0);
RoadLines(-100,0,-100,-10,-60,-10,-60,0);
RoadLines(-50,0,-50,-10,-20,-10,-20,0);
RoadLines(20,0,20,-10,40,-10,40,0);
RoadLines(50,0,50,-10,90,-10,90,0);
RoadLines(100,0,100,-10,140,-10,140,0);
RoadLines(150,0,150,-10,190,-10,190,0);



//traffic lights

//upper left corner
circle(-155,170,255,0,0);
circle(-155,130,255,255,0);
circle(-155,90,0,128,0);
//upper right corner
circle(155,170,255,0,0);
circle(155,130,255,255,0);
circle(155,90,0,128,0);
//lower left corner
circle(-155,-170,255,0,0);
circle(-155,-130,255,255,0);
circle(-155,-90,0,128,0);
//lower right corner
circle(155,-170,255,0,0);
circle(155,-130,255,255,0);
circle(155,-90,0,128,0);

//Horizontal Cars
horizontalCar1();
horizontalCar2();

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
