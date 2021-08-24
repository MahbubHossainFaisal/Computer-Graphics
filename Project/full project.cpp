#include <windows.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
# define PI 3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void dis();
void display1();
void display3();
void disRaihan();

//Faysal
float satelite_angle1 = 30.0f;
float starPositionX = 1.0f;
float starPositionY = 1.0f;
float starSpeedX = 1.0f;
float starSpeedY = 1.0f;

float radar_angle1 = 0;
float radar_angle2 = 0;

float astronautPositionX = 0.0f;
float astronautPositionY = 0.0f;
float astronautSpeed =0.0f;


//tasfia
float PlanetAngle = 0.0f;
GLfloat r = 0.0f;

//raihan
GLfloat Rocketposition = 0.0f;

GLfloat SootingStar1Position = 0.0f;

GLfloat SootingStar2Position = 0.0f;

GLfloat RocketSpeed = 5.1f;
GLfloat SootingStarSpeed = 6.0f;
float bulbAngle = 0.0f;
float MoonAngle = 0.0f;
float PlanetZAngle = 0.0f;

//tanim
float angle1 = 0.0f;
float yaxis=460.0;
float xaxis=-190.0;

//tanim update
void circle_round(int value) //TU1
{
    angle1-=2.0f;
    if(angle1 < 360.0) angle1+=360;
    glutPostRedisplay();
    glutTimerFunc(2,circle_round, 0);

}

void Movement_of_star(int value)//TU2
{
   glutPostRedisplay();
   glutTimerFunc(10,Movement_of_star, 0);
   if(xaxis<200) xaxis+=0.60;
   if(xaxis>200) xaxis=-200;

}

//tasfia update

void PlanetRotate(int value)//MU1
 {

 PlanetAngle+=20.21f;
if(PlanetAngle > 360.0)
{
PlanetAngle-=360;
}
glutPostRedisplay(); //Notify GLUT that the display has changed

 glutTimerFunc(70, PlanetRotate, 0); //Notify GLUT to call update again in 25 milliseconds

}



//raihan updates

void moonUpdate(int value)//RU1
{
    MoonAngle-=2.0f;
    if(MoonAngle < 360.0) MoonAngle+=360;
    glutPostRedisplay();
    glutTimerFunc(2,moonUpdate, 0);

}


void PlanetZUpdate(int value)//RU2
{
    PlanetZAngle-=2.0f;
    if(PlanetZAngle < 360.0) PlanetZAngle+=360;
    glutPostRedisplay();
    glutTimerFunc(2,PlanetZUpdate, 0);

}


void SootingStar1Update(int value)//RU3
 {

if(SootingStar1Position >400.0)
        SootingStar1Position = -20.5f;

    SootingStar1Position += SootingStarSpeed;

	glutPostRedisplay();

	glutTimerFunc(100,SootingStar1Update,0);
}



void SootingStar2Update(int value)//RU4
 {

      if(SootingStar2Position <-400.0)
        SootingStar2Position = 60.0f;

    SootingStar2Position -= SootingStarSpeed;

	glutPostRedisplay();

	glutTimerFunc(100,SootingStar2Update,0);
}


void RocketUpdate(int value) //RU5
{

    if(Rocketposition >480.0)
        Rocketposition = -25.0f;

    Rocketposition += RocketSpeed;

	glutPostRedisplay();

	glutTimerFunc(100,RocketUpdate,0);
}


void LeftBulbUpdate(int value) //RU6
{

 bulbAngle+=20.21f;
if(bulbAngle > 360.0)
{
bulbAngle-=360;
}
glutPostRedisplay(); //Notify GLUT that the display has changed

 glutTimerFunc(70, LeftBulbUpdate, 0); //Notify GLUT to call update again in 25 milliseconds
}

//faysal update

void radarUpdate1(int value) //FU1

{

 radar_angle1+=1.0f;
if(radar_angle1 > 360.0)
{
radar_angle1-=360;
}
glutPostRedisplay();

 glutTimerFunc(20, radarUpdate1, 0);
}

void radarUpdate2(int value) //FU2
{

 radar_angle2+=1.0f;
if(radar_angle2 > 360.0)
{
radar_angle2-=360;
}
glutPostRedisplay();

 glutTimerFunc(20, radarUpdate2, 0);
}

void moveShootingStar(int val)//FU3
{
    if(starPositionX>=500 || starPositionY>=1000){
        starPositionX=1.0f;
        starPositionY=1.0f;
    }
    starPositionX+=starSpeedX;
    starPositionY+=starSpeedY;
    glutPostRedisplay();
    glutTimerFunc(20,moveShootingStar,0);
}

void moveAstronautLeft(int val);

void moveAstronautRight (int val)//FU11
{

    if(astronautPositionX>=70 ){
        astronautPositionX=70;
        astronautSpeed=0.0f;
    }

   astronautPositionX+=astronautSpeed;


	//glutTimerFunc(30,moveAstronautRight,0);
}



void moveAstronautLeft (int val)//FU12
{

    if(astronautPositionX<=-100 ){
            astronautPositionX=-100;
            astronautSpeed=0;
    }

   astronautPositionX-=astronautSpeed;

	//glutTimerFunc(30,moveAstronautLeft,0);
}

void moveAstronautDown (int val)//FU13
{

    if(astronautPositionY<=-50){
            astronautPositionY=-50;
            astronautSpeed=0;
    }

   astronautPositionY-=astronautSpeed;

	//glutTimerFunc(30,moveAstronautDown,0);
}

void moveAstronautUp (int val)//FU14
{

    if(astronautPositionY>=100 ){
            astronautPositionY=100;
            astronautSpeed=0;
    }

   astronautPositionY+=astronautSpeed;


	//glutTimerFunc(30,moveAstronautUp,0);
}

void sateliteUpdate(int val)//FU4
{
    satelite_angle1 +=3.0f;
    if(satelite_angle1 >= 360)
    {
        satelite_angle1 -=360;
    }
    glutPostRedisplay();
    glutTimerFunc(40,sateliteUpdate,0);
}




//faysal object

void Back()// F1
{

    glPushMatrix();
    //back for display 3&4
     glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-200,0);
    glVertex2f(200,0);
    glVertex2f(200,480);
    glVertex2f(-200,480);
    glEnd();
    glPopMatrix();

}

void shootingStar()//F2
{
    glPushMatrix();
    glTranslatef(starPositionX,starPositionY,0.0f);
    glPushMatrix();
    //first
     glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2f(-220,34);
    glVertex2f(-250,6);
    glVertex2f(-220,26);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
    glColor3ub(255,215,0);
    float pi=3.1416;
    float A=(i*2*pi)/200;
    float r=4;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x-220,y+30);
    }
    glEnd();
    //second

    //third
 glBegin(GL_TRIANGLES);
    glColor3ub(255,255,0);
    glVertex2f(-220,14);
    glVertex2f(-250,-22);
    glVertex2f(-220,6);
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
    glColor3ub(255,215,0);
    float pi=3.1416;
    float A=(i*2*pi)/200;
    float r=4;
    float x = r * cos(A);
    float y = r * sin(A);
    glVertex2f(x-220,y+10);
    }
    glEnd();


    glPopMatrix();
    glPopMatrix();
}


void spaceRadar()//F3
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
glColor3ub(255,255,255);
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
glColor3ub(255,255,255);
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
glColor3ub(255,255,255);
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
glColor3ub(255,255,255);
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

}


