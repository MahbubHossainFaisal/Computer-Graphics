#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

//-------------------------------Space Radar ---------------------------------------------------

float radar_angle1 = 0;
float radar_angle2 = 0;
float satelite_angle1 = 30.0f;

void spaceRadar()
{

//radar body
glPushMatrix();
glTranslatef(0,20,0);
glBegin(GL_QUADS);
glColor3ub(210,105,30);
glVertex2d(-150,100);
glVertex2d(-150,70);
glVertex2d(-130,70);
glVertex2d(-130,100);
glEnd();
glPushMatrix();
glTranslatef(0,-20,0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2d(-180,105);
glVertex2d(-100,105);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0,-20,0);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2d(-140,145);
glVertex2d(-140,65);
glEnd();
glPopMatrix();
glPopMatrix();

//radar hands
glPushMatrix();

glTranslatef(-140,105,0);
glRotatef(radar_angle1, 0.0f, 0.0f,1.0f);
glLineWidth(3);

glBegin(GL_LINES);
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=40;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();


glBegin(GL_LINES);
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=30;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}

glEnd();



glBegin(GL_LINES);
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=20;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();

glBegin(GL_LINES);
for(int i=0;i<200;i++)
{
glColor3ub(255,255,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=10;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();


glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0,0,128);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=7;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();



glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=3;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();

glPopMatrix();
glFlush();
}



void radarUpdate1(int value) {

 radar_angle1+=1.0f;
if(radar_angle1 > 360.0)
{
radar_angle1-=360;
}
glutPostRedisplay();

 glutTimerFunc(20, radarUpdate1, 0);
}

void radarUpdate2(int value) {

 radar_angle2+=1.0f;
if(radar_angle2 > 360.0)
{
radar_angle2-=360;
}
glutPostRedisplay();

 glutTimerFunc(20, radarUpdate2, 0);
}


//-------------------------------Stars---------------------------------------------------------


//-----------------background color------------------------------------------
void bac(){

glBegin(GL_POLYGON);
//back color test
glColor3ub(0,0,95);
glVertex2f(-200.0f,0.0f);
glVertex2f(200.0f,0.0f);
glVertex2f(200.0f,480.0f);
glVertex2f(-200.0f,480.0f);

glEnd();

}

//-------------------------------------Planet X------------------------------------------