void backStars()//F4
{

glPushMatrix();
//back stars
glPointSize(3);
glBegin(GL_POINTS);
glColor3ub(255,255 ,255);

glVertex2f(-160.0f,460.0f);
glVertex2f(-150.0f,450.0f);
glVertex2f(-140.0f,350.0f);
glVertex2f(-170.0f,360.0f);
glVertex2f(-150.0f,360.0f);
glVertex2f(170.0f,360.0f);
glVertex2f(-175.0f,355.0f);
glVertex2f(180.0f,355.0f);
glVertex2f(-20.0f,370.0f);
glVertex2f(-30.0f,360.0f);
glVertex2f(0.0f,375.0f);
glVertex2f(-10.0f,390.0f);
glVertex2f(-70.0f,340.0f);
glVertex2f(20.0f,355.0f);
glVertex2f(-35.0f,460.0f);
glVertex2f(37.0f,470.0f);
glVertex2f(21.0f,442.0f);
glVertex2f(-5.0f,384.0f);
glVertex2f(200.0f,320.0f);
glVertex2f(180.0f,320.0f);
glVertex2f(160.0f,320.0f);
glVertex2f(140.0f,320.0f);
glVertex2f(120.0f,320.0f);
glVertex2f(100.0f,320.0f);
glVertex2f(80.0f,320.0f);
glVertex2f(60.0f,320.0f);
glVertex2f(40.0f,320.0f);
glVertex2f(20.0f,320.0f);
glVertex2f(0.0f,320.0f);
glVertex2f(-20.0f,322.0f);
glVertex2f(-40.0f,320.0f);
glVertex2f(-60.0f,323.0f);
glVertex2f(-80.0f,321.0f);
glVertex2f(-100.0f,324.0f);
glVertex2f(-120.0f,321.0f);
glVertex2f(-140.0f,322.0f);
glVertex2f(-160.0f,324.0f);
glVertex2f(-180.0f,323.0f);
glVertex2f(-200.0f,321.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(140.0f,380.0f);
glVertex2f(145.0f,390.0f);
glVertex2f(155.0f,375.0f);
glVertex2f(80.0f,345.0f);
glVertex2f(85.0f,355.0f);
glVertex2f(-120.0f,400.0f);
glVertex2f(-120.0f,440.0f);
glVertex2f(-110.0f,460.0f);
glVertex2f(120.0f,460.0f);
glVertex2f(160.0f,460.0f);
glVertex2f(120.0f,420.0f);
glVertex2f(160.0f,420.0f);
glVertex2f(140.0f,440.0f);
glVertex2f(-140.0f,420.0f);
glVertex2f(-100.0f,420.0f);
glVertex2f(-140.0f,380.0f);
glVertex2f(-100.0f,380.0f);
glVertex2f(-20.0f,420.0f);
glVertex2f(-60.0f,420.0f);
glVertex2f(-60.0f,380.0f);
glVertex2f(-20.0f,380.0f);
glVertex2f(-40.0f,400.0f);
glVertex2f(-80.0f,400.0f);
glVertex2f(-190.0f,420.0f);
glVertex2f(-190.0f,380.0f);
glVertex2f(-160.0f,380.0f);
glVertex2f(-160.0f,420.0f);
glVertex2f(-176.0f,400.0f);
glVertex2f(-190.0f,460.0f);
glVertex2f(-190.0f,440.0f);
glVertex2f(-170.0f,440.0f);
glVertex2f(-170.0f,460.0f);
glVertex2f(-110.0f,470.0f);
glVertex2f(-110.0f,450.0f);
glVertex2f(-90.0f,450.0f);
glVertex2f(-90.0f,470.0f);
glVertex2f(-100.0f,460.0f);
glVertex2f(-110.0f,330.0f);
glVertex2f(-110.0f,350.0f);
glVertex2f(-130.0f,350.0f);
glVertex2f(-130.0f,330.0f);
glVertex2f(-120.0f,340.0f);
glVertex2f(-120.0f,360.0f);
glVertex2f(-125.0f,380.0f);
glVertex2f(-180.0f,340.0f);
glVertex2f(-175.0f,360.0f);
glVertex2f(-190.0f,360.0f);
glVertex2f(-195.0f,335.0f);
glVertex2f(-150.0f,400.0f);
glVertex2f(60.0f,380.0f);
glVertex2f(80.0f,380.0f);
glVertex2f(60.0f,360.0f);
glVertex2f(80.0f,360.0f);
glVertex2f(70.0f,370.0f);
glVertex2f(70.0f,410.0f);
glVertex2f(70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(90.0f,410.0f);
glVertex2f(80.0f,400.0f);
glVertex2f(60.0f,450.0f);
glVertex2f(80.0f,450.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(70.0f,460.0f);
glVertex2f(60.0f,470.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(40.0f,450.0f);
glVertex2f(30.0f,460.0f);
glVertex2f(50.0f,460.0f);
glVertex2f(140.0f,470.0f);
glVertex2f(140.0f,410.0f);
glVertex2f(170.0f,440.0f);
glVertex2f(190.0f,430.0f);
glVertex2f(190.0f,450.0f);
glVertex2f(180.0f,420.0f);
glVertex2f(170.0f,410.0f);
glVertex2f(190.0f,400.0f);
glVertex2f(180.0f,380.0f);
glVertex2f(170.0f,370.0f);
glVertex2f(-10.0f,470.0f);
glVertex2f(-10.0f,450.0f);
glVertex2f(10.0f,470.0f);
glVertex2f(10.0f,450.0f);
glVertex2f(0.0f,460.0f);
glVertex2f(-10.0f,430.0f);
glVertex2f(-10.0f,410.0f);
glVertex2f(10.0f,430.0f);
glVertex2f(10.0f,410.0f);
glVertex2f(0.0f,420.0f);
glVertex2f(0.0f,440.0f);
glVertex2f(90.0f,360.0f);
glVertex2f(110.0f,360.0f);
glVertex2f(90.0f,340.0f);
glVertex2f(110.0f,340.0f);
glVertex2f(100.0f,350.0f);
glVertex2f(-20.0f,360.0f);
glVertex2f(-20.0f,340.0f);
glVertex2f(-10.0f,350.0f);
glVertex2f(0.0f,340.0f);
glVertex2f(0.0f,360.0f);
glVertex2f(-10.0f,370.0f);
glVertex2f(-10.0f,330.0f);
glVertex2f(30.0f,420.0f);
glVertex2f(50.0f,420.0f);
glVertex2f(30.0f,400.0f);
glVertex2f(50.0f,400.0f);
glVertex2f(40.0f,410.0f);
glVertex2f(30.0f,380.0f);
glVertex2f(50.0f,380.0f);
glVertex2f(30.0f,360.0f);
glVertex2f(50.0f,360.0f);
glVertex2f(40.0f,370.0f);
glVertex2f(20.0f,340.0f);
glVertex2f(40.0f,340.0f);
glVertex2f(60.0f,340.0f);
glVertex2f(10.0f,390.0f);
glVertex2f(10.0f,370.0f);
glVertex2f(10.0f,350.0f);
glVertex2f(10.0f,330.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(160.0f,350.0f);
glVertex2f(160.0f,330.0f);
glVertex2f(150.0f,340.0f);
glVertex2f(190.0f,350.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(210.0f,350.0f);
glVertex2f(210.0f,330.0f);
glVertex2f(200.0f,340.0f);
glVertex2f(120.0f,380.0f);
glVertex2f(130.0f,360.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(110.0f,390.0f);
glVertex2f(110.0f,410.0f);
glVertex2f(100.0f,420.0f);
glVertex2f(110.0f,430.0f);
glVertex2f(110.0f,450.0f);
glVertex2f(100.0f,460.0f);
glVertex2f(110.0f,470.0f);
glVertex2f(90.0f,470.0f);
glVertex2f(94.0f,442.0f);
glVertex2f(-40.0f,380.0f);
glVertex2f(-50.0f,360.0f);
glVertex2f(-50.0f,340.0f);
glVertex2f(-36.0f,346.0f);
glVertex2f(-90.0f,370.0f);
glVertex2f(-90.0f,350.0f);
glVertex2f(-70.0f,370.0f);
glVertex2f(-70.0f,350.0f);
glVertex2f(-80.0f,360.0f);
glVertex2f(-70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(80.0f,346.0f);
glVertex2f(-40.0f,460.0f);
glVertex2f(-50.0f,450.0f);
glVertex2f(-60.0f,470.0f);

//lower mid
glVertex2f(-60,10);
glVertex2f(-70,20);
glVertex2f(-90,80);
glVertex2f(-100,120);
glVertex2f(-160,10);
glVertex2f(-190,20);
glVertex2f(-60,20);
glVertex2f(-70,30);
glVertex2f(-90,90);
glVertex2f(-60,10);
glVertex2f(-20,20);
glVertex2f(-110,30);
glVertex2f(-60,10);
glVertex2f(-70,20);
glVertex2f(-90,80);
//between -200,50 to 200,50
glVertex2f(-190,50);glVertex2f(-190,40);
glVertex2f(-190,35);glVertex2f(-188,40);
glVertex2f(-180,50);glVertex2f(-180,30);
glVertex2f(-180,20);
glVertex2f(-170,40);glVertex2f(-170,20);
glVertex2f(-170,10);glVertex2f(-160,20);
glVertex2f(-160,25);
glVertex2f(-160,40);glVertex2f(-150,10);glVertex2f(-150,25);
glVertex2f(-150,45);glVertex2f(-150,55);
glVertex2f(-140,5);glVertex2f(-140,40);glVertex2f(-140,40);glVertex2f(-140,20);
glVertex2f(-130,40);glVertex2f(-120,50);
glVertex2f(-110,30);glVertex2f(-90,40);
glVertex2f(-90,50);glVertex2f(-70,40);
glVertex2f(-70,20);glVertex2f(-70,80);
glVertex2f(-160,40);glVertex2f(-160,40);glVertex2f(-160,40);
glVertex2f(-160,25);glVertex2f(-130,40);glVertex2f(-110,40);
glVertex2f(-160,210);glVertex2f(-120,180);glVertex2f(-160,140);
glVertex2f(-160,250);glVertex2f(-100,220);glVertex2f(-110,130);
glVertex2f(-160,120);glVertex2f(-160,40);glVertex2f(-160,140);
glVertex2f(-160,150);glVertex2f(-160,170);glVertex2f(-160,240);
glVertex2f(-120,150);glVertex2f(-120,170);glVertex2f(-120,240);
glVertex2f(-100,150);glVertex2f(-100,170);glVertex2f(-100,240);

glVertex2f(-160.0f,60.0f);
glVertex2f(-150.0f,50.0f);
glVertex2f(-140.0f,50.0f);
glVertex2f(-170.0f,60.0f);
glVertex2f(-150.0f,160.0f);
glVertex2f(170.0f,160.0f);
glVertex2f(-175.0f,255.0f);
glVertex2f(180.0f,155.0f);
glVertex2f(-20.0f,270.0f);
glVertex2f(-30.0f,260.0f);
glVertex2f(0.0f,175.0f);
glVertex2f(-10.0f,110.0f);
glVertex2f(-70.0f,140.0f);
glVertex2f(20.0f,155.0f);
glVertex2f(-35.0,160.0f);
glVertex2f(37.0f,170.0f);
glVertex2f(21.0f,142.0f);
glVertex2f(-5.0f,184.0f);
glVertex2f(200.0f,120.0f);
glVertex2f(180.0f,120.0f);
glVertex2f(160.0f,120.0f);
glVertex2f(140.0f,220.0f);
glVertex2f(120.0f,120.0f);
glVertex2f(100.0f,120.0f);
glVertex2f(80.0f,220.0f);
glVertex2f(60.0f,220.0f);
glVertex2f(40.0f,120.0f);
glVertex2f(20.0f,120.0f);
glVertex2f(0.0f,120.0f);
glVertex2f(-20.0f,322.0f);
glVertex2f(-40.0f,220.0f);
glVertex2f(-60.0f,223.0f);
glVertex2f(-80.0f,221.0f);
glVertex2f(-100.0f,224.0f);
glVertex2f(-120.0f,221.0f);
glVertex2f(-140.0f,222.0f);
glVertex2f(-160.0f,224.0f);
glVertex2f(-180.0f,223.0f);
glVertex2f(-200.0f,121.0f);
glVertex2f(190.0f,130.0f);
glVertex2f(140.0f,80.0f);
glVertex2f(145.0f,190.0f);
glVertex2f(155.0f,175.0f);
glVertex2f(80.0f,145.0f);
glVertex2f(85.0f,155.0f);
glVertex2f(-120.0f,100.0f);
glVertex2f(-120.0f,140.0f);
glVertex2f(-110.0f,160.0f);
glVertex2f(120.0f,60.0f);
glVertex2f(160.0f,160.0f);
glVertex2f(120.0f,120.0f);
glVertex2f(160.0f,120.0f);
glVertex2f(140.0f,140.0f);
glVertex2f(-140.0f,220.0f);
glVertex2f(-100.0f,120.0f);
glVertex2f(-140.0f,180.0f);
glVertex2f(-100.0f,180.0f);
glVertex2f(-20.0f,120.0f);
glVertex2f(-60.0f,220.0f);
glVertex2f(-60.0f,280.0f);
glVertex2f(-20.0f,180.0f);
glVertex2f(-40.0f,200.0f);
glVertex2f(-80.0f,100.0f);
glVertex2f(-190.0f,120.0f);
glVertex2f(-190.0f,180.0f);
glVertex2f(-160.0f,280.0f);
glVertex2f(-160.0f,220.0f);
glVertex2f(-176.0f,200.0f);
glVertex2f(-190.0f,260.0f);
glVertex2f(-190.0f,140.0f);
glVertex2f(-170.0f,140.0f);
glVertex2f(-170.0f,260.0f);
glVertex2f(-110.0f,270.0f);
glVertex2f(-110.0f,250.0f);
glVertex2f(-90.0f,150.0f);
glVertex2f(-90.0f,370.0f);
glVertex2f(-100.0f,160.0f);
glVertex2f(-110.0f,130.0f);
glVertex2f(-110.0f,150.0f);
glVertex2f(-130.0f,150.0f);
glVertex2f(-130.0f,130.0f);
glVertex2f(-120.0f,140.0f);
glVertex2f(-120.0f,60.0f);
glVertex2f(-125.0f,180.0f);
glVertex2f(-180.0f,40.0f);
glVertex2f(-175.0f,60.0f);
glVertex2f(-190.0f,60.0f);
glVertex2f(-195.0f,135.0f);
glVertex2f(-150.0f,200.0f);
glVertex2f(60.0f,180.0f);
glVertex2f(80.0f,80.0f);
glVertex2f(60.0f,60.0f);
glVertex2f(80.0f,60.0f);
glVertex2f(70.0f,70.0f);
glVertex2f(70.0f,110.0f);
glVertex2f(70.0f,190.0f);
glVertex2f(90.0f,190.0f);
glVertex2f(90.0f,10.0f);
glVertex2f(80.0f,100.0f);
glVertex2f(60.0f,50.0f);
glVertex2f(80.0f,50.0f);
glVertex2f(60.0f,130.0f);
glVertex2f(80.0f,230.0f);
glVertex2f(70.0f,240.0f);
glVertex2f(70.0f,260.0f);
glVertex2f(60.0f,270.0f);
glVertex2f(60.0f,130.0f);
glVertex2f(80.0f,230.0f);
glVertex2f(70.0f,140.0f);
glVertex2f(40.0f,150.0f);
glVertex2f(30.0f,160.0f);
glVertex2f(50.0f,160.0f);
glVertex2f(140.0f,170.0f);
glVertex2f(140.0f,110.0f);
glVertex2f(170.0f,140.0f);
glVertex2f(190.0f,30.0f);
glVertex2f(190.0f,150.0f);
glVertex2f(180.0f,20.0f);
glVertex2f(170.0f,10.0f);
glVertex2f(190.0f,100.0f);
glVertex2f(180.0f,280.0f);
glVertex2f(170.0f,170.0f);
glVertex2f(-10.0f,170.0f);
glVertex2f(-10.0f,50.0f);
glVertex2f(10.0f,70.0f);
glVertex2f(10.0f,50.0f);
glVertex2f(0.0f,60.0f);
glVertex2f(-10.0f,30.0f);
glVertex2f(-10.0f,10.0f);
glVertex2f(10.0f,30.0f);
glVertex2f(10.0f,10.0f);
glVertex2f(0.0f,20.0f);
glVertex2f(0.0f,40.0f);
glVertex2f(90.0f,160.0f);
glVertex2f(110.0f,160.0f);
glVertex2f(90.0f,40.0f);
glVertex2f(110.0f,140.0f);
glVertex2f(100.0f,50.0f);
glVertex2f(-20.0f,160.0f);
glVertex2f(-20.0f,140.0f);
glVertex2f(-10.0f,150.0f);
glVertex2f(0.0f,140.0f);
glVertex2f(0.0f,160.0f);
glVertex2f(-10.0f,170.0f);
glVertex2f(-10.0f,130.0f);
glVertex2f(30.0f,120.0f);
glVertex2f(50.0f,120.0f);
glVertex2f(30.0f,200.0f);
glVertex2f(50.0f,100.0f);
glVertex2f(40.0f,210.0f);
glVertex2f(30.0f,280.0f);
glVertex2f(50.0f,280.0f);
glVertex2f(30.0f,160.0f);
glVertex2f(50.0f,160.0f);
glVertex2f(40.0f,170.0f);
glVertex2f(20.0f,140.0f);
glVertex2f(40.0f,140.0f);
glVertex2f(60.0f,140.0f);
glVertex2f(10.0f,190.0f);
glVertex2f(10.0f,170.0f);
glVertex2f(10.0f,150.0f);
glVertex2f(10.0f,130.0f);
glVertex2f(140.0f,150.0f);
glVertex2f(140.0f,230.0f);
glVertex2f(160.0f,150.0f);
glVertex2f(160.0f,130.0f);
glVertex2f(150.0f,140.0f);
glVertex2f(190.0f,150.0f);
glVertex2f(190.0f,130.0f);
glVertex2f(210.0f,150.0f);
glVertex2f(210.0f,30.0f);
glVertex2f(200.0f,140.0f);
glVertex2f(120.0f,180.0f);
glVertex2f(130.0f,160.0f);
glVertex2f(140.0f,50.0f);
glVertex2f(140.0f,30.0f);
glVertex2f(110.0f,190.0f);
glVertex2f(110.0f,210.0f);
glVertex2f(100.0f,220.0f);
glVertex2f(110.0f,230.0f);
glVertex2f(110.0f,50.0f);
glVertex2f(100.0f,260.0f);
glVertex2f(110.0f,270.0f);
glVertex2f(90.0f,10.0f);
glVertex2f(94.0f,242.0f);
glVertex2f(-40.0f,180.0f);
glVertex2f(-50.0f,160.0f);
glVertex2f(-50.0f,40.0f);
glVertex2f(-36.0f,146.0f);
glVertex2f(-90.0f,170.0f);
glVertex2f(-90.0f,150.0f);
glVertex2f(-70.0f,170.0f);
glVertex2f(-70.0f,150.0f);
glVertex2f(-80.0f,160.0f);
glVertex2f(-70.0f,190.0f);
glVertex2f(90.0f,120.0f);
glVertex2f(80.0f,146.0f);
glVertex2f(-40.0f,260.0f);
glVertex2f(-50.0f,250.0f);
glVertex2f(-60.0f,270.0f);
glVertex2f(-50.0f,40.0f);
glVertex2f(-36.0f,46.0f);
glVertex2f(-90.0f,70.0f);
glVertex2f(-90.0f,50.0f);
glVertex2f(-70.0f,70.0f);
glVertex2f(-70.0f,50.0f);
glVertex2f(-80.0f,60.0f);
glVertex2f(-70.0f,90.0f);
glVertex2f(90.0f,30.0f);
glVertex2f(80.0f,46.0f);
glVertex2f(-40.0f,60.0f);
glVertex2f(-50.0f,50.0f);
glVertex2f(-60.0f,70.0f);
glVertex2f(-50.0f,40.0f);
glVertex2f(-36.0f,146.0f);
glVertex2f(-90.0f,170.0f);
glVertex2f(-90.0f,150.0f);
glVertex2f(-70.0f,170.0f);
glVertex2f(70.0f,150.0f);
glVertex2f(80.0f,160.0f);
glVertex2f(70.0f,190.0f);
glVertex2f(190.0f,120.0f);
glVertex2f(180.0f,146.0f);
glVertex2f(40.0f,260.0f);
glVertex2f(50.0f,250.0f);
glVertex2f(60.0f,270.0f);
glVertex2f(170.0f,200.0f);
glVertex2f(180.0f,190.0f);
glVertex2f(170.0f,200.0f);
glVertex2f(190.0f,10.0f);
glVertex2f(180.0f,146.0f);
glVertex2f(140.0f,200.0f);
glVertex2f(150.0f,120.0f);
glVertex2f(70.0f,150.0f);
glVertex2f(280.0f,160.0f);
glVertex2f(70.0f,190.0f);
glVertex2f(190.0f,120.0f);
glVertex2f(180.0f,146.0f);
glVertex2f(140.0f,260.0f);
glVertex2f(150.0f,250.0f);
glVertex2f(160.0f,70.0f);
glVertex2f(160.0f,170.0f);
glVertex2f(10.0f,20.0f);
glVertex2f(20.0f,10.0f);
glVertex2f(40.0f,46.0f);
glVertex2f(40.0f,60.0f);
glVertex2f(50.0f,20.0f);
glVertex2f(40.0f,20.0f);
glVertex2f(30.0f,40.0f);




glEnd();

glPopMatrix();

}

void planetX()//F5
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

void astronaut()//F6
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


void satelite()//F7
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
 glColor3ub(192,192,192);
 glVertex2d(130,470);
 glVertex2d(130,420);
 glVertex2d(150,420);
 glVertex2d(150,470);
 glEnd();

 glBegin(GL_QUADS);
 glColor3ub(192,192,192);
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
 glColor3ub(192,192,192);
 glVertex2d(130,450);
 glVertex2d(125,450);
 glVertex2d(125,440);
 glVertex2d(130,440);
 glEnd();
 glPopMatrix();
 //left hands
 glBegin(GL_QUADS);
 glColor3ub(192,192,192);
 glVertex2d(125,458);
 glVertex2d(95,458);
 glVertex2d(95,432);
 glVertex2d(125,432);
 glEnd();

 //right sidebar
 glBegin(GL_QUADS);
 glColor3ub(192,192,192);
 glVertex2d(130,450);
 glVertex2d(155,450);
 glVertex2d(155,440);
 glVertex2d(130,440);
 glEnd();
 //right hand
 glBegin(GL_QUADS);
 glColor3ub(192,192,192);
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


//tanim object
void Moving_star()//T1
{
    glColor3ub(253, 254, 254);
    glBegin(GL_POLYGON);
    glVertex2f(xaxis,470);
    glVertex2f(xaxis-5,460);
    glVertex2f(xaxis,450);
    glVertex2f(xaxis+5,460);
    glEnd();
}

void star1()//T2
{
      glColor3ub(247, 249, 249);
      glBegin(GL_POLYGON);
      glVertex2f(122,410);
      glVertex2f(128,410);
      glVertex2f(128,420);
      glVertex2f(122,420);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(125,440);
      glVertex2f(122,420);
      glVertex2f(128,420);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(127,409);
      glVertex2f(136,416);
      glVertex2f(127,423);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(125,393);
      glVertex2f(121,412);
      glVertex2f(128,412);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(113,415);
      glVertex2f(124,408);
      glVertex2f(124,422);
      glEnd();

}


void star2()//T3
{
      glColor3ub(247, 249, 249);
      glBegin(GL_POLYGON);
      glVertex2f(95,452);
      glVertex2f(101,452);
      glVertex2f(101,460);
      glVertex2f(95,460);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(98,474);
      glVertex2f(95,460);
      glVertex2f(101,460);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(96,450);
      glVertex2f(86,455);
      glVertex2f(96,460);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(100,433);
      glVertex2f(95,453);
      glVertex2f(101,453);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(100,448);
      glVertex2f(111,455);
      glVertex2f(100,458);
      glEnd();

}

void star3()//T4
{

      glColor3ub(247, 249, 249);
      glBegin(GL_POLYGON);
      glVertex2f(150,455);
      glVertex2f(156,455);
      glVertex2f(156,461);
      glVertex2f(150,461);
      glEnd();
      glBegin(GL_TRIANGLES);
      glVertex2f(153,474);
      glVertex2f(150,460);
      glVertex2f(156,460);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(152,450);
      glVertex2f(142,456);
      glVertex2f(152,460);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(153,436);
      glVertex2f(150,456);
      glVertex2f(156,456);
      glEnd();
      ///
      glBegin(GL_TRIANGLES);
      glVertex2f(153,450);
      glVertex2f(163,454);
      glVertex2f(153,460);
      glEnd();

}


void sun()//T5
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.7f, 0.65f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        if(i<20) glColor3ub(241, 196, 15 );
        else if(i<40) glColor3ub(212, 172, 13);
        else if(i<60) glColor3ub(243, 156, 18 );
        else if(i<80) glColor3ub(214, 137, 16 );
        else if(i<100) glColor3ub(185, 119, 14 );
        else if(i<130) glColor3ub(147, 81, 22);
        else if(i<160) glColor3ub(135, 54, 0);
        else if(i<200) glColor3ub(110, 44, 0);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.10;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(5.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {
        glColor3ub(23, 32, 42);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(5.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {
        glColor3ub(23, 32, 42);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
}

void Mars()//T6
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.85f, 0.65f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        if(i<=50) glColor3ub(192, 57, 43);
        else if(i<=100) glColor3ub(211, 84, 0);
        else if(i<=150) glColor3ub(248, 196, 113);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.04;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {
        glColor3ub(192, 57, 43 );
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.03;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
}

void Jupiter()//T7
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.75f, 0.80f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        if(i<50) glColor3ub(179, 182, 183);
        else if(i<100) glColor3ub(186, 74, 0 );
        else if(i<150) glColor3ub(179, 182, 183);
        else if(i<200) glColor3ub(211, 84, 0);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.02;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.03;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
}

void Neptune()//T8
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.50f, 0.60f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        if(i<50) glColor3ub(215, 189, 226);
        else if(i<100) glColor3ub(165, 105, 189);
        else if(i<150) glColor3ub(125, 60, 152);
        else if(i<200) glColor3ub(74, 35, 90);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.04;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {
        glColor3ub(125, 60, 152 );
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
}

void Mercury()//T9
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.75f, 0.50f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        if(i<100) glColor3ub(229, 231, 233);
        else if(i<200) glColor3ub(66, 73, 73);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for(int i=0;i<200;i++)
    {
        glColor3ub(213, 216, 220);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.07;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
}




//raihan object

void bac()//R1
{
glPushMatrix();
glBegin(GL_POLYGON);
//background color
glColor3ub(0,0,95);
glVertex2f(-200.0f,0.0f);
glVertex2f(200.0f,0.0f);
glVertex2f(200.0f,480.0f);
glVertex2f(-200.0f,480.0f);

glEnd();
glPopMatrix();

}


void BackStars()//R2
{

glPushMatrix();
glPointSize(3);
glBegin(GL_POINTS);
glColor3ub(255,255 ,255);

glVertex2f(-160.0f,460.0f);
glVertex2f(-150.0f,450.0f);
glVertex2f(-140.0f,350.0f);
glVertex2f(-170.0f,360.0f);
glVertex2f(-150.0f,360.0f);
glVertex2f(170.0f,360.0f);
glVertex2f(-175.0f,355.0f);
glVertex2f(180.0f,355.0f);
glVertex2f(-20.0f,370.0f);
glVertex2f(-30.0f,360.0f);
glVertex2f(0.0f,375.0f);
glVertex2f(-10.0f,390.0f);
glVertex2f(-70.0f,340.0f);
glVertex2f(20.0f,355.0f);
glVertex2f(-35.0f,460.0f);
glVertex2f(37.0f,470.0f);
glVertex2f(21.0f,442.0f);
glVertex2f(-5.0f,384.0f);
glVertex2f(200.0f,320.0f);
glVertex2f(180.0f,320.0f);
glVertex2f(160.0f,320.0f);
glVertex2f(140.0f,320.0f);
glVertex2f(120.0f,320.0f);
glVertex2f(100.0f,320.0f);
glVertex2f(80.0f,320.0f);
glVertex2f(60.0f,320.0f);
glVertex2f(40.0f,320.0f);
glVertex2f(20.0f,320.0f);
glVertex2f(0.0f,320.0f);
glVertex2f(-20.0f,322.0f);
glVertex2f(-40.0f,320.0f);
glVertex2f(-60.0f,323.0f);
glVertex2f(-80.0f,321.0f);
glVertex2f(-100.0f,324.0f);
glVertex2f(-120.0f,321.0f);
glVertex2f(-140.0f,322.0f);
glVertex2f(-160.0f,324.0f);
glVertex2f(-180.0f,323.0f);
glVertex2f(-200.0f,321.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(140.0f,380.0f);
glVertex2f(145.0f,390.0f);
glVertex2f(155.0f,375.0f);
glVertex2f(80.0f,345.0f);
glVertex2f(85.0f,355.0f);
glVertex2f(-120.0f,400.0f);
glVertex2f(-120.0f,440.0f);
glVertex2f(-110.0f,460.0f);
glVertex2f(120.0f,460.0f);
glVertex2f(160.0f,460.0f);
glVertex2f(120.0f,420.0f);
glVertex2f(160.0f,420.0f);
glVertex2f(140.0f,440.0f);
glVertex2f(-140.0f,420.0f);
glVertex2f(-100.0f,420.0f);
glVertex2f(-140.0f,380.0f);
glVertex2f(-100.0f,380.0f);
glVertex2f(-20.0f,420.0f);
glVertex2f(-60.0f,420.0f);
glVertex2f(-60.0f,380.0f);
glVertex2f(-20.0f,380.0f);
glVertex2f(-40.0f,400.0f);
glVertex2f(-80.0f,400.0f);
glVertex2f(-190.0f,420.0f);
glVertex2f(-190.0f,380.0f);
glVertex2f(-160.0f,380.0f);
glVertex2f(-160.0f,420.0f);
glVertex2f(-176.0f,400.0f);
glVertex2f(-190.0f,460.0f);
glVertex2f(-190.0f,440.0f);
glVertex2f(-170.0f,440.0f);
glVertex2f(-170.0f,460.0f);
glVertex2f(-110.0f,470.0f);
glVertex2f(-110.0f,450.0f);
glVertex2f(-90.0f,450.0f);
glVertex2f(-90.0f,470.0f);
glVertex2f(-100.0f,460.0f);
glVertex2f(-110.0f,330.0f);
glVertex2f(-110.0f,350.0f);
glVertex2f(-130.0f,350.0f);
glVertex2f(-130.0f,330.0f);
glVertex2f(-120.0f,340.0f);
glVertex2f(-120.0f,360.0f);
glVertex2f(-125.0f,380.0f);
glVertex2f(-180.0f,340.0f);
glVertex2f(-175.0f,360.0f);
glVertex2f(-190.0f,360.0f);
glVertex2f(-195.0f,335.0f);
glVertex2f(-150.0f,400.0f);
glVertex2f(60.0f,380.0f);
glVertex2f(80.0f,380.0f);
glVertex2f(60.0f,360.0f);
glVertex2f(80.0f,360.0f);
glVertex2f(70.0f,370.0f);
glVertex2f(70.0f,410.0f);
glVertex2f(70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(90.0f,410.0f);
glVertex2f(80.0f,400.0f);
glVertex2f(60.0f,450.0f);
glVertex2f(80.0f,450.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(70.0f,460.0f);
glVertex2f(60.0f,470.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(40.0f,450.0f);
glVertex2f(30.0f,460.0f);
glVertex2f(50.0f,460.0f);
glVertex2f(140.0f,470.0f);
glVertex2f(140.0f,410.0f);
glVertex2f(170.0f,440.0f);
glVertex2f(190.0f,430.0f);
glVertex2f(190.0f,450.0f);
glVertex2f(180.0f,420.0f);
glVertex2f(170.0f,410.0f);
glVertex2f(190.0f,400.0f);
glVertex2f(180.0f,380.0f);
glVertex2f(170.0f,370.0f);
glVertex2f(-10.0f,470.0f);
glVertex2f(-10.0f,450.0f);
glVertex2f(10.0f,470.0f);
glVertex2f(10.0f,450.0f);
glVertex2f(0.0f,460.0f);
glVertex2f(-10.0f,430.0f);
glVertex2f(-10.0f,410.0f);
glVertex2f(10.0f,430.0f);
glVertex2f(10.0f,410.0f);
glVertex2f(0.0f,420.0f);
glVertex2f(0.0f,440.0f);
glVertex2f(90.0f,360.0f);
glVertex2f(110.0f,360.0f);
glVertex2f(90.0f,340.0f);
glVertex2f(110.0f,340.0f);
glVertex2f(100.0f,350.0f);
glVertex2f(-20.0f,360.0f);
glVertex2f(-20.0f,340.0f);
glVertex2f(-10.0f,350.0f);
glVertex2f(0.0f,340.0f);
glVertex2f(0.0f,360.0f);
glVertex2f(-10.0f,370.0f);
glVertex2f(-10.0f,330.0f);
glVertex2f(30.0f,420.0f);
glVertex2f(50.0f,420.0f);
glVertex2f(30.0f,400.0f);
glVertex2f(50.0f,400.0f);
glVertex2f(40.0f,410.0f);
glVertex2f(30.0f,380.0f);
glVertex2f(50.0f,380.0f);
glVertex2f(30.0f,360.0f);
glVertex2f(50.0f,360.0f);
glVertex2f(40.0f,370.0f);
glVertex2f(20.0f,340.0f);
glVertex2f(40.0f,340.0f);
glVertex2f(60.0f,340.0f);
glVertex2f(10.0f,390.0f);
glVertex2f(10.0f,370.0f);
glVertex2f(10.0f,350.0f);
glVertex2f(10.0f,330.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(160.0f,350.0f);
glVertex2f(160.0f,330.0f);
glVertex2f(150.0f,340.0f);
glVertex2f(190.0f,350.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(210.0f,350.0f);
glVertex2f(210.0f,330.0f);
glVertex2f(200.0f,340.0f);
glVertex2f(120.0f,380.0f);
glVertex2f(130.0f,360.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(110.0f,390.0f);
glVertex2f(110.0f,410.0f);
glVertex2f(100.0f,420.0f);
glVertex2f(110.0f,430.0f);
glVertex2f(110.0f,450.0f);
glVertex2f(100.0f,460.0f);
glVertex2f(110.0f,470.0f);
glVertex2f(90.0f,470.0f);
glVertex2f(94.0f,442.0f);
glVertex2f(-40.0f,380.0f);
glVertex2f(-50.0f,360.0f);
glVertex2f(-50.0f,340.0f);
glVertex2f(-36.0f,346.0f);
glVertex2f(-90.0f,370.0f);
glVertex2f(-90.0f,350.0f);
glVertex2f(-70.0f,370.0f);
glVertex2f(-70.0f,350.0f);
glVertex2f(-80.0f,360.0f);
glVertex2f(-70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(80.0f,346.0f);
glVertex2f(-40.0f,460.0f);
glVertex2f(-50.0f,450.0f);
glVertex2f(-60.0f,470.0f);

glEnd();
glPopMatrix();
}


void PlanetZ()//R3
{
    glPushMatrix();
    glTranslatef(160.0f, 430.0f, 0.0f);
  glRotatef(PlanetZAngle, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
    {
        if(i<50) glColor3ub(255, 255, 0 );
        else if(i<100) glColor3ub(204, 204, 0);
        else if(i<150) glColor3ub(153, 153, 153 );
        else if(i<200) glColor3ub(204, 102, 0 );


        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=7.0;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
	glEnd();

	glPopMatrix();
}



void moon()//R4
{
    glPushMatrix();
    glTranslatef(-120.0f, 400.0f, 0.0f);
  glRotatef(MoonAngle, 0.0f, 0.0f,1.0f);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
    {
        if(i<20) glColor3ub(255, 255, 255 );
        else if(i<40) glColor3ub(224, 224, 224);
        else if(i<60) glColor3ub(192, 192, 192 );
        else if(i<80) glColor3ub(160, 160, 160 );
        else if(i<100) glColor3ub(128, 128, 128);
        else if(i<130) glColor3ub(229, 255, 204);
        else if(i<160) glColor3ub(255, 255, 204);
        else if(i<200) glColor3ub(236, 239, 237);

        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=7.10;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
	glEnd();

	glPopMatrix();
}



void sootingStar1()//R5
{

glPushMatrix();

glTranslatef(SootingStar1Position,0.0f, 0.0f);

glBegin(GL_POLYGON);
//sooting star1 middle
glColor3ub(255,255,255);
glVertex2f(-182.0f,432.0f);
glVertex2f(-182.0f,428.0f);
glVertex2f(-178.0f,428.0f);
glVertex2f(-178.0f,432.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star1 left triangle
glColor3ub(255,255,255);
glVertex2f(-182.0f,432.0f);
glVertex2f(-190.0f,430.0f);
glVertex2f(-182.0f,428.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star1 right triangle
glColor3ub(255,255,255);
glVertex2f(-178.0f,432.0f);
glVertex2f(-178.0f,428.0f);
glVertex2f(-174.0f,430.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star1 up triangle
glColor3ub(255,255,255);
glVertex2f(-180.0f,436.0f);
glVertex2f(-182.0f,432.0f);
glVertex2f(-178.0f,432.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star1 down triangle
glColor3ub(255,255,255);
glVertex2f(-182.0f,428.0f);
glVertex2f(-180.0f,424.0f);
glVertex2f(-178.0f,428.0f);
glEnd();

glPopMatrix();

}



void sootingStar2()//R6
{

glPushMatrix();

glTranslatef(SootingStar2Position,0.0f, 0.0f);

glBegin(GL_POLYGON);
//sooting star2 middle
glColor3ub(255,255,255);
glVertex2f(138.0f,464.0f);
glVertex2f(138.0f,460.0f);
glVertex2f(142.0f,460.0f);
glVertex2f(142.0f,464.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star2 left triangle
glColor3ub(255,255,255);
glVertex2f(134.0f,462.0f);
glVertex2f(138.0f,460.0f);
glVertex2f(138.0f,464.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star2 right triangle
glColor3ub(255,255,255);
glVertex2f(142.0f,464.0f);
glVertex2f(142.0f,460.0f);
glVertex2f(150.0f,462.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star2 up triangle
glColor3ub(255,255,255);
glVertex2f(140.0f,468.0f);
glVertex2f(138.0f,464.0f);
glVertex2f(142.0f,464.0f);
glEnd();

glBegin(GL_POLYGON);
//sooting star2 down triangle
glColor3ub(255,255,255);
glVertex2f(138.0f,460.0f);
glVertex2f(140.0f,456.0f);
glVertex2f(142.0f,460.0f);
glEnd();

glPopMatrix();

}

void backBuildings()//R7
{

    glPushMatrix();

glBegin(GL_POLYGON);
//back right building
glColor3ub(0,0,70);
glVertex2f(100.0f,24.0f);
glVertex2f(180.0f,24.0f);
glVertex2f(180.0f,200.0f);
glVertex2f(100.0f,200.0f);
glEnd();

glBegin(GL_POLYGON);//right back building top
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=40.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+140,y+235 );
        }

	glEnd();

glBegin(GL_POLYGON);
//back left building
glColor3ub(0,0,70);
glVertex2f(-100.0f,24.0f);
glVertex2f(-180.0f,24.0f);
glVertex2f(-180.0f,200.0f);
glVertex2f(-100.0f,200.0f);
glEnd();

glBegin(GL_POLYGON);//left back building top
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=40.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-140,y+235 );
        }

	glEnd();


	glBegin(GL_POLYGON);
//back right building column
glColor3ub(0,0,70);
glVertex2f(80.0f,24.0f);
glVertex2f(90.0f,24.0f);
glVertex2f(90.0f,250.0f);
glVertex2f(80.0f,250.0f);
glEnd();

glBegin(GL_POLYGON);//right back building column top circle 1
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+84.5,y+250 );
        }

	glEnd();

	glBegin(GL_POLYGON);//right back building column top circle 2
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+84.5,y+270 );
        }

	glEnd();

		glBegin(GL_POLYGON);//right back building column top circle 3
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+84.5,y+290 );
        }

	glEnd();



	glBegin(GL_POLYGON);
//back left building column
glColor3ub(0,0,70);
glVertex2f(-80.0f,24.0f);
glVertex2f(-90.0f,24.0f);
glVertex2f(-90.0f,250.0f);
glVertex2f(-80.0f,250.0f);
glEnd();

glBegin(GL_POLYGON);//left back building column top circle 1
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-84.5,y+250 );
        }

	glEnd();

	glBegin(GL_POLYGON);//left back building column top circle 2
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-84.5,y+270 );
        }

	glEnd();

		glBegin(GL_POLYGON);//left back building column top circle 3
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-84.5,y+290 );
        }

	glEnd();

glBegin(GL_LINES);
//right back column circle join
glColor3ub(0, 0, 70);
glVertex2f(84.5f,240.0f);
glVertex2f(84.5f,290.0f);
glEnd();

glBegin(GL_LINES);
//left back column circle join
glColor3ub(0, 0, 70);
glVertex2f(-84.5f,240.0f);
glVertex2f(-84.5f,290.0f);
glEnd();

glPopMatrix();
}



void rocket()//R8
{

glPushMatrix();

glTranslatef(0.0f,Rocketposition, 0.0f);

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



	//head black circle
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


	glPopMatrix();

	//glFlush();


}



void station()//R9
{

glPushMatrix();
glBegin(GL_POLYGON);
//green base
glColor3ub(0 ,255 ,0);
glVertex2f(-200.0f,20.0f);
glVertex2f(-200.0f,18.0f);
glVertex2f(200.0f,18.0f);
glVertex2f(200.00f,20.0f);
glEnd();

glBegin(GL_POLYGON);
//purple base
glColor3ub(204 ,0 ,204);
glVertex2f(-196.0f,24.0f);
glVertex2f(-196.0f,20.0f);
glVertex2f(196.0f,20.0f);
glVertex2f(196.00f,24.0f);
glEnd();

glBegin(GL_POLYGON);
//octagon blue base
glColor3ub(0 ,0 ,255);
glVertex2f(-196.0f,18.0f);
glVertex2f(-200.0f,14.0f);
glVertex2f(-196.0f,10.0f);
glVertex2f(196.00f,10.0f);
glVertex2f(200.0f,14.0f);
glVertex2f(196.00f,18.0f);
glEnd();

glBegin(GL_POLYGON);
//octagon  base
glColor3ub(137, 104, 205);
glVertex2f(-196.0f,10.0f);
glVertex2f(-200.0f,6.0f);
glVertex2f(-196.0f,2.0f);
glVertex2f(196.00f,2.0f);
glVertex2f(200.0f,6.0f);
glVertex2f(196.00f,10.0f);
glEnd();

glBegin(GL_POLYGON);
//station middle
glColor3ub(137, 104, 205);
glVertex2f(-120.0f,100.0f);
glVertex2f(-120.0f,24.0f);
glVertex2f(120.0f,24.0f);
glVertex2f(120.00f,100.0f);
glEnd();

glBegin(GL_POLYGON);
//station triangle left
glColor3ub(137, 104, 205);
glVertex2f(-80.0f,160.0f);
glVertex2f(-120.0f,104.0f);
glVertex2f(-30.0f,104.0f);
glEnd();

glBegin(GL_POLYGON);
//station triangle left2
glColor3ub(67, 205, 128);
glVertex2f(-80.0f,150.0f);
glVertex2f(-108.0f,110.0f);
glVertex2f(-50.0f,110.0f);
glEnd();

glBegin(GL_POLYGON);
//station triangle right
glColor3ub(137, 104, 205);
glVertex2f(80.0f,160.0f);
glVertex2f(30.0f,104.0f);
glVertex2f(120.0f,104.0f);
glEnd();

glBegin(GL_POLYGON);
//station triangle right2
glColor3ub(67, 205, 128);
glVertex2f(80.0f,150.0f);
glVertex2f(50.0f,110.0f);
glVertex2f(108.0f,110.0f);
glEnd();


glPopMatrix();

}


void Stationcircles() //R10
{

glPushMatrix();

	glBegin(GL_POLYGON);//1
	for(int i=0;i<200;i++)
        {
            glColor3ub(153,76 ,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-80,y+60 );
        }

	glEnd();

		glBegin(GL_POLYGON);//2
	for(int i=0;i<200;i++)
        {
            glColor3ub(153,76 ,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-40,y+60 );
        }

	glEnd();

			glBegin(GL_POLYGON);//3
	for(int i=0;i<200;i++)
        {
            glColor3ub(153,76 ,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y+60 );
        }

	glEnd();

			glBegin(GL_POLYGON);//4
	for(int i=0;i<200;i++)
        {
            glColor3ub(153,76 ,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+40,y+60 );
        }

	glEnd();

			glBegin(GL_POLYGON);//5
	for(int i=0;i<200;i++)
        {
            glColor3ub(153,76 ,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+80,y+60 );
        }

	glEnd();

				glBegin(GL_POLYGON);//6
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-80,y+60 );
        }

	glEnd();

					glBegin(GL_POLYGON);//7
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-40,y+60 );
        }

	glEnd();

						glBegin(GL_POLYGON);//8
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y+60 );
        }

	glEnd();

						glBegin(GL_POLYGON);//9
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+40,y+60 );
        }

	glEnd();

						glBegin(GL_POLYGON);//10
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+80,y+60 );
        }

	glEnd();

							glBegin(GL_POLYGON);//11
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-118,y+102 );
        }

	glEnd();

							glBegin(GL_POLYGON);//12
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-32,y+102 );
        }

	glEnd();

								glBegin(GL_POLYGON);//13
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+32,y+102 );
        }

	glEnd();

								glBegin(GL_POLYGON);//14
	for(int i=0;i<200;i++)
        {
            glColor3ub(51,51 ,255);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+118,y+102 );
        }

	glEnd();


								glBegin(GL_POLYGON);//15
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-118,y+102 );
        }

	glEnd();

							glBegin(GL_POLYGON);//16
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-32,y+102 );
        }

	glEnd();

								glBegin(GL_POLYGON);//17
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+32,y+102 );
        }

	glEnd();

								glBegin(GL_POLYGON);//18
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+118,y+102 );
        }

	glEnd();