void planetX()
{
glPushMatrix();
glTranslatef(-100,350,0);
glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin

for(int i=0;i<200;i++)
{
glColor3ub(255,165,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=32;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
//small circles under the skin of the planetX
glPushMatrix();
glTranslatef(-110,370,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor3ub(255,0,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=5;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-96,350,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,50);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=4;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-80,350,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=4;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-120,340,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=4;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-100,325,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=3;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-110,340,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=2;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-95,370,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=3;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-122,360,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=4;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-85,330,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=2;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-82,370,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor4ub(255,0,0,100);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=2;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

}
//---------------------------------Astronaut-------------------------------------------------------
float astronautPositionX = 0.0f;
float astronautPositionY = 0.0f;
float astronautSpeed =0.0f;

void moveAstronautLeft(int val);

void moveAstronautRight (int val)
{

    if(astronautPositionX>=70 ){
        astronautPositionX=70;
        astronautSpeed=0.0f;
    }

   astronautPositionX+=astronautSpeed;


	//glutTimerFunc(30,moveAstronautRight,0);
}



void moveAstronautLeft (int val)
{

    if(astronautPositionX<=-100 ){
            astronautPositionX=-100;
            astronautSpeed=0;
    }

   astronautPositionX-=astronautSpeed;

	//glutTimerFunc(30,moveAstronautLeft,0);
}


void moveAstronautDown (int val)
{

    if(astronautPositionY<=-50){
            astronautPositionY=-50;
            astronautSpeed=0;
    }

   astronautPositionY-=astronautSpeed;

	//glutTimerFunc(30,moveAstronautDown,0);
}

void moveAstronautUp (int val)
{

    if(astronautPositionY>=100 ){
            astronautPositionY=100;
            astronautSpeed=0;
    }

   astronautPositionY+=astronautSpeed;


	//glutTimerFunc(30,moveAstronautUp,0);
}




void astronaut()
{

//upper body
glPushMatrix();
glTranslatef(astronautPositionX,astronautPositionY,0.0f);
glPushMatrix();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(98,350);
glVertex2d(95,330);
glVertex2d(105,330);
glVertex2d(102,350);
glEnd();
glPopMatrix();

//lower body

glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(95,330);
glVertex2d(98,310);
glVertex2d(102,310);
glVertex2d(105,330);
glEnd();
glPopMatrix();

//left leg
glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(98,310);
glVertex2d(96,306);
glVertex2d(99,306);
glVertex2d(99,310);
glEnd();
glPopMatrix();

//right leg
glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(101,310);
glVertex2d(99,306);
glVertex2d(102,306);
glVertex2d(102,310);
glEnd();
glPopMatrix();

//left hand
glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(98,346);
glVertex2d(90,338);
glVertex2d(92,334);
glVertex2d(95,336);
glEnd();
glPopMatrix();

//right hand
glPushMatrix();
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2d(102,346);
glVertex2d(110,338);
glVertex2d(108,334);
glVertex2d(105,336);
glEnd();
glPopMatrix();


//space between legs
glPushMatrix();
glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2d(100,325);
glVertex2d(99,310);
glVertex2d(101,310);
glEnd();
glPopMatrix();


//face
glPushMatrix();
glTranslatef(100,350,0);
glBegin(GL_POLYGON);

for(int i=0;i<200;i++)
{
glColor3ub(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=6;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glBegin(GL_POLYGON);

for(int i=0;i<2000;i++)
{
glColor3ub(0,0,0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=3;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();


//decoration
glPushMatrix();
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2d(95,330);
glVertex2d(105,330);
glEnd();
glPopMatrix();
glPopMatrix();

}

void SpecialInput(int key, int x, int y)
{
switch(key)
{

case GLUT_KEY_LEFT:

    astronautSpeed=2.0f;

  glutTimerFunc(30,moveAstronautLeft,0);
break;
case GLUT_KEY_RIGHT:

    astronautSpeed=2.0f;

  glutTimerFunc(30,moveAstronautRight,0);

break;
case GLUT_KEY_UP:
    astronautSpeed=1.0f;
    glutTimerFunc(30,moveAstronautUp,0);
    break;
case GLUT_KEY_DOWN:
    astronautSpeed=1.0f;
    glutTimerFunc(30,moveAstronautDown,0);
    break;
}
glutPostRedisplay();
}

//---------------------------------- Satelite---------------------------------------------------------

void satelite()
{

 glPushMatrix();
glTranslatef(140,-80,0);
 glPushMatrix();
 glRotatef(satelite_angle1,0.0f,1.0f,0.0f);
 glTranslatef(-140,-100,0);


glPushMatrix();
glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(135,470);
 glVertex2d(135,480);
 glVertex2d(145,480);
 glVertex2d(145,470);
 glEnd();

 //body

 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(130,470);
 glVertex2d(130,420);
 glVertex2d(150,420);
 glVertex2d(150,470);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(138,420);
 glVertex2d(138,410);
 glVertex2d(142,410);
 glVertex2d(142,420);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(138,410);
 glVertex2d(130,400);
 glVertex2d(150,400);
 glVertex2d(142,410);
 glEnd();

 //left sidebar
 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(130,450);
 glVertex2d(125,450);
 glVertex2d(125,440);
 glVertex2d(130,440);
 glEnd();
 glPopMatrix();
 //left hands
 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(125,458);
 glVertex2d(95,458);
 glVertex2d(95,432);
 glVertex2d(125,432);
 glEnd();

 //right sidebar
 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(130,450);
 glVertex2d(155,450);
 glVertex2d(155,440);
 glVertex2d(130,440);
 glEnd();
 //right hand
 glBegin(GL_QUADS);
 glColor3ub(176,196,222);
 glVertex2d(155,458);
 glVertex2d(185,458);
 glVertex2d(185,432);
 glVertex2d(155,432);
 glEnd();


 //decoration
 glBegin(GL_LINES);
 glLineWidth(5.0);
 glColor3ub(0,0,0);
 glVertex2d(135,465);
 glVertex2d(135,425);
 glVertex2d(145,425);
 glVertex2d(145,465);
 glEnd();
 //left hand decoration

 glBegin(GL_LINES);
 glColor3ub(0,0,0);
 glVertex2d(105,458);
 glVertex2d(105,432);
 glVertex2d(120,458);
 glVertex2d(120,432);
 glVertex2d(95,450);
 glVertex2d(125,450);
 glVertex2d(95,440);
 glVertex2d(125,440);
 glEnd();

 //right hand decoration
 glBegin(GL_LINES);
 glColor3ub(0,0,0);
 glVertex2d(160,458);
 glVertex2d(160,432);
 glVertex2d(175,458);
 glVertex2d(175,432);
 glVertex2d(155,450);
 glVertex2d(185,450);
 glVertex2d(155,440);
 glVertex2d(185,440);
 glEnd();
    glPopMatrix();






 glPopMatrix();
 glPopMatrix();

}

void sateliteUpdate(int val)
{
    satelite_angle1 +=2.0f;
    if(satelite_angle1 >= 360)
    {
        satelite_angle1 -=360;
    }
    glutPostRedisplay();
    glutTimerFunc(20,sateliteUpdate,0);
}


//-----------------------------------------------Rocket-------------------------------------------------
void rocket(){


glBegin(GL_POLYGON);
//rocket black tail
glColor3ub(0, 0, 0);
glVertex2f(-4.0f,134.0f);
glVertex2f(-8.0f,120.0f);
glVertex2f(8.0f,120.0f);
glVertex2f(4.0f,134.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket body rectangle3
glColor3ub(160, 160, 160);
glVertex2f(-8.0f,180.0f);
glVertex2f(-8.0f,134.0f);
glVertex2f(8.0f,134.0f);
glVertex2f(8.0f,180.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket body rectangle 2 & 3 join
glColor3ub(0, 0, 0);
glVertex2f(-6.0f,182.0f);
glVertex2f(-6.0f,180.0f);
glVertex2f(6.0f,180.0f);
glVertex2f(6.0f,182.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket body rectangle2
glColor3ub(160, 160, 160);
glVertex2f(-6.0f,220.0f);
glVertex2f(-6.0f,182.0f);
glVertex2f(6.0f,182.0f);
glVertex2f(6.0f,220.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket body rectangle 1 & 2 join
glColor3ub(0, 0, 0);
glVertex2f(-4.0f,224.0f);
glVertex2f(-4.0f,220.0f);
glVertex2f(4.0f,220.0f);
glVertex2f(4.0f,224.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket body rectangle1
glColor3ub(160, 160, 160);
glVertex2f(-4.0f,260.0f);
glVertex2f(-4.0f,224.0f);
glVertex2f(4.0f,224.0f);
glVertex2f(4.0f,260.0f);
glEnd();

glBegin(GL_POLYGON);
//rocket head part 2
glColor3ub(0, 0, 0);
glVertex2f(-2.0f,266.0f);
glVertex2f(-4.0f,260.0f);
glVertex2f(4.0f,260.0f);
glVertex2f(2.0f,266.0f);
glEnd();

glBegin(GL_TRIANGLES);
//rocket head part 1
glColor3ub(160, 160, 160);
glVertex2f(0.0f,274.0f);
glVertex2f(-2.0f,266.0f);
glVertex2f(2.0f,266.0f);
glEnd();

glBegin(GL_TRIANGLES);
//rocket right wing
glColor3ub(0, 0, 0);
glVertex2f(8.0f,160.0f);
glVertex2f(8.0f,140.0f);
glVertex2f(20.0f,140.0f);
glEnd();

glBegin(GL_TRIANGLES);
//rocket rleft wing
glColor3ub(0, 0, 0);
glVertex2f(-8.0f,160.0f);
glVertex2f(-20.0f,140.0f);
glVertex2f(-8.0f,140.0f);
glEnd();

glBegin(GL_LINES);
//rocket flames
glColor3ub(255, 0, 0);
glVertex2f(-6.0f,120.0f);
glVertex2f(-6.0f,106.0f);
glVertex2f(-4.0f,120.0f);
glVertex2f(-4.0f,106.0f);
glVertex2f(-2.0f,120.0f);
glVertex2f(-2.0f,104.0f);
glVertex2f(6.0f,120.0f);
glVertex2f(6.0f,106.0f);
glVertex2f(4.0f,120.0f);
glVertex2f(4.0f,106.0f);
glVertex2f(2.0f,120.0f);
glVertex2f(2.0f,104.0f);
glVertex2f(0.0f,120.0f);
glVertex2f(0.0f,100.0f);

//rocket name NASA
glColor3ub(0, 0, 0);
glVertex2f(-4.0f,218.0f);
glVertex2f(-4.0f,210.0f);
glVertex2f(-4.0f,218.0f);
glVertex2f(4.0f,210.0f);
glVertex2f(4.0f,218.0f);
glVertex2f(4.0f,210.0f);

glVertex2f(0.0f,208.0f);
glVertex2f(-4.0f,200.0f);
glVertex2f(0.0f,208.0f);
glVertex2f(4.0f,200.0f);
glVertex2f(-2.0f,204.0f);
glVertex2f(2.0f,204.0f);

glVertex2f(4.0f,198.0f);
glVertex2f(-4.0f,198.0f);
glVertex2f(-4.0f,198.0f);
glVertex2f(-4.0f,194.0f);
glVertex2f(-4.0f,194.0f);
glVertex2f(4.0f,194.0f);
glVertex2f(4.0f,194.0f);
glVertex2f(4.0f,190.0f);
glVertex2f(4.0f,190.0f);
glVertex2f(-4.0f,190.0f);

glVertex2f(0.0f,190.0f);
glVertex2f(-4.0f,182.0f);
glVertex2f(0.0f,190.0f);
glVertex2f(4.0f,182.0f);
glVertex2f(-2.0f,186.0f);
glVertex2f(2.0f,186.0f);

glEnd();

glBegin(GL_POLYGON);
//bd flag green
glColor3ub(0, 153, 0);
glVertex2f(6.0f,176.0f);
glVertex2f(-6.0f,176.0f);
glVertex2f(-6.0f,138.0f);
glVertex2f(6.0f,138.0f);
glEnd();


//bd flag red
	glColor3ub(255,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.85;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y+160 );
        }

	glEnd();


	//bd flag red
	glColor3ub(0,0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.85;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y+245 );
        }

	glEnd();

	glFlush();


}

// -------------------------------------------Display-------------------------------------------

void faisalDisplay() {

glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
//glColor3d(1,0,0);
glMatrixMode(GL_MODELVIEW);
glLineWidth(1.0);
bac();
//backStars();

rocket();
astronaut();
planetX();
spaceRadar();
satelite();

 // Render now

glutSwapBuffers();
}

void init() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glLoadIdentity();
gluOrtho2D(-200,200,0,480);
}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1920,1080);
glutCreateWindow("Display 4"); // Create a window with the given title
init();
 glutSpecialFunc(SpecialInput);
glutDisplayFunc(faisalDisplay);
glutTimerFunc(20, radarUpdate1, 0);
glutTimerFunc(20,radarUpdate2,0);
glutTimerFunc(20,sateliteUpdate,0);
glutTimerFunc(20,moveAstronautLeft,0);
glutMainLoop(); // Enter the event-processing loop
return 0;
}