glPopMatrix();
}



void StationRightBulb()//R11
{

glPushMatrix();

glBegin(GL_QUADS);
//station right bulb stand up
glColor3ub(137, 104, 205);
glVertex2f(156.0f,40.0f);
glVertex2f(156.0f,140.0f);
glVertex2f(140.0f,140.0f);
glVertex2f(140.0f,40.0f);
glEnd();

glBegin(GL_QUADS);
//station right bulb stand low
glColor3ub(137, 104, 205);
glVertex2f(144.0f,40.0f);
glVertex2f(144.0f,24.0f);
glVertex2f(152.0f,24.0f);
glVertex2f(152.0f,40.0f);
glEnd();

glBegin(GL_QUADS);
//station right bulb rectangle1
glColor3ub(124, 252, 0);
glVertex2f(136.0f,120.0f);
glVertex2f(136.0f,114.0f);
glVertex2f(160.0f,114.0f);
glVertex2f(160.0f,120.0f);
glEnd();

glPushMatrix();
glBegin(GL_QUADS);
//station right bulb rectangle2


glColor3ub(255, 255, 0);
glVertex2f(136.0f,100.0f);
glVertex2f(136.0f,94.0f);
glVertex2f(160.0f,94.0f);
glVertex2f(160.0f,100.0f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
//station right bulb rectangle3
glColor3ub(255, 0, 0);
glVertex2f(136.0f,80.0f);
glVertex2f(136.0f,74.0f);
glVertex2f(160.0f,74.0f);
glVertex2f(160.0f,80.0f);
glEnd();

glBegin(GL_QUADS);
//station right bulb rectangle4
glColor3ub(124, 252, 0);
glVertex2f(136.0f,60.0f);
glVertex2f(136.0f,54.0f);
glVertex2f(160.0f,54.0f);
glVertex2f(160.0f,60.0f);
glEnd();

glBegin(GL_TRIANGLES);
//station right bulb triangle
glColor3ub(192, 255, 62);
glVertex2f(148.0f,154.0f);
glVertex2f(136.0f,136.0f);
glVertex2f(160.0f,136.0f);
glEnd();

glBegin(GL_TRIANGLES);
//station right bulb triangle
glColor3ub(192, 255, 62);
glVertex2f(136.0f,136.0f);
glVertex2f(148.0f,122.0f);
glVertex2f(160.0f,136.0f);
glEnd();

glPopMatrix();
glFlush();

}



void stationLeftBulb()//R12
{

glBegin(GL_POLYGON);
//station left bulb stand
glColor3ub(137, 104, 205);
glVertex2f(-148.0f,140.0f);
glVertex2f(-148.0f,24.0f);
glVertex2f(-140.0f,24.0f);
glVertex2f(-140.00f,140.0f);
glEnd();

glBegin(GL_POLYGON);
//station left bulb stand side 1
glColor3ub(137, 104, 205);
glVertex2f(-170.0f,92.0f);
glVertex2f(-170.0f,88.0f);
glVertex2f(-148.0f,88.0f);
glVertex2f(-148.0f,92.0f);
glEnd();


glBegin(GL_POLYGON);
//station left bulb stand side 2
glColor3ub(137, 104, 205);
glVertex2f(-170.0f,58.0f);
glVertex2f(-170.0f,54.0f);
glVertex2f(-148.0f,54.0f);
glVertex2f(-148.0f,58.0f);
glEnd();

glPushMatrix();
glLineWidth(4.0);
glTranslatef(-144.0f,136.0f,0.0f);
glRotatef(bulbAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//left bulb circle 1 effect
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,255,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=9.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();

glBegin(GL_POLYGON);//left bulb circle 1
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=9.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-144,y+136 );
        }

	glEnd();


		glPushMatrix();
glLineWidth(4.0);
glTranslatef(-144.0f,136.0f,0.0f);
glRotatef(bulbAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//left bulb circle 1 up circle effect
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,204);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();


	glBegin(GL_POLYGON);//left bulb circle 1 up circle
	for(int i=0;i<200;i++)
        {
            glColor3ub(124, 252, 0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-144,y+136 );
        }

	glEnd();

	glPushMatrix();
glLineWidth(4.0);
glTranslatef(-168.0f,90.0f,0.0f);
glRotatef(bulbAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//left bulb circle 2 effect
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,255,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();



	glBegin(GL_POLYGON);//left bulb circle 2
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-168,y+90 );
        }

	glEnd();

glPushMatrix();
glLineWidth(4.0);
glTranslatef(-168.0f,56.0f,0.0f);
glRotatef(bulbAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//left bulb circle 3 effect
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,255,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);//left bulb circle 3
	for(int i=0;i<200;i++)
        {
            glColor3ub(255,0,0);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-168,y+56 );
        }

	glEnd();


glBegin(GL_POLYGON);
//station left bulb circle 2 line
glColor3ub(124, 252, 0);
glVertex2f(-180.0f,92.0f);
glVertex2f(-180.0f,88.0f);
glVertex2f(-164.0f,88.0f);
glVertex2f(-164.0f,92.0f);
glEnd();

	glBegin(GL_POLYGON);
//station left bulb circle 3 line
glColor3ub(124, 252, 0);
glVertex2f(-180.0f,58.0f);
glVertex2f(-180.0f,54.0f);
glVertex2f(-164.0f,54.0f);
glVertex2f(-164.0f,58.0f);
glEnd();


}

void disback(int val){

glutDisplayFunc(disRaihan);

}

void display4(){

 glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(1.0);
Back();
backStars();
shootingStar();
rocket();
astronaut();
planetX();
spaceRadar();
satelite();
glutTimerFunc(11000, disback,0);

glFlush();

}



void faysalDisplay(int val)
{
    glutDisplayFunc(display4);
}



void display3(){

 glClear(GL_COLOR_BUFFER_BIT);
Back();
backStars();
 Moving_star();
   star1();
   star2();
   star3();
   sun();
   Mars();
   Jupiter();
   Neptune();
   Mercury();
   rocket();
glutTimerFunc(11000, faysalDisplay,0);

glFlush();

}



void tanimDisplay(int val)
{
    glutDisplayFunc(display3);
}



void display2() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

/*glPushMatrix();

glBegin(GL_POLYGON);
//background color
glColor3ub(0,0,95);
glVertex2f(-200.0f,0.0f);
glVertex2f(200.0f,0.0f);
glVertex2f(200.0f,480.0f);
glVertex2f(-200.0f,480.0f);

glEnd();

glPopMatrix();*/



glPushMatrix();//M1
  glTranslatef(0.0,0.0,0);//MU2
    glRotatef(r,0,0,1);

	GLfloat x15=-150.0f; GLfloat y15=150.0f; GLfloat radius15 =15.0f; //moon_circle
	int triangleAmount15 = 50;
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x15, y15);
		for(int i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

	glPopMatrix();
    r-=0.12;




glPushMatrix();//M2
//back stars1
glPointSize(3);
glBegin(GL_POINTS);
glColor3ub(255,255 ,255);

glVertex2f(-160.0f,460.0f);
glVertex2f(-150.0f,450.0f);
glVertex2f(-140.0f,350.0f);
glVertex2f(-170.0f,360.0f);
glVertex2f(-150.0f,360.0f);
glVertex2f(170.0f,360.0f);
glVertex2f(-175.0f,355.0f);
glVertex2f(180.0f,355.0f);
glVertex2f(-20.0f,370.0f);
glVertex2f(-30.0f,360.0f);
glVertex2f(0.0f,375.0f);
glVertex2f(-10.0f,390.0f);
glVertex2f(-70.0f,340.0f);
glVertex2f(20.0f,355.0f);
glVertex2f(-35.0f,460.0f);
glVertex2f(37.0f,470.0f);
glVertex2f(21.0f,442.0f);
glVertex2f(-5.0f,384.0f);
glVertex2f(200.0f,320.0f);
glVertex2f(180.0f,320.0f);
glVertex2f(160.0f,320.0f);
glVertex2f(140.0f,320.0f);
glVertex2f(120.0f,320.0f);
glVertex2f(100.0f,320.0f);
glVertex2f(80.0f,320.0f);
glVertex2f(60.0f,320.0f);
glVertex2f(40.0f,320.0f);
glVertex2f(20.0f,320.0f);
glVertex2f(0.0f,320.0f);
glVertex2f(-20.0f,322.0f);
glVertex2f(-40.0f,320.0f);
glVertex2f(-60.0f,323.0f);
glVertex2f(-80.0f,321.0f);
glVertex2f(-100.0f,324.0f);
glVertex2f(-120.0f,321.0f);
glVertex2f(-140.0f,322.0f);
glVertex2f(-160.0f,324.0f);
glVertex2f(-180.0f,323.0f);
glVertex2f(-200.0f,321.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(140.0f,380.0f);
glVertex2f(145.0f,390.0f);
glVertex2f(155.0f,375.0f);
glVertex2f(80.0f,345.0f);
glVertex2f(85.0f,355.0f);
glVertex2f(-120.0f,400.0f);
glVertex2f(-120.0f,440.0f);
glVertex2f(-110.0f,460.0f);
glVertex2f(120.0f,460.0f);
glVertex2f(160.0f,460.0f);
glVertex2f(120.0f,420.0f);
glVertex2f(160.0f,420.0f);
glVertex2f(140.0f,440.0f);
glVertex2f(-140.0f,420.0f);
glVertex2f(-100.0f,420.0f);
glVertex2f(-140.0f,380.0f);
glVertex2f(-100.0f,380.0f);
glVertex2f(-20.0f,420.0f);
glVertex2f(-60.0f,420.0f);
glVertex2f(-60.0f,380.0f);
glVertex2f(-20.0f,380.0f);
glVertex2f(-40.0f,400.0f);
glVertex2f(-80.0f,400.0f);
glVertex2f(-190.0f,420.0f);
glVertex2f(-190.0f,380.0f);
glVertex2f(-160.0f,380.0f);
glVertex2f(-160.0f,420.0f);
glVertex2f(-176.0f,400.0f);
glVertex2f(-190.0f,460.0f);
glVertex2f(-190.0f,440.0f);
glVertex2f(-170.0f,440.0f);
glVertex2f(-170.0f,460.0f);
glVertex2f(-110.0f,470.0f);
glVertex2f(-110.0f,450.0f);
glVertex2f(-90.0f,450.0f);
glVertex2f(-90.0f,470.0f);
glVertex2f(-100.0f,460.0f);
glVertex2f(-110.0f,330.0f);
glVertex2f(-110.0f,350.0f);
glVertex2f(-130.0f,350.0f);
glVertex2f(-130.0f,330.0f);
glVertex2f(-120.0f,340.0f);
glVertex2f(-120.0f,360.0f);
glVertex2f(-125.0f,380.0f);
glVertex2f(-180.0f,340.0f);
glVertex2f(-175.0f,360.0f);
glVertex2f(-190.0f,360.0f);
glVertex2f(-195.0f,335.0f);
glVertex2f(-150.0f,400.0f);
glVertex2f(60.0f,380.0f);
glVertex2f(80.0f,380.0f);
glVertex2f(60.0f,360.0f);
glVertex2f(80.0f,360.0f);
glVertex2f(70.0f,370.0f);
glVertex2f(70.0f,410.0f);
glVertex2f(70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(90.0f,410.0f);
glVertex2f(80.0f,400.0f);
glVertex2f(60.0f,450.0f);
glVertex2f(80.0f,450.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(70.0f,460.0f);
glVertex2f(60.0f,470.0f);
glVertex2f(60.0f,430.0f);
glVertex2f(80.0f,430.0f);
glVertex2f(70.0f,440.0f);
glVertex2f(40.0f,450.0f);
glVertex2f(30.0f,460.0f);
glVertex2f(50.0f,460.0f);
glVertex2f(140.0f,470.0f);
glVertex2f(140.0f,410.0f);
glVertex2f(170.0f,440.0f);
glVertex2f(190.0f,430.0f);
glVertex2f(190.0f,450.0f);
glVertex2f(180.0f,420.0f);
glVertex2f(170.0f,410.0f);
glVertex2f(190.0f,400.0f);
glVertex2f(180.0f,380.0f);
glVertex2f(170.0f,370.0f);
glVertex2f(-10.0f,470.0f);
glVertex2f(-10.0f,450.0f);
glVertex2f(10.0f,470.0f);
glVertex2f(10.0f,450.0f);
glVertex2f(0.0f,460.0f);
glVertex2f(-10.0f,430.0f);
glVertex2f(-10.0f,410.0f);
glVertex2f(10.0f,430.0f);
glVertex2f(10.0f,410.0f);
glVertex2f(0.0f,420.0f);
glVertex2f(0.0f,440.0f);
glVertex2f(90.0f,360.0f);
glVertex2f(110.0f,360.0f);
glVertex2f(90.0f,340.0f);
glVertex2f(110.0f,340.0f);
glVertex2f(100.0f,350.0f);
glVertex2f(-20.0f,360.0f);
glVertex2f(-20.0f,340.0f);
glVertex2f(-10.0f,350.0f);
glVertex2f(0.0f,340.0f);
glVertex2f(0.0f,360.0f);
glVertex2f(-10.0f,370.0f);
glVertex2f(-10.0f,330.0f);
glVertex2f(30.0f,420.0f);
glVertex2f(50.0f,420.0f);
glVertex2f(30.0f,400.0f);
glVertex2f(50.0f,400.0f);
glVertex2f(40.0f,410.0f);
glVertex2f(30.0f,380.0f);
glVertex2f(50.0f,380.0f);
glVertex2f(30.0f,360.0f);
glVertex2f(50.0f,360.0f);
glVertex2f(40.0f,370.0f);
glVertex2f(20.0f,340.0f);
glVertex2f(40.0f,340.0f);
glVertex2f(60.0f,340.0f);
glVertex2f(10.0f,390.0f);
glVertex2f(10.0f,370.0f);
glVertex2f(10.0f,350.0f);
glVertex2f(10.0f,330.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(160.0f,350.0f);
glVertex2f(160.0f,330.0f);
glVertex2f(150.0f,340.0f);
glVertex2f(190.0f,350.0f);
glVertex2f(190.0f,330.0f);
glVertex2f(210.0f,350.0f);
glVertex2f(210.0f,330.0f);
glVertex2f(200.0f,340.0f);
glVertex2f(120.0f,380.0f);
glVertex2f(130.0f,360.0f);
glVertex2f(140.0f,350.0f);
glVertex2f(140.0f,330.0f);
glVertex2f(110.0f,390.0f);
glVertex2f(110.0f,410.0f);
glVertex2f(100.0f,420.0f);
glVertex2f(110.0f,430.0f);
glVertex2f(110.0f,450.0f);
glVertex2f(100.0f,460.0f);
glVertex2f(110.0f,470.0f);
glVertex2f(90.0f,470.0f);
glVertex2f(94.0f,442.0f);
glVertex2f(-40.0f,380.0f);
glVertex2f(-50.0f,360.0f);
glVertex2f(-50.0f,340.0f);
glVertex2f(-36.0f,346.0f);
glVertex2f(-90.0f,370.0f);
glVertex2f(-90.0f,350.0f);
glVertex2f(-70.0f,370.0f);
glVertex2f(-70.0f,350.0f);
glVertex2f(-80.0f,360.0f);
glVertex2f(-70.0f,390.0f);
glVertex2f(90.0f,390.0f);
glVertex2f(80.0f,346.0f);
glVertex2f(-40.0f,460.0f);
glVertex2f(-50.0f,450.0f);
glVertex2f(-60.0f,470.0f);

glEnd();

glPopMatrix();



glPushMatrix();//M3
//back stars2
glPointSize(3);
glBegin(GL_POINTS);
glColor3ub(255,255 ,255);

glVertex2f(-160.0f,260.0f);
glVertex2f(-150.0f,250.0f);
glVertex2f(-140.0f,150.0f);
glVertex2f(-170.0f,160.0f);
glVertex2f(-150.0f,160.0f);
glVertex2f(170.0f,160.0f);
glVertex2f(-175.0f,155.0f);
glVertex2f(180.0f,155.0f);
glVertex2f(-20.0f,170.0f);
glVertex2f(-30.0f,160.0f);
glVertex2f(0.0f,175.0f);
glVertex2f(-10.0f,190.0f);
glVertex2f(-70.0f,140.0f);
glVertex2f(20.0f,155.0f);
glVertex2f(-35.0f,260.0f);
glVertex2f(37.0f,270.0f);
glVertex2f(21.0f,242.0f);
glVertex2f(-5.0f,184.0f);
glVertex2f(200.0f,120.0f);
glVertex2f(180.0f,120.0f);
glVertex2f(160.0f,120.0f);
glVertex2f(140.0f,120.0f);
glVertex2f(120.0f,120.0f);
glVertex2f(100.0f,120.0f);
glVertex2f(80.0f,120.0f);
glVertex2f(60.0f,120.0f);
glVertex2f(40.0f,120.0f);
glVertex2f(20.0f,120.0f);
glVertex2f(0.0f,120.0f);
glVertex2f(-20.0f,122.0f);
glVertex2f(-40.0f,120.0f);
glVertex2f(-60.0f,123.0f);
glVertex2f(-80.0f,121.0f);
glVertex2f(-100.0f,124.0f);
glVertex2f(-120.0f,121.0f);
glVertex2f(-140.0f,122.0f);
glVertex2f(-160.0f,124.0f);
glVertex2f(-180.0f,123.0f);
glVertex2f(-200.0f,121.0f);
glVertex2f(190.0f,130.0f);
glVertex2f(140.0f,180.0f);
glVertex2f(145.0f,190.0f);
glVertex2f(155.0f,175.0f);
glVertex2f(80.0f,145.0f);
glVertex2f(85.0f,155.0f);
glVertex2f(-120.0f,200.0f);
glVertex2f(-120.0f,240.0f);
glVertex2f(-110.0f,260.0f);
glVertex2f(120.0f,260.0f);
glVertex2f(160.0f,260.0f);
glVertex2f(120.0f,220.0f);
glVertex2f(160.0f,220.0f);
glVertex2f(140.0f,240.0f);
glVertex2f(-140.0f,220.0f);
glVertex2f(-100.0f,220.0f);
glVertex2f(-140.0f,180.0f);
glVertex2f(-100.0f,180.0f);
glVertex2f(-20.0f,220.0f);
glVertex2f(-60.0f,220.0f);
glVertex2f(-60.0f,180.0f);
glVertex2f(-20.0f,180.0f);
glVertex2f(-40.0f,200.0f);
glVertex2f(-80.0f,200.0f);
glVertex2f(-190.0f,220.0f);
glVertex2f(-190.0f,180.0f);
glVertex2f(-160.0f,180.0f);
glVertex2f(-160.0f,220.0f);
glVertex2f(-176.0f,200.0f);
glVertex2f(-190.0f,260.0f);
glVertex2f(-190.0f,240.0f);
glVertex2f(-170.0f,240.0f);
glVertex2f(-170.0f,260.0f);
glVertex2f(-110.0f,270.0f);
glVertex2f(-110.0f,250.0f);
glVertex2f(-90.0f,250.0f);
glVertex2f(-90.0f,270.0f);
glVertex2f(-100.0f,260.0f);
glVertex2f(-110.0f,130.0f);
glVertex2f(-110.0f,150.0f);
glVertex2f(-130.0f,150.0f);
glVertex2f(-130.0f,130.0f);
glVertex2f(-120.0f,140.0f);
glVertex2f(-120.0f,160.0f);
glVertex2f(-125.0f,180.0f);
glVertex2f(-180.0f,140.0f);
glVertex2f(-175.0f,160.0f);
glVertex2f(-190.0f,160.0f);
glVertex2f(-195.0f,135.0f);
glVertex2f(-150.0f,200.0f);
glVertex2f(60.0f,180.0f);
glVertex2f(80.0f,180.0f);
glVertex2f(60.0f,160.0f);
glVertex2f(80.0f,160.0f);
glVertex2f(70.0f,170.0f);
glVertex2f(70.0f,210.0f);
glVertex2f(70.0f,190.0f);
glVertex2f(90.0f,190.0f);
glVertex2f(90.0f,210.0f);
glVertex2f(80.0f,200.0f);
glVertex2f(60.0f,250.0f);
glVertex2f(80.0f,250.0f);
glVertex2f(60.0f,230.0f);
glVertex2f(80.0f,230.0f);
glVertex2f(70.0f,240.0f);
glVertex2f(70.0f,260.0f);
glVertex2f(60.0f,270.0f);
glVertex2f(60.0f,230.0f);
glVertex2f(80.0f,230.0f);
glVertex2f(70.0f,240.0f);
glVertex2f(40.0f,250.0f);
glVertex2f(30.0f,260.0f);
glVertex2f(50.0f,260.0f);
glVertex2f(140.0f,270.0f);
glVertex2f(140.0f,410.0f);
glVertex2f(170.0f,240.0f);
glVertex2f(190.0f,230.0f);
glVertex2f(190.0f,250.0f);
glVertex2f(180.0f,220.0f);
glVertex2f(170.0f,210.0f);
glVertex2f(190.0f,200.0f);
glVertex2f(180.0f,180.0f);
glVertex2f(170.0f,170.0f);
glVertex2f(-10.0f,270.0f);
glVertex2f(-10.0f,250.0f);
glVertex2f(10.0f,270.0f);
glVertex2f(10.0f,250.0f);
glVertex2f(0.0f,260.0f);
glVertex2f(-10.0f,230.0f);
glVertex2f(-10.0f,210.0f);
glVertex2f(10.0f,230.0f);
glVertex2f(10.0f,210.0f);
glVertex2f(0.0f,220.0f);
glVertex2f(0.0f,240.0f);
glVertex2f(90.0f,160.0f);
glVertex2f(110.0f,160.0f);
glVertex2f(90.0f,140.0f);
glVertex2f(110.0f,140.0f);
glVertex2f(100.0f,150.0f);
glVertex2f(-20.0f,160.0f);
glVertex2f(-20.0f,140.0f);
glVertex2f(-10.0f,150.0f);
glVertex2f(0.0f,140.0f);
glVertex2f(0.0f,160.0f);
glVertex2f(-10.0f,170.0f);
glVertex2f(-10.0f,130.0f);
glVertex2f(30.0f,220.0f);
glVertex2f(50.0f,220.0f);
glVertex2f(30.0f,200.0f);
glVertex2f(50.0f,200.0f);
glVertex2f(40.0f,210.0f);
glVertex2f(30.0f,180.0f);
glVertex2f(50.0f,180.0f);
glVertex2f(30.0f,160.0f);
glVertex2f(50.0f,160.0f);
glVertex2f(40.0f,170.0f);
glVertex2f(20.0f,140.0f);
glVertex2f(40.0f,140.0f);
glVertex2f(60.0f,140.0f);
glVertex2f(10.0f,190.0f);
glVertex2f(10.0f,170.0f);
glVertex2f(10.0f,150.0f);
glVertex2f(10.0f,130.0f);
glVertex2f(140.0f,150.0f);
glVertex2f(140.0f,130.0f);
glVertex2f(160.0f,150.0f);
glVertex2f(160.0f,130.0f);
glVertex2f(150.0f,140.0f);
glVertex2f(190.0f,150.0f);
glVertex2f(190.0f,130.0f);
glVertex2f(210.0f,150.0f);
glVertex2f(210.0f,130.0f);
glVertex2f(200.0f,140.0f);
glVertex2f(120.0f,180.0f);
glVertex2f(130.0f,160.0f);
glVertex2f(140.0f,150.0f);
glVertex2f(140.0f,130.0f);
glVertex2f(110.0f,190.0f);
glVertex2f(110.0f,210.0f);
glVertex2f(100.0f,220.0f);
glVertex2f(110.0f,230.0f);
glVertex2f(110.0f,250.0f);
glVertex2f(100.0f,260.0f);
glVertex2f(110.0f,270.0f);
glVertex2f(90.0f,270.0f);
glVertex2f(94.0f,242.0f);
glVertex2f(-40.0f,180.0f);
glVertex2f(-50.0f,160.0f);
glVertex2f(-50.0f,140.0f);
glVertex2f(-36.0f,146.0f);
glVertex2f(-90.0f,170.0f);
glVertex2f(-90.0f,150.0f);
glVertex2f(-70.0f,170.0f);
glVertex2f(-70.0f,150.0f);
glVertex2f(-80.0f,160.0f);
glVertex2f(-70.0f,190.0f);
glVertex2f(90.0f,190.0f);
glVertex2f(80.0f,146.0f);
glVertex2f(-40.0f,260.0f);
glVertex2f(-50.0f,250.0f);
glVertex2f(-60.0f,270.0f);

glEnd();

glPopMatrix();





glPushMatrix();
//M4

glBegin(GL_POLYGON);
//comet middle
glColor3ub(30, 183, 251);
glVertex2f(138.0f,464.0f);
glVertex2f(138.0f,460.0f);
glVertex2f(142.0f,460.0f);
glVertex2f(142.0f,464.0f);
glEnd();

glBegin(GL_POLYGON);
//comet right triangle
glColor3ub(30, 183, 251);
glVertex2f(142.0f,464.0f);
glVertex2f(142.0f,460.0f);
glVertex2f(180.0f,462.0f);
glEnd();

glBegin(GL_POLYGON);
//comet up triangle
glColor3ub(30, 183, 251);
glVertex2f(140.0f,468.0f);
glVertex2f(138.0f,464.0f);
glVertex2f(142.0f,464.0f);
glEnd();

glBegin(GL_POLYGON);
//comet down triangle
glColor3ub(30, 183, 251);
glVertex2f(138.0f,460.0f);
glVertex2f(140.0f,456.0f);
glVertex2f(142.0f,460.0f);
glEnd();

glPopMatrix();






	glBegin(GL_POLYGON);//comet_circle

	for(int i=0;i<300;i++)
        {
            glColor3ub(30, 183, 251);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=4.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+137,y+462);
        }

	glEnd();














glBegin(GL_POLYGON);//world_whole_circle
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,70);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=250.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+0,y-100);
        }

	glEnd();


glBegin(GL_POLYGON);//M5
//earth area1
glColor3ub(50, 191, 87);

glVertex2f(-200.0f,0.0f);
glVertex2f(-180.0f,0.0f);
glVertex2f(-160.0f,0.0f);
glVertex2f(-150.0f,0.0f);
glVertex2f(-115.0f,0.0f);
glVertex2f(-120.0f,5.0f);
glVertex2f(-130.0f,10.0f);
glVertex2f(-140.0f,20.0f);
glVertex2f(-145.0f,25.0f);
glVertex2f(-155.0f,25.0f);
glVertex2f(-170.0f,30.0f);
glVertex2f(-180.0f,22.0f);
glVertex2f(-190.0f,22.0f);
glVertex2f(-200.0f,22.0f);
glEnd();



glBegin(GL_POLYGON);
//earth area2
glColor3ub(50, 191, 87);

glVertex2f(-140.0f,80.0f);
glVertex2f(-130.0f,90.0f);
glVertex2f(-100.0f,100.0f);
glVertex2f(-80.0f,115.0f);
glVertex2f(-65.0f,115.0f);
glVertex2f(-55.0f,125.0f);
glVertex2f(-40.0f,120.0f);
glVertex2f(-30.0f,110.0f);
glVertex2f(-20.0f,110.0f);
glVertex2f(-10.0f,100.0f);
glVertex2f(-25.0f,85.0f);
glVertex2f(-35.0f,85.0f);
glVertex2f(-50.0f,80.0f);
glVertex2f(-60.0f,75.0f);
glVertex2f(-70.0f,75.0f);
glVertex2f(-85.0f,60.0f);
glVertex2f(-100.0f,65.0f);
glVertex2f(-115.0f,60.0f);
glVertex2f(-125.0f,58.0f);
glVertex2f(-130.0f,55.0f);
glVertex2f(-135.0f,65.0f);
glVertex2f(-145.0f,65.0f);

glEnd();


glBegin(GL_POLYGON);
//earth area3
glColor3ub(50, 191, 87);

glVertex2f(80.0f,0.0f);
glVertex2f(50.0f,0.0f);
glVertex2f(10.0f,0.0f);
glVertex2f(-50.0f,0.0f);
glVertex2f(-85.0f,0.0f);
glVertex2f(-70.0f,10.0f);
glVertex2f(-65.0f,15.0f);
glVertex2f(-50.0f,22.0f);
glVertex2f(-35.0f,35.0f);
glVertex2f(-15.0f,35.0f);
glVertex2f(-10.0f,25.0f);
glVertex2f(0.0f,15.0f);
glVertex2f(20.0f,15.0f);
glVertex2f(30.0f,30.0f);
glVertex2f(50.0f,35.0f);
glVertex2f(60.0f,25.0f);
glVertex2f(65.0f,25.0f);
glVertex2f(70.0f,25.0f);
glVertex2f(80.0f,25.0f);
glVertex2f(85.0f,15.0f);
glVertex2f(95.0f,15.0f);
glVertex2f(105.0f,10.0f);
glVertex2f(115.0f,0.0f);

glEnd();



glBegin(GL_POLYGON);
//earth area4
glColor3ub(50, 191, 87);

glVertex2f(50.0f,110.0f);
glVertex2f(65.0f,120.0f);
glVertex2f(75.0f,120.0f);
glVertex2f(90.0f,105.0f);
glVertex2f(100.0f,100.0f);
glVertex2f(105.0f,90.0f);
glVertex2f(100.0f,85.0f);
glVertex2f(80.0f,85.0f);
glVertex2f(70.0f,80.0f);
glVertex2f(60.0f,80.0f);
glVertex2f(50.0f,80.0f);
glVertex2f(40.0f,85.0f);
glVertex2f(40.0f,100.0f);

glEnd();




glBegin(GL_POLYGON);
//earth area5
glColor3ub(50, 191, 87);

glVertex2f(200.0f,0.0f);
glVertex2f(180.0f,0.0f);
glVertex2f(160.0f,0.0f);
glVertex2f(150.0f,0.0f);
glVertex2f(140.0f,10.0f);
glVertex2f(130.0f,25.0f);
glVertex2f(135.0f,30.0f);
glVertex2f(140.0f,38.0f);
glVertex2f(145.0f,38.0f);
glVertex2f(155.0f,42.0f);
glVertex2f(158.0f,43.0f);
glVertex2f(161.0f,46.0f);
glVertex2f(166.0f,50.0f);
glVertex2f(170.0f,55.0f);
glVertex2f(180.0f,63.0f);
glVertex2f(190.0f,55.0f);
glVertex2f(200.0f,48.0f);
glEnd();







glPushMatrix();

glTranslatef(0.0f,Rocketposition, 0.0f);

glBegin(GL_POLYGON);
//rocket black tail
glColor3ub(160, 160, 160);
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
glColor3ub(160, 160, 160);
glVertex2f(8.0f,160.0f);
glVertex2f(8.0f,140.0f);
glVertex2f(20.0f,140.0f);
glEnd();

glBegin(GL_TRIANGLES);
//rocket left wing
glColor3ub(160, 160, 160);
glVertex2f(-8.0f,160.0f);
glVertex2f(-20.0f,140.0f);
glVertex2f(-8.0f,140.0f);
glEnd();

glBegin(GL_LINES);
//rocket flames
glColor3ub(235, 60, 2);
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

glPopMatrix();






glBegin(GL_POLYGON);//sun_big_circle_1
//M6
	for(int i=0;i<300;i++)
        {
            glColor3ub(248, 172, 1);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=32.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-62,y+300);
        }

	glEnd();


glBegin(GL_POLYGON);//sun_big_circle_2

	for(int i=0;i<300;i++)
        {
            glColor3ub(255, 204, 1);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=27.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-62,y+300);
        }

	glEnd();


	glPushMatrix();
glLineWidth(13.0);
glTranslatef(-62.0f,300.0f,0.0f);
glRotatef(PlanetAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//sun_circle_round_border
	for(int i=0;i<200;i++)
        {
            glColor3ub(255, 204, 1);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=34.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();





glBegin(GL_POLYGON);//mars_big_circle
//M7
	for(int i=0;i<300;i++)
        {
            glColor3ub(167, 42, 50);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=34.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+130,y+380);
        }

	glEnd();


glBegin(GL_POLYGON);//mars_small_1

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+140,y+380);
        }

	glEnd();

	glBegin(GL_POLYGON);//mars_small_2

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=6.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+145,y+365);
        }

	glEnd();

	glBegin(GL_POLYGON);//mars_small_3

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=3.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+125,y+360);
        }

	glEnd();

	glBegin(GL_POLYGON);//mars_small_4

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=4.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+132,y+400);
        }

	glEnd();


	glBegin(GL_POLYGON);//mars_small_5

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+155,y+372);
        }

	glEnd();

	glBegin(GL_POLYGON);//mars_big_small_6

	for(int i=0;i<300;i++)
        {
            glColor3ub(137, 26, 38);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=2.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+110,y+380);
        }

	glEnd();




	glPushMatrix();
glLineWidth(6.0);
glTranslatef(130.0f,380.0f,0.0f);
glRotatef(PlanetAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//mars_circle_round_border
	for(int i=0;i<200;i++)
        {
            glColor3ub(167, 42, 50);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=34.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();



	glBegin(GL_POLYGON);//jupiter_big_circle
//M8
	for(int i=0;i<300;i++)
        {
            glColor3ub(226, 153, 74);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=22.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-130,y+430);
        }

	glEnd();


glBegin(GL_POLYGON);//jupiter_texture_circle_1

	for(int i=0;i<300;i++)
        {
            glColor3ub(164, 82, 35);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=6.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-130,y+416);
        }

	glEnd();

	glBegin(GL_POLYGON);//jupiter_texture_circle_2

	for(int i=0;i<300;i++)
        {
            glColor3ub(164, 82, 35);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=4.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-120,y+425);
        }

	glEnd();


        glBegin(GL_POLYGON);//jupiter_texture_circle_3

	for(int i=0;i<300;i++)
        {
            glColor3ub(164, 82, 35);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=2.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-145,y+420);
        }

	glEnd();

	glBegin(GL_POLYGON);//jupiter_texture_circle_4

	for(int i=0;i<300;i++)
        {
            glColor3ub(164, 82, 35);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=3.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-125,y+445);
        }

	glEnd();

	glBegin(GL_POLYGON);//jupiter_texture_circle_5

	for(int i=0;i<300;i++)
        {
            glColor3ub(164, 82, 35);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/300;
            float r=2.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-145,y+430);
        }

	glEnd();

glPushMatrix();
glLineWidth(6.0);
glTranslatef(-130.0f,+430.0f,0.0f);
glRotatef(PlanetAngle, 0.0f, 0.0f,1.0f);
glBegin(GL_LINES);//jupiter_circle_round_border
	for(int i=0;i<200;i++)
        {
            glColor3ub(226, 153, 74);
            //glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=22.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();




glPushMatrix();
glLineWidth(4.0);
glTranslatef(-144.0f,136.0f,0.0f);
glRotatef(PlanetAngle, 0.0f, 0.0f,1.0f);
glPopMatrix();
glutTimerFunc(11000, tanimDisplay,0);
glFlush(); // Render now
}

void tasfia(int val){

glutDisplayFunc(display2);

}





void display1() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
//glLoadIdentity();
//glMatrixMode(GL_MODELVIEW);
glColor3ub(38,77,115);

bac();
BackStars();
PlanetZ();
moon();
sootingStar1();
sootingStar2();
backBuildings();
rocket();
station();
Stationcircles();
stationLeftBulb();
StationRightBulb();

glLineWidth(3.0);
 glutTimerFunc(9000, tasfia,0);
glFlush(); // Render now
}

void disRaihan(){

glutDisplayFunc(display1);

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



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitWindowSize(1280, 1024);
glutCreateWindow("Space Port By Rayhan Ahmed "); // Create a window with the given title

//faisal
glutTimerFunc(20, radarUpdate1, 0);
glutTimerFunc(20,radarUpdate2,0);
glutTimerFunc(20,sateliteUpdate,0);
glutTimerFunc(20,moveAstronautLeft,0);
glutTimerFunc(20,moveShootingStar,0);
glutSpecialFunc(SpecialInput);


//raihan
glutTimerFunc(100, LeftBulbUpdate, 0);
glutTimerFunc(100, moonUpdate, 0);
glutTimerFunc(2,PlanetZUpdate, 0);
glutTimerFunc(100, RocketUpdate, 0);
glutTimerFunc(100, SootingStar2Update, 0);
glutTimerFunc(100, SootingStar1Update, 0);
//tasfia
glutTimerFunc(70, PlanetRotate, 0);
//tanim
glutTimerFunc(2,circle_round, 0);
glutTimerFunc(10,Movement_of_star, 0);
gluOrtho2D(-200,200,0,480); // Set the window's initial width & height
glutDisplayFunc(display1); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}

