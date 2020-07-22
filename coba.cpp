/*Kelompok 3 Emirates Stadium 
1. Jovan Millenno Claudiyap (672018086)
2. Graciela Fausten Novindri (672018057)
3. Adimas TristaN N.H (672018063)
*/
#include <math.h>
#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#define ZOOM_FACTOR 0.05f
#define UNITS_PER_PIXEL 1.0f
#define UNITS_PER_PIXELS 0.1f
#define RATIO 1.200 
#define WW 100
#define WH (WW/RATIO) 
#define deltat .001


int w;
int is_depth;
const double Pi = 3.141592653589793;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
static GLfloat spin = 0.0;
bool mouseDown = false;
int i, x_tengah = 0, y_tengah = 50;

typedef struct{
	bool leftButton, rightButton;
	int x;
	int y;
}MouseState;
MouseState mouseState = {false, false, 0,0};
float xRotate =0,yRotate=0;
GLfloat eye[]={5,5,10};
GLfloat at[]= {0,0,0};
GLfloat light1_position[]={0.0,0.0,1.0,1.0};

void lighting(void) {
glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
}

int x=0;
void bola(){
	if(x<20)
	{
		x +=1;	
	}
	else
	{
		x=-1;
		
	}
		//bola
	glPushMatrix();
	glTranslatef(x, 1.1, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(1.0, 20, 10);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(1.0, 20, 10);
	glFlush();
	glPopMatrix();
	
	//bola luar
	glPushMatrix();
	glTranslatef(-57.0, 12.1, 43.0);
	glColor3f(0.9, 0.9, 0.2);
	glutWireSphere(4.0, 20, 10);
	glFlush();
	glPopMatrix();
}

void ikigambar(void) {
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(spin, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	GLfloat x = 0.0; GLfloat y = 50.0; GLfloat angle_stepsize = 1.0; GLfloat height = 30.0; GLfloat radius = -40.0; GLfloat jumlah_titik = 20;
	int k;
	//ini tv dinding
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.9, 0.0, 0.1);
	for (k = 16; k <= jumlah_titik; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x-0.5, height - 5, y);
		glVertex3f(x-0.5, 5.0, y + 0.3);
		sudut = sudut + angle_stepsize;
	}
	glEnd();
	//atas tv
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.2, 0.2, 0.2);
	for (k = 16; k <= jumlah_titik; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x-0.5, height - 3, y);
		glVertex3f(x-0.5, 20.0, y + 0.3);
		sudut = sudut + angle_stepsize;
	}
	glEnd();
	//E
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-39.5-0.5, 21, 5);
	glVertex3f(-39.5-0.5, 21, 7);
	glVertex3f(-39.5-0.5, 21, 5);
	glVertex3f(-39.5-0.5, 22.5, 5);
	glVertex3f(-39.5-0.5, 22.5, 7);
	glVertex3f(-39.5-0.5, 22.5, 5);
	glVertex3f(-39.5-0.5, 24., 5);
	glVertex3f(-39.5-0.5, 24., 7);
	glEnd();

	//M
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-38.5-0.5, 21, 9);
	glVertex3f(-38.5-0.5, 24, 9);
	glVertex3f(-38.5-0.5, 21, 10);
	glVertex3f(-38.5-0.5, 24, 11);
	glVertex3f(-38.5-0.5, 21, 11);
	glEnd();
	//I
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-37.5-0.5, 21, 13);
	glVertex3f(-37.5-0.5, 24, 13);
	glEnd();
	//R
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-36.5-0.5, 21, 15);
	glVertex3f(-36.5-0.5, 24, 15);
	glVertex3f(-35.5-0.5, 24, 17);
	glVertex3f(-35.5-0.5, 22.5, 17);
	glVertex3f(-36.5-0.5, 22.5, 15);
	glVertex3f(-35.5-0.5, 21, 17);
	glEnd();
	//A
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-34-0.5, 21, 19);
	glVertex3f(-33.5-0.5, 24, 20);
	glVertex3f(-32.7-0.5, 21, 21);
	glVertex3f(-32-0.5, 22, 21.1);
	glVertex3f(-34-0.5, 22, 19.5);
	glEnd();
	//T
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-31.5-0.5, 24, 22);
	glVertex3f(-29-0.5, 24, 25);
	glVertex3f(-30-0.5, 24, 23.5);
	glVertex3f(-30.2-0.5, 21, 23.5);
	glEnd();
	//E
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-27.4-0.5, 21, 26);
	glVertex3f(-25.5-0.5, 21, 28);
	glVertex3f(-27.4-0.5, 21, 26);
	glVertex3f(-27.6-0.5, 22.5, 26);
	glVertex3f(-25.6-0.5, 22.5, 28);
	glVertex3f(-27.6-0.5, 22.5, 26);
	glVertex3f(-27.4-0.5, 24., 26);
	glVertex3f(-25.5-0.5, 24., 28);
	glEnd();
	//S
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(-24.2-0.5, 21, 29);
	glVertex3f(-20.7-0.5, 21, 31);
	glVertex3f(-20.7-0.5, 22.5, 31);
	glVertex3f(-24.2-0.5, 22.5, 29);
	glVertex3f(-24-0.5, 24, 29);
	glVertex3f(-20.7-0.5, 24, 31);
	glEnd();
	//bawah tv
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.6, 0.6, 0.6);
	for (k = 16; k <= jumlah_titik; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x, height - 24.5, y);
		glVertex3f(x, 0.0, y + 0.3);
		sudut = sudut + angle_stepsize;
	}
	glEnd();
	//pintu
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(x + 0.5, 0.0, y + 3);
	glVertex3f(x + 0.5, 5.0, y + 3);
	glVertex3f(x + 0.9, 5.0, y + 8);
	glVertex3f(x + 0.9, 0.0, y + 8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(x + 2.0, 0.0, y + 12);
	glVertex3f(x + 2.0, 5.0, y + 12);
	glVertex3f(x + 5.1, 5.0, y + 17);
	glVertex3f(x + 5.1, 0.0, y + 17);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(x + 7.2, 0.0, y + 21);
	glVertex3f(x + 7.2, 5.0, y + 21);
	glVertex3f(x + 9, 5.0, y + 23);
	glVertex3f(x + 9, 0.0, y + 23);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(x + 12.6, 0.0, y + 27);
	glVertex3f(x + 12.6, 5.0, y + 27);
	glVertex3f(x + 20.6, 5.0, y + 32);
	glVertex3f(x + 20.6, 0.0, y + 32);
	glEnd();


	//dinding sekitar
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8, 0.8, 0.8);
	for (k = 0; k <= jumlah_titik; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x, height - 0, y + 0.1);
		glVertex3f(x, 0.0, y);
		sudut = sudut + angle_stepsize;
	}
	glEnd();
	//kaca
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 1.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 1.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 6.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 6.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 11.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 11.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 16.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 16.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 21.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 21.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 26.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 26.0, y - 50.1);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 49.9);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 50.1);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);//1
	glColor3f(1, 1, 1);
	glVertex3f(x, height, y);
	glVertex3f(x, height - height, y);
	glEnd();
	glBegin(GL_LINE_STRIP);//2
	glColor3f(1, 1, 1);
	glVertex3f(x+1, height, y-7);
	glVertex3f(x+1, height - height, y-7);
	glEnd();
	glBegin(GL_LINE_STRIP);//3
	glColor3f(1, 1, 1);
	glVertex3f(x+3, height, y-14);
	glVertex3f(x+3, height - height, y-14);
	glEnd();
	glBegin(GL_LINE_STRIP);//4
	glColor3f(1, 1, 1);
	glVertex3f(x+7, height, y-21);
	glVertex3f(x+7, height - height, y-21);
	glEnd();
	glBegin(GL_LINE_STRIP);//5
	glColor3f(1, 1, 1);
	glVertex3f(x+13.5, height, y-27);
	glVertex3f(x+13.5, height - height, y-27);
	glEnd();
	glBegin(GL_LINE_STRIP);//6
	glColor3f(1, 1, 1);
	glVertex3f(x+22, height, y-32);
	glVertex3f(x+22, height - height, y-32);
	glEnd();
	glBegin(GL_LINE_STRIP);//7
	glColor3f(1, 1, 1);
	glVertex3f(x + 30, height, y - 35);
	glVertex3f(x + 30, height - height, y - 35);
	glEnd();
	glBegin(GL_LINE_STRIP);//8
	glColor3f(1, 1, 1);
	glVertex3f(x + 38, height, y - 36);
	glVertex3f(x + 38, height - height, y - 36);
	glEnd();
	glBegin(GL_LINE_STRIP);//9
	glColor3f(1, 1, 1);
	glVertex3f(x + 46, height, y - 35.5);
	glVertex3f(x + 46, height - height, y - 35.5);
	glEnd();
	glBegin(GL_LINE_STRIP);//10
	glColor3f(1, 1, 1);
	glVertex3f(x + 54, height, y - 34);
	glVertex3f(x + 54, height - height, y - 34);
	glEnd();
	glBegin(GL_LINE_STRIP);//11
	glColor3f(1, 1, 1);
	glVertex3f(x + 62, height, y - 30);
	glVertex3f(x + 62, height - height, y - 30);
	glEnd();
	glBegin(GL_LINE_STRIP);//12
	glColor3f(1, 1, 1);
	glVertex3f(x + 69, height, y - 25);
	glVertex3f(x + 69, height - height, y - 25);
	glEnd();
	glBegin(GL_LINE_STRIP);//13
	glColor3f(1, 1, 1);
	glVertex3f(x + 75, height, y - 17.5);
	glVertex3f(x + 75, height - height, y - 17.5);
	glEnd();
	glBegin(GL_LINE_STRIP);//14
	glColor3f(1, 1, 1);
	glVertex3f(x + 78.5, height, y - 9);
	glVertex3f(x + 78.5, height - height, y - 9);
	glEnd();
	glBegin(GL_LINE_STRIP);//15
	glColor3f(1, 1, 1);
	glVertex3f(x + 80.2, height, y - 0);
	glVertex3f(x + 80.2, height - height, y - 0);
	glEnd();
	glBegin(GL_LINE_STRIP);//16
	glColor3f(1, 1, 1);
	glVertex3f(x + 79, height, y + 8);
	glVertex3f(x + 79, height - height, y + 8);
	glEnd();
	glBegin(GL_LINE_STRIP);//17
	glColor3f(1, 1, 1);
	glVertex3f(x + 76.2, height, y + 15);
	glVertex3f(x + 76.2, height - height, y + 15);
	glEnd();
	glBegin(GL_LINE_STRIP);//18
	glColor3f(1, 1, 1);
	glVertex3f(x + 72, height, y + 22);
	glVertex3f(x + 72, height - height, y + 22);
	glEnd();
	glBegin(GL_LINE_STRIP);//19
	glColor3f(1, 1, 1);
	glVertex3f(x + 66.2, height, y + 27);
	glVertex3f(x + 66.2, height - height, y + 27);
	glEnd();
	glBegin(GL_LINE_STRIP);//20
	glColor3f(1, 1, 1);
	glVertex3f(x + 60, height, y + 31);
	glVertex3f(x + 60, height - height, y + 31);
	glEnd();
	glBegin(GL_LINE_STRIP);//21
	glColor3f(1, 1, 1);
	glVertex3f(x + 53.5, height, y + 34);
	glVertex3f(x + 53.5, height - height, y + 34);
	glEnd();
	glBegin(GL_LINE_STRIP);//22
	glColor3f(1, 1, 1);
	glVertex3f(x + 46.5, height, y + 36);
	glVertex3f(x + 46.5, height - height, y + 36);
	glEnd();
	glBegin(GL_LINE_STRIP);//23
	glColor3f(1, 1, 1);
	glVertex3f(x + 38, height, y + 36.);
	glVertex3f(x + 38, height - height, y + 36.);
	glEnd();
	glBegin(GL_LINE_STRIP);//23
	glColor3f(1, 1, 1);
	glVertex3f(x + 27.7, height, y + 34.7);
	glVertex3f(x + 27.7, height - height, y + 34.7);
	glEnd();
	//dinding sekitar
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8, 0.8, 0.8);
	for (k = 0; k <= jumlah_titik; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x, height - 0, y - 0.1);
		glVertex3f(x, 0.0, y);
		sudut = sudut + angle_stepsize;
	}
	glEnd();
	//dinding stadion
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.7, 0.7, 0.7);
	for (k = 0; k <= 360; k++) {
		float sudut = k * (2 * Pi / jumlah_titik);
		x = radius * cos(sudut);
		y = (radius + 4) * sin(sudut);
		glVertex3f(x, height, y);
		glVertex3f(x, 0.0, y);
		sudut = sudut + angle_stepsize;
	}
	glVertex3f(radius, height, 0.0);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();
	//lantai 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.0, y - 50);
	}
	glEnd();
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, -0.8, y - 50);
	}
	glEnd();
	//atap belakang 
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	int j;
	for (j = 3.5; j <= jumlah_titik - 10.5; j++) {
		float sudut = j * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 50);
	}
	glEnd();
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-23.0, 30.0, -29.0);
	glVertex3f(-7.75, 35.0, -24.5);
	glVertex3f(7.5, 36.0, -20.0);
	glVertex3f(22.75, 35.0, -15.5);
	glVertex3f(38.0, 30.0, -11.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-12.75, 30.0, -26.0);
	glVertex3f(-7.75, 35.0, -24.5);
	glVertex3f(-2.75, 30.0, -22.75);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-2.75, 30.0, -22.75);
	glVertex3f(3.75, 35.75, -21.0);
	glVertex3f(8.75, 30.0, -19.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(8.75, 30.0, -19.5);
	glVertex3f(13.75, 35.75, -17.75);
	glVertex3f(18.75, 30.0, -16.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(18.75, 30.0, -16.0);
	glVertex3f(23.75, 35.0, -14.5);
	glVertex3f(28.75, 30.0, -13.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(3.75, 35.75, -21.0);
	glVertex3f(8.0, 30.0, -35.0);
	glVertex3f(3.75, 30, -21.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-7.75, 35.0, -24.5);
	glVertex3f(-4.75, 30.0, -35.5);
	glVertex3f(-7.75, 30.0, -24.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(23.75, 35.0, -14.5);
	glVertex3f(27.75, 30.75, -25.5);
	glVertex3f(23.75, 30.0, -14.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(13.75, 35.75, -17.75);
	glVertex3f(18.75, 30.0, -31.75);
	glVertex3f(13.75, 30, -17.75);
	glEnd();
	//atap depan
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	int f;
	for (f = 13.5; f <= jumlah_titik - 0.5; f++) {
		float sudut = f * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 50);
	}
	glEnd();
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-38.0, 30.0, 11.0);
	glVertex3f(-22.75, 35.0, 15.5);
	glVertex3f(-7.5, 36.0, 20.0);
	glVertex3f(7.75, 35.0, 24.5);
	glVertex3f(23.0, 30.0, 29.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-18.75, 30.0, 16.0);
	glVertex3f(-23.75, 35.0, 14.5);
	glVertex3f(-28.75, 30.0, 13.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-8.75, 30.0, 19.5);
	glVertex3f(-13.75, 35.75, 17.75);
	glVertex3f(-18.75, 30.0, 16.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(12.75, 30.0, 26.0);
	glVertex3f(7.75, 35.0, 24.5);
	glVertex3f(2.75, 30.0, 22.75);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(2.75, 30.0, 22.75);
	glVertex3f(-3.75, 35.75, 21.0);
	glVertex3f(-8.75, 30.0, 19.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-3.75, 35.75, 21.0);
	glVertex3f(-8.0, 30.0, 35.0);
	glVertex3f(-3.75, 30, 21.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(7.75, 35.0, 24.5);
	glVertex3f(4.75, 30.0, 35.5);
	glVertex3f(7.75, 30.0, 24.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-23.75, 35.0, 14.5);
	glVertex3f(-27.75, 30.75, 25.5);
	glVertex3f(-23.75, 30.0, 14.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-13.75, 35.75, 17.75);
	glVertex3f(-18.75, 30.0, 31.75);
	glVertex3f(-13.75, 30, 17.75);
	glEnd();
	//atap kanan
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	int g;
	for (g = 8.5; g <= jumlah_titik - 5.5; g++) {
		float sudut = g * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 50);
	}
	glEnd();
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(32.0, 30.0, -21.0);
	glVertex3f(27.25, 35.0, -7.5);
	glVertex3f(22.5, 36.0, 6.0);
	glVertex3f(17.75, 35.0, 19.5);
	glVertex3f(13.0, 30.0, 33.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(19.75, 30.0, 14.875);
	glVertex3f(22.75, 36.0, 6.25);
	glVertex3f(25.75, 30.0, -2.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(25.75, 30.0, -2.5);
	glVertex3f(27.5, 35.0, -7.375);
	glVertex3f(29.75, 30.0, -12.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(15.75, 30.0, 24.875);
	glVertex3f(17.75, 35.0, 19.875);
	glVertex3f(19.75, 30.0, 14.875);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(17.75, 35.0, 19.875);
	glVertex3f(29.75, 30.0, 22.875);
	glVertex3f(17.75, 30.0, 19.875);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(22.75, 36.0, 6.25);
	glVertex3f(37.75, 30.0, 10.75);
	glVertex3f(22.75, 30.0, 6.25);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(27.5, 35.0, -7.375);
	glVertex3f(39.5, 30.0, -4.375);
	glVertex3f(27.5, 30.0, -7.375);
	glEnd();
	//atap kiri
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	int h;
	for (h = -2.5; h <= jumlah_titik - 15.5; h++) {
		float sudut = h * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 30.0, y - 50);
	}
	glEnd();
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-13.0, 30.0, -33.5);
	glVertex3f(-17.75, 35.0, -19.875);
	glVertex3f(-22.75, 36.0, -6.25);
	glVertex3f(-27.5, 35.0, 7.375);
	glVertex3f(-32.5, 30.0, 21.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-15.75, 30.0, -24.875);
	glVertex3f(-17.75, 35.0, -19.875);
	glVertex3f(-19.75, 30.0, -14.875);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-19.75, 30.0, -14.875);
	glVertex3f(-22.75, 36.0, -6.25);
	glVertex3f(-25.75, 30.0, 2.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-25.75, 30.0, 2.5);
	glVertex3f(-27.5, 35.0, 7.375);
	glVertex3f(-29.75, 30.0, 12.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-17.75, 35.0, -19.875);
	glVertex3f(-29.75, 30.0, -22.875);
	glVertex3f(-17.75, 30.0, -19.875);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-22.75, 36.0, -6.25);
	glVertex3f(-37.75, 30.0, -10.75);
	glVertex3f(-22.75, 30.0, -6.25);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-27.5, 35.0, 7.375);
	glVertex3f(-39.5, 30.0, 4.375);
	glVertex3f(-27.5, 30.0, 7.375);
	glEnd();
	//garis atap
	float pxx, pzz, pii, pyy, Mgh, Cgh, ax = -13, ay = 30, az = -33.5, bx = -32.5, by = 30, bz = 21, cx = 32, cy = 30, cz = -21, dx = 13, dy = 30, dz = 33, ex = -23, ey = 30, ez = -29, fx = 38, fy = 30, fz = -11, gx = -38, gy = 30, gz = 11, hx = 23, hy = 30, hz = 29, Mab, Mcd, Cab, Mef, Cef, Ccd, px, py, pz, pi;
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(ax, ay, az);
	glVertex3f(bx, by, bz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(cx, cy, cz);
	glVertex3f(dx, dy, dz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(ex, ey, ez);
	glVertex3f(fx, fy, fz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(gx, gy, gz);
	glVertex3f(hx, hy, hz);
	glEnd();
	//rumus perpotongan
	Mab = (bz - az) / (bx - ax);
	Mcd = (dz - cz) / (dx - cx);
	Mef = (fz - ez) / (fx - ex);
	Mgh = (hz - gz) / (hx - gx);
	Cab = az - (ax * Mab);
	Ccd = cz - (cx * Mcd);
	Cef = ez - (ex * Mef);
	Cgh = gz - (gx * Mgh);

	//titik potong
	px = (Cab - Cgh) / (Mgh - Mab);
	py = (Mab * px) + Cab;
	pz = (Cef - Cab) / (Mab - Mef);
	pi = (Mef * pz) + Cef;
	pxx = (Cgh - Ccd) / (Mcd - Mgh);
	pyy = (Mcd * pxx) + Ccd;
	pzz = (Cef - Ccd) / (Mcd - Mef);
	pii = (Mcd * pzz) + Ccd;

	//Hasil
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_POINTS);
	glVertex3f(px, 30.0, py);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pz, 30.0, pi);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pxx, 30.0, pyy);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pzz, 30.0, pii);
	glEnd();
	//lantai belakang 
	glColor3f(0.8, 0.2, 0.0);
	glBegin(GL_POLYGON);
	for (j = 3.5; j <= jumlah_titik - 10.5; j++) {
		float sudut = j * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.1, y - 50);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (j = 3.5; j <= jumlah_titik - 10.5; j++) {
		float sudut = j * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.1, y - 50);
	}
	glEnd();
	//lantai kiri 
	glBegin(GL_POLYGON);
	for (h = -2.5; h <= jumlah_titik - 15.5; h++) {
		float sudut = h * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.1, y - 50);
	}
	glEnd();
	//lantai kanan
	glBegin(GL_POLYGON);
	for (g = 8.5; g <= jumlah_titik - 5.5; g++) {
		float sudut = g * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.1, y - 50);
	}
	glEnd();
	//lantai bawah
	glBegin(GL_POLYGON);
	for (f = 13.5; f <= jumlah_titik - 0.5; f++) {
		float sudut = f * (2 * Pi / jumlah_titik);
		float x = x_tengah + radius * cos(sudut);
		float y = y_tengah + (radius + 4) * sin(sudut);
		glVertex3f(x, 0.1, y - 50);
	}
	glEnd();


	//garis lapangan
	glBegin(GL_LINE_LOOP);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(px, 0.11, py);
	glVertex3f(pz, 0.11, pi);
	glVertex3f(pzz, 0.11, pii);
	glVertex3f(pxx, 0.11, pyy);
	glEnd();
	//pagar k.l.d
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(16.0, 0.12, 27.5);
	glVertex3f(-31.0, 0.12, 13.5);
	glVertex3f(-31.0, 1.0, 13.5);
	glVertex3f(16.0, 1.0, 27.5);
	glEnd();

	//pagar k.l.b
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-16.0, 0.12, -27.5);
	glVertex3f(30.0, 0.12, -13.5);
	glVertex3f(30.0, 1.0, -13.5);
	glVertex3f(-16.0, 1.0, -27.5);
	glEnd();

	//pagar k.l.ki
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-16.0, 0.12, -27.5);
	glVertex3f(-31.0, 0.12, 13.5);
	glVertex3f(-31.0, 1.0, 13.5);
	glVertex3f(-16.0, 1.0, -27.5);
	glEnd();

	//pagar k.l.ka
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(16.0, 0.12, 27.5);
	glVertex3f(30.0, 0.12, -13.5);
	glVertex3f(30.0, 1.0, -13.5);
	glVertex3f(16.0, 1.0, 27.5);
	glEnd();

	//kursi penonton

	//kursi b
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-16.0, 0.12, -28.5);
	glVertex3f(31.0, 0.12, -14.5); //6
	glVertex3f(31.0, 28.0, -18.5);
	glVertex3f(-16.0, 28.0, -32.5);
	glEnd();

	//kursi d
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(16.0, 0.12, 28.5);
	glVertex3f(-32.0, 0.12, 14.5);
	glVertex3f(-32.0, 28.0, 18.5);
	glVertex3f(16.0, 28.0, 32.5);
	glEnd();

	//kursi ki
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-16.0, 0.12, -28.5);
	glVertex3f(-32.0, 0.12, 14.5);
	glVertex3f(-32.0, 28.0, 18.5);
	glVertex3f(-16.0, 28.0, -32.5);
	glEnd();

	//kursi ka
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(16.0, 0.12, 28.5);
	glVertex3f(31.0, 0.12, -14.5);
	glVertex3f(31.0, 28.0, -18.5);
	glVertex3f(16.0, 28.0, 32.5);
	glEnd();

	//kursi garis belakang
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(8.5, 20.0, -25.2);
	glVertex3f(7.0, 20.0, -25.5);
	glVertex3f(7.0, 6.0, -21.0);
	glVertex3f(8.5, 6.0, -20.5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(14.5, 6.0, -18.4);
	glVertex3f(15.0, 6.0, -18.2); //7
	glVertex3f(15.0, 28.0, -23.0);
	glVertex3f(14.5, 28.0, -23.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(21.5, 0.12, -16.4);
	glVertex3f(22.0, 0.12, -16.2); //7
	glVertex3f(22.0, 28.0, -20.8);
	glVertex3f(21.5, 28.0, -21.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(28.5, 0.12, -14.4);
	glVertex3f(29.0, 0.12, -14.2); //7
	glVertex3f(29.0, 28.0, -18.6);
	glVertex3f(28.5, 28.0, -18.9);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.5, 6.0, -22.4);
	glVertex3f(1.0, 6.0, -22.2); //7
	glVertex3f(1.0, 28.0, -27.2);
	glVertex3f(0.5, 28.0, -27.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.0, 0.12, -24.8);
	glVertex3f(-5.5, 0.12, -24.6); //7
	glVertex3f(-5.5, 28.0, -29.0);
	glVertex3f(-6.0, 28.0, -29.3);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.0, 0.12, -26.8);
	glVertex3f(-12.5, 0.12, -26.6); //7
	glVertex3f(-12.5, 28.0, -31.0);
	glVertex3f(-13.0, 28.0, -31.3);
	glEnd();

	//tempat masuk
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0, 0.1, -23.0);
	glVertex3f(-1.0, 6.0, -23.0);
	glVertex3f(17.0, 6.0, -17.5);
	glVertex3f(17.0, 0.1, -17);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(9.5, 0.1, -20.2);
	glVertex3f(6.0, 0.1, -21.0);
	glVertex3f(6.0, 6.0, -21.0);
	glVertex3f(9.5, 6.0, -20.0);
	glEnd();


	//kursi garis kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-23.40, 0.12, -8.5);
	glVertex3f(-23.75, 0.12, -7.5);
	glVertex3f(-23.3, 28.0, -7.65);
	glVertex3f(-22.95, 28.0, -8.8);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.75, 0.12, -15.5);
	glVertex3f(-21.2, 0.12, -14.5);
	glVertex3f(-21.25, 28.0, -14.65);
	glVertex3f(-20.91, 28.0, -15.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-17.09, 0.12, -25.5);
	glVertex3f(-17.48, 0.12, -24.5); //10
	glVertex3f(-18.25, 28.0, -24.65);
	glVertex3f(-17.91, 28.0, -25.8);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-26.20, 0.12, -1.05);
	glVertex3f(-26.6, 0.12, 0.05);
	glVertex3f(-26.2, 28.0, 0.2);
	glVertex3f(-25.7, 28.0, -1.35);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-29.8, 0.12, 8.5);
	glVertex3f(-30.05, 0.12, 9.5);
	glVertex3f(-29.2, 28.0, 9.65);
	glVertex3f(-28.95, 28.0, 8.8);
	glEnd();

	//kursi garis kanan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(22.95, 0.12, 8.5);
	glVertex3f(23.3, 0.12, 7.5);
	glVertex3f(23.3, 28.0, 7.65);
	glVertex3f(22.95, 28.0, 8.8);
	glEnd();
	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(25.25, 0.12, 1.5);
	glVertex3f(25.6, 0.12, 0.5);
	glVertex3f(25.35, 28.0, 0.65);
	glVertex3f(25.0, 28.0, 1.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(28.75, 0.12, -8.5);
	glVertex3f(29.1, 0.12, -9.5);
	glVertex3f(28.4, 28.0, -9.65);
	glVertex3f(28.15, 28.0, -8.8);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.48, 0.12, 15.5);
	glVertex3f(20.89, 0.12, 14.5);
	glVertex3f(21.25, 28.0, 14.65);
	glVertex3f(20.91, 28.0, 15.8);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(17.04, 0.12, 25.5);
	glVertex3f(17.35, 0.12, 24.5);
	glVertex3f(18.25, 28.0, 24.65);
	glVertex3f(17.91, 28.0, 25.8);
	glEnd();

	//kursi garis depan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.0, 0.12, 22.0);
	glVertex3f(-7.0, 0.12, 21.7);
	glVertex3f(-7.0, 28.0, 25.7);
	glVertex3f(-6.0, 28.0, 26.0);
	glEnd();
	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0, 0.12, 24.0);
	glVertex3f(0.0, 0.12, 23.7);
	glVertex3f(0.0, 28.0, 27.7);
	glVertex3f(1.0, 28.0, 28.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(8.0, 0.12, 26.0);
	glVertex3f(7.0, 0.12, 25.7);
	glVertex3f(7.0, 28.0, 29.7);
	glVertex3f(8.0, 28.0, 30.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(15.0, 0.12, 28.0);
	glVertex3f(14.0, 0.12, 27.7);
	glVertex3f(14.0, 28.0, 31.7);
	glVertex3f(15.0, 28.0, 32.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-13.0, 0.12, 20.0);
	glVertex3f(-14.0, 0.12, 19.7);
	glVertex3f(-14.0, 28.0, 23.7);
	glVertex3f(-13.0, 28.0, 24.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.0, 0.12, 18.0);
	glVertex3f(-21.0, 0.12, 17.7);
	glVertex3f(-21.0, 28.0, 21.7);
	glVertex3f(-20.0, 28.0, 22.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-27.0, 0.12, 15.9);
	glVertex3f(-28.0, 0.12, 15.55);
	glVertex3f(-28.0, 28.0, 19.6);
	glVertex3f(-27.0, 28.0, 19.9);
	glEnd();
	//lingkaran lapangan 

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	int radiuss = -6, x_tengaah = 1, y_tengaah = 0;
	for (i = 0; i <= 360; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaah + radiuss * cos(sudut);
		float y = y_tengaah + radiuss * sin(sudut);
		glVertex3f(x, 0.1, y);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	int radiusss = -4, x_tengaaah = -15, y_tengaaah = -5;
	for (i = 6; i <= jumlah_titik - 4; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaaah + radiusss * cos(sudut);
		float y = y_tengaaah + radiusss * sin(sudut);
		glVertex3f(x, 0.1, y);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	int x_tengaaahh = 15, y_tengaaahh = 5;
	for (i = 16; i <= jumlah_titik + 6; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaaahh + radiusss * cos(sudut);
		float y = y_tengaaahh + radiusss * sin(sudut);
		glVertex3f(x, 0.1, y);
	}
	glEnd();
	//hiasan kursi (putih)
	//belakang
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 0.5, -28.5);
	glVertex3f(-1.0, 0.5, -24.0); //1
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(17.8, 0.5, -18.2);
	glVertex3f(30.0, 0.5, -14.5); //1
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 2.0, -28.7);
	glVertex3f(-1.0, 2.0, -24.2); //2
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(17.8, 2.0, -18.4);
	glVertex3f(30.0, 2.0, -14.7); //2
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 3.5, -28.9);
	glVertex3f(-1.0, 3.5, -24.2); //3
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(17.8, 3.5, -18.6);
	glVertex3f(31.0, 3.5, -14.9); //3
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 5.0, -29.1);
	glVertex3f(31.0, 5.0, -15.1); //4
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 6.5, -29.3);
	glVertex3f(31.0, 6.5, -15.3); //5
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 8.0, -29.5);
	glVertex3f(31.0, 8.0, -15.5); //6
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 9.5, -29.7);
	glVertex3f(31.0, 9.5, -15.7); //7
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 11.0, -29.9);
	glVertex3f(31.0, 11.0, -15.9); //8
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 12.5, -30.1);
	glVertex3f(31.0, 12.5, -16.1); //9
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 14.0, -30.);
	glVertex3f(31.0, 14.0, -16.25); //10
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 15.5, -30.4);
	glVertex3f(31.0, 15.5, -16.4); //11
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 16.0, -30.65);
	glVertex3f(31.0, 16.0, -16.65); //12
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 17.5, -30.8);
	glVertex3f(31.0, 17.5, -16.8); //13
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 18.0, -31.05);
	glVertex3f(31.0, 18.0, -17.05); //14
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 19.5, -31.25);
	glVertex3f(31.0, 19.5, -17.25); //15
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 21.0, -31.4);
	glVertex3f(31.0, 21.0, -17.4); //16
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 22.5, -31.55);
	glVertex3f(31.0, 22.5, -17.55); //17
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 24.0, -31.7);
	glVertex3f(31.0, 24.0, -17.7); //18
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 25.5, -31.85);
	glVertex3f(31.0, 25.5, -17.85); //19
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 27.0, -32.0);
	glVertex3f(31.0, 27.0, -18.0); //20 //3
	glEnd();

	// depan
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 0.5, 28.5); //1
	glVertex3f(-32.0, 0.5, 14.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 2.0, 28.7); //2
	glVertex3f(-32.0, 2.0, 14.7);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 3.5, 28.9);//3
	glVertex3f(-32.0, 3.5, 14.9);
	glEnd();
	//
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 5.0, 29.1);
	glVertex3f(-32.0, 5.0, 15.1); //4
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 6.5, 29.3);
	glVertex3f(-32.0, 6.5, 15.3); //5
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 8.0, 29.5);
	glVertex3f(-32.0, 8.0, 15.5); //6
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 9.5, 29.7);
	glVertex3f(-32.0, 9.5, 15.7); //7
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 11.0, 29.9);
	glVertex3f(-32.0, 11.0, 15.9); //8
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 12.5, 30.1);
	glVertex3f(-32.0, 12.5, 16.1); //9
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 14.0, 30.);
	glVertex3f(-32.0, 14.0, 16.25); //10
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 15.5, 30.4);
	glVertex3f(-32.0, 15.5, 16.4); //11
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 16.0, 30.65);
	glVertex3f(-32.0, 16.0, 16.65); //12
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 17.5, 30.8);
	glVertex3f(-32.0, 17.5, 16.8); //13
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 18.0, 31.05);
	glVertex3f(-32.0, 18.0, 17.05); //14
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 19.5, 31.25);
	glVertex3f(-32.0, 19.5, 17.25); //15
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 21.0, 31.4);
	glVertex3f(-32.0, 21.0, 17.4); //16
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 22.5, 31.55);
	glVertex3f(-32.0, 22.5, 17.55); //17
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 24.0, 31.7);
	glVertex3f(-32.0, 24.0, 17.7); //18
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 25.5, 31.85);
	glVertex3f(-32.0, 25.5, 17.85); //19
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 27.0, 32.0);
	glVertex3f(-32.0, 27.0, 18.0); //20 //3
	glEnd();

	//kiri
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 0.5, -28.5);//1
	glVertex3f(-32.0, 0.5, 14.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 2.0, -28.7);//2
	glVertex3f(-32.0, 2.0, 14.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 3.5, -28.9);//3
	glVertex3f(-32.0, 3.5, 14.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 5.0, -29.1);//4
	glVertex3f(-32.0, 5.0, 15.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 6.5, -29.3);//5
	glVertex3f(-32.0, 6.5, 15.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 8.0, -29.5);//6
	glVertex3f(-32.0, 8.0, 15.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 9.5, -29.7);//7
	glVertex3f(-32.0, 9.5, 15.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 11.0, -29.9);//8
	glVertex3f(-32.0, 11.0, 15.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 12.5, -30.1);//9
	glVertex3f(-32.0, 12.5, 16.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 14.0, -30.3);//10
	glVertex3f(-32.0, 14.0, 16.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 15.5, -30.5);//11
	glVertex3f(-32.0, 15.5, 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 16.0, -30.7);//12
	glVertex3f(-32.0, 16.0, 16.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 17.5, -30.9);//13
	glVertex3f(-32.0, 17.5, 16.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 18.0, -31.1);//14
	glVertex3f(-32.0, 18.0, 17.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 19.5, -31.3);//15
	glVertex3f(-32.0, 19.5, 17.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 21.0, -31.5);//16
	glVertex3f(-32.0, 21.0, 17.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 22.5, -31.7);//17
	glVertex3f(-32.0, 22.5, 17.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 24.0, -31.9);//18
	glVertex3f(-32.0, 24.0, 17.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 25.5, -32.1);//19
	glVertex3f(-32.0, 25.5, 18.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-16.0, 27.0, -32.3);//20
	glVertex3f(-32.0, 27.0, 18.3);
	glEnd();

	//kanan
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 0.5, 28.5);//1 //3
	glVertex3f(30.8, 0.5, -14.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 2.0, 28.7);//2
	glVertex3f(30.85, 2.0, -14.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 3.5, 28.9);//3
	glVertex3f(30.9, 3.5, -14.9);
	glEnd();
	//
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 5.0, 29.1);//4
	glVertex3f(30.95, 5.0, -15.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 6.5, 29.3);//5
	glVertex3f(30.96, 6.5, -15.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 8.0, 29.5);//6
	glVertex3f(30.78, 8.0, -15.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 9.5, 29.7);//7
	glVertex3f(30.81, 9.5, -15.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 11.0, 29.9);//8
	glVertex3f(30.84, 11.0, -15.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 12.5, 30.1);//9
	glVertex3f(30.88, 12.5, -16.1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 14.0, 30.3);//10
	glVertex3f(30.9, 14.0, -16.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 15.5, 30.5);//11
	glVertex3f(30.65, 15.5, -16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 16.0, 30.7);//12
	glVertex3f(30.7, 16.0, -16.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 17.5, 30.9);//13
	glVertex3f(30.75, 17.5, -16.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 18.0, 31.1);//14
	glVertex3f(30.8, 18.0, -17.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 19.5, 31.3);//15
	glVertex3f(30.85, 19.5, -17.3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 21.0, 31.5);//16
	glVertex3f(30.85, 21.0, -17.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 22.5, 31.7);//17
	glVertex3f(30.9, 22.5, -17.7);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 24.0, 31.9);//18
	glVertex3f(30.95, 24.0, -17.9);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 25.5, 32.1);//19
	glVertex3f(30.9, 25.5, -18.1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(16.0, 27.0, 32.3);//20
	glVertex3f(30.95, 27.0, -18.3);
	glEnd();


	//garis tengah 
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-6.0, 0.12, 20.0);
	glVertex3f(8.0, 0.12, -20.0);
	glEnd();
	glBegin(GL_LINE_STRIP); // kiri
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-19.5, 0.12, -15.0);
	glVertex3f(-12.0, 0.12, -12.5);
	glVertex3f(-17.0, 0.12, 2.5);
	glVertex3f(-25.0, 0.12, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); // kiri dalam
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.5, 0.12, -11.3);
	glVertex3f(-17.3, 0.12, -10.2);
	glVertex3f(-20.0, 0.12, -2.8);
	glVertex3f(-23.5, 0.12, -4.0);
	glEnd();

	glBegin(GL_LINE_STRIP); // kanan
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(19.5, 0.12, 15.0);
	glVertex3f(12.0, 0.12, 12.5);
	glVertex3f(17.0, 0.12, -2.5);
	glVertex3f(25.0, 0.12, -0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); // kanan dalam
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.5, 0.12, 11.3);
	glVertex3f(17.3, 0.12, 10.2);
	glVertex3f(20.0, 0.12, 2.8);
	glVertex3f(23.5, 0.12, 4.0);
	glEnd();

	//tiang bendera sudut kiri
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-29.8, 0.12, 13.8);
	glVertex3f(-29.8, 3.12, 13.5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-29.8, 3.12, 13.5);
	glVertex3f(-28.8, 3.12, 13.0); //bendera
	glVertex3f(-28.8, 2.12, 13.0);
	glVertex3f(-29.8, 2.12, 13.6);
	glEnd();
	//tiang bendera sudut kanan
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(29.8, 0.12, -13.8);
	glVertex3f(29.8, 3.12, -13.5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(29.8, 3.12, -13.5);
	glVertex3f(28.8, 3.12, -13.0); //bendera
	glVertex3f(28.8, 2.12, -13.0);
	glVertex3f(29.8, 2.12, -13.6);
	glEnd();
	//jalan
	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-35.8, -0.5, 0.0);
	glVertex3f(-70.8, -0.5,0.0);
	glVertex3f(-70.8, -0.5,50.0);
	glVertex3f(-25.8, -0.5,65.0);
	glVertex3f(0.0, -0.5,10.0);
	glEnd();
	//piala
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 5.0,40.0);
	glVertex3f(-55.0, 5.0,45.0);
	glVertex3f(-60.0, 5.0,45.0);
	glVertex3f(-60.0, 5.0,40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 0.0,40.0);
	glVertex3f(-55.0, 0.0,45.0);
	glVertex3f(-60.0, 0.0,45.0);
	glVertex3f(-60.0, 0.0,40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 5.0,45.0);
	glVertex3f(-55.0, 0.0,45.0);
	glVertex3f(-60.0, 0.0,45.0);
	glVertex3f(-60.0, 5.0,45.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 5.0,40.0);
	glVertex3f(-55.0, 0.0,40.0);
	glVertex3f(-60.0, 0.0,40.0);
	glVertex3f(-60.0, 5.0,40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 0.0,40.0);
	glVertex3f(-55.0, 5.0,40.0);
	glVertex3f(-60.0, 5.0,45.0);
	glVertex3f(-60.0, 0.0,45.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-55.0, 5.0,45.0);
	glVertex3f(-55.0, 0.0,45.0);
	glVertex3f(-60.0, 0.0,40.0);
	glVertex3f(-60.0, 5.0,40.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-58.0, 5.0,42.0);
	glVertex3f(-57.0, 8.0,42.0);
	glVertex3f(-58.0, 8.0,42.0);
	glVertex3f(-57.0, 5.0,42.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-58.0, 5.0,43.0);
	glVertex3f(-57.0, 8.0,43.0);
	glVertex3f(-58.0, 8.0,43.0);
	glVertex3f(-57.0, 5.0,43.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-58.0, 5.0,43.0);
	glVertex3f(-58.0, 8.0,43.0);
	glVertex3f(-58.0, 8.0,42.0);
	glVertex3f(-58.0, 5.0,42.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-57.0, 5.0,43.0);
	glVertex3f(-57.0, 8.0,43.0);
	glVertex3f(-57.0, 8.0,42.0);
	glVertex3f(-57.0, 5.0,42.0);
	glEnd();
		//tv atas
	glBegin(GL_QUADS); // kiri 
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-20.5, 25.12, -11.3);
	glVertex3f(-23.0, 25.12, -3.8);
	glVertex3f(-23.5, 30.12, -4.0);
		glVertex3f(-20.8, 30.12, -11.2);
	glEnd();
	
	glBegin(GL_QUADS); // kanan 
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(20.5, 25.12, 11.3);
	glVertex3f(23.0, 25.12, 3.8);
	glVertex3f(23.5, 30.12, 4.0);
		glVertex3f(20.8, 30.12, 11.2);
	glEnd();
	//gawang
	glBegin(GL_LINE_STRIP); // kiri gawang
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-20.5, 0.12, -11.3);
	glVertex3f(-20.3, 5.12, -11.2);
	glVertex3f(-23.0, 5.12, -3.8);
	glVertex3f(-23.5, 0.12, -4.0);
	glEnd();
	glBegin(GL_LINE_STRIP); // kanan gawang
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(20.5, 0.12, 11.3);
	glVertex3f(20.3, 5.12, 11.2);
	glVertex3f(23.0, 5.12, 3.8);
	glVertex3f(23.5, 0.12, 4.0);
	glEnd();
	
	//pembatas kursi
	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-17.0, 14.5, -26.5);
	glVertex3f(29.0, 14.5, -12.5); //6
	glVertex3f(30.5, 14.5, -15.5);
	glVertex3f(-16.0, 14.5, -29.5);
	glEnd();
	
		glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-17.0, 15.5, -26.5);
	glVertex3f(29.0, 15.5, -12.5); //6
	glVertex3f(30.5, 15.5, -15.5);
	glVertex3f(-16.0, 15.5, -29.5);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-17.0, 15.5, -26.5);
	glVertex3f(29.0, 15.5, -15.5); //6
	glVertex3f(30.5, 14.5, -15.5);
	glVertex3f(-16.0, 14.5, -26.5);
	glEnd();
	
	//depan
		glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(17.0, 14.5, 26.5);
	glVertex3f(-29.0, 14.5, 12.5); //6
	glVertex3f(-30.5, 14.5, 15.5);
	glVertex3f(16.0, 14.5, 29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(17.0, 15.5, 26.5);
	glVertex3f(-29.0, 15.5, 12.5); //6
	glVertex3f(-30.5, 15.5, 15.5);
	glVertex3f(16.0, 15.5, 29.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(17.0, 15.5, 26.5);
	glVertex3f(-29.0, 15.5, 15.5); //6
	glVertex3f(-30.5, 14.5, 15.5);
	glVertex3f(16.0, 14.5, 26.5);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(-31.0, 14.5, 15.4);
	glVertex3f(-29.0, 14.5, 16.0);
	glVertex3f(-14.0, 14.5, -28.5);
	glVertex3f(-16.0, 14.5, -29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-31.0, 15.5, 15.4);
	glVertex3f(-29.0, 15.5, 16.0);
	glVertex3f(-14.0, 15.5, -28.5);
	glVertex3f(-16.0, 15.5, -29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-29.0, 15.5, 15.4);
	glVertex3f(-29.0, 14.5, 16.0);
	glVertex3f(-14.0, 14.5, -28.5);
	glVertex3f(-14.0, 15.5, -29.5);
	glEnd();
	
	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(30.0, 14.5, -15.4);
	glVertex3f(28.0, 14.5, -16.0);
	glVertex3f(14.0, 14.5, 28.5);
	glVertex3f(16.0, 14.5, 29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(30.0, 15.5, -15.4);
	glVertex3f(28.0, 15.5, -16.0);
	glVertex3f(14.0, 15.5, 28.5);
	glVertex3f(16.0, 15.5, 29.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(28.0, 15.5, -15.4);
	glVertex3f(28.0, 14.5, -16.0);
	glVertex3f(14.0, 14.5, 28.5);
	glVertex3f(14.0, 15.5, 29.5);
	glEnd();

	
	glPopMatrix();
}

void tv(){
	//tv
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-53.0, 15.0,25.0);
	glVertex3f(-42.0, 15.0,40.0);
	glVertex3f(-42.0, 25.0,40.0);
	glVertex3f(-53.0, 25.0,25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-53.0, 15.0,25.0);
	glVertex3f(-42.0, 15.0,40.0);
	glVertex3f(-42.0, 25.0,40.0);
	glVertex3f(-53.0, 25.0,25.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 5.0,30.0);
	glVertex3f(-45.0, 5.0,35.0);
	glVertex3f(-50.0, 5.0,35.0);
	glVertex3f(-50.0, 5.0,30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 0.0,30.0);
	glVertex3f(-45.0, 0.0,35.0);
	glVertex3f(-50.0, 0.0,35.0);
	glVertex3f(-50.0, 0.0,30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 5.0,35.0);
	glVertex3f(-45.0, 0.0,35.0);
	glVertex3f(-50.0, 0.0,35.0);
	glVertex3f(-50.0, 5.0,35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 5.0,30.0);
	glVertex3f(-45.0, 0.0,30.0);
	glVertex3f(-50.0, 0.0,30.0);
	glVertex3f(-50.0, 5.0,30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 0.0,30.0);
	glVertex3f(-45.0, 5.0,30.0);
	glVertex3f(-50.0, 5.0,35.0);
	glVertex3f(-50.0, 0.0,35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);
	glVertex3f(-45.0, 5.0,35.0);
	glVertex3f(-45.0, 0.0,35.0);
	glVertex3f(-50.0, 0.0,30.0);
	glVertex3f(-50.0, 5.0,30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-48.0, 5.0,32.0);
	glVertex3f(-47.0, 15.0,32.0);
	glVertex3f(-48.0, 15.0,32.0);
	glVertex3f(-47.0, 5.0,32.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-48.0, 5.0,33.0);
	glVertex3f(-47.0, 15.0,33.0);
	glVertex3f(-48.0, 15.0,33.0);
	glVertex3f(-47.0, 5.0,33.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-48.0, 5.0,33.0);
	glVertex3f(-48.0, 15.0,33.0);
	glVertex3f(-48.0, 15.0,32.0);
	glVertex3f(-48.0, 5.0,32.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-47.0, 5.0,33.0);
	glVertex3f(-47.0, 15.0,33.0);
	glVertex3f(-47.0, 15.0,32.0);
	glVertex3f(-47.0, 5.0,32.0);
	glEnd();
}
void Display()
{
	int Vtx,i;
 glLineWidth(4.0);
float StartShape[12][2]={{-9,17.5},{-3,17.5},{-3,18.5},{-7.5,18.5},{-7.5,19.5},{-8,19.5},{-3,20.5},{-3,20.5},{-7.5,21.5},{-7.5,21.5},{-3,23},{-9,23}};
float EndShape[12][2]= {{-9,17},{-8,17},{-7,19},{-6.5,21},{-5.5,21},{-5,19},{-4,17},{-4,17},{-3,17},{-3.5,21},{-5,23},{-7,23}};
float IntermediateShape[12][3];
float VertexColors[12][3]={{1,0,0},{1,1,0},{1,0,1},{0,1,0},{0,1,1},{0,0,1},{1,0.5,0},{1,0,0.5},{0.5,1,0},
{0.5,0,1}, {1,0,0.5},{0,1,0.5}};
 static float Tween=0.0-deltat;
 if(Tween<1){
 	Tween+= deltat;
 }
 
 for (Vtx=0;Vtx<12;Vtx++){
 	IntermediateShape[Vtx][0]=(1.0-Tween)*StartShape[Vtx][0]+Tween*EndShape[Vtx][0];
 	IntermediateShape[Vtx][1]=(1.0-Tween)*StartShape[Vtx][1]+Tween*EndShape[Vtx][1];
 }
 glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
 glColorPointer(3,GL_FLOAT,0,VertexColors);
}

void memutar(void) {
	glLoadIdentity();
	spin = spin + 0.1;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}


void gambar(){
	glRotatef(xRotate,0,1,0);
	glRotatef(yRotate,1,0,0);
	ikigambar();
}
void tampil(void){
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0],eye[1],eye[2], at[0], at[1],at[2], 0,1,0);

	Display();
	gambar();
	bola();
	tv();
	glFlush();
	glutSwapBuffers();
}
void specialkey(int key, int x, int y){
	switch(key){
	case GLUT_KEY_LEFT : 
	eye[0] = eye[0] + UNITS_PER_PIXEL;
	at[0] = at[0] + UNITS_PER_PIXEL; break;
	case GLUT_KEY_RIGHT : 
	eye[0] = eye[0] - UNITS_PER_PIXEL;
	at[0] = at[0] - UNITS_PER_PIXEL; break;
	case GLUT_KEY_UP : 
	eye[1] = eye[1] - UNITS_PER_PIXEL;
	at[1] = at[1] - UNITS_PER_PIXEL; break;
	case GLUT_KEY_DOWN : 
	eye[1] = eye[1] + UNITS_PER_PIXEL;
	at[1] = at[1] + UNITS_PER_PIXEL; break;
	case GLUT_KEY_HOME : 
	eye[0] = (1- ZOOM_FACTOR) * eye[0]+at[0]*ZOOM_FACTOR;
	eye[1] = (1- ZOOM_FACTOR) * eye[1]+at[1]*ZOOM_FACTOR;
	eye[2] = (1- ZOOM_FACTOR) * eye[2]+at[2]*ZOOM_FACTOR;break;
	case GLUT_KEY_END : 
	eye[0] = (1+ ZOOM_FACTOR) * eye[0]-at[0]*ZOOM_FACTOR;
	eye[1] = (1+ ZOOM_FACTOR) * eye[1]-at[1]*ZOOM_FACTOR;
	eye[2] = (1+ ZOOM_FACTOR) * eye[2]-at[2]*ZOOM_FACTOR;break;
}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case '-': 
		case '_':
			specialkey(GLUT_KEY_END,0,0); 
			break;
		case '+': 
		case '=':
			specialkey(GLUT_KEY_HOME,0,0); 
		break;
		case 'a':
		case 'A':
			specialkey(GLUT_KEY_LEFT,0,0); 
		break;
		case 'd':
		case 'D':
			specialkey(GLUT_KEY_RIGHT,0,0); 
		break;
		case 'w':
		case 'W':
			specialkey(GLUT_KEY_UP,0,0); 
		break;
		case 's':
		case 'S':
			specialkey(GLUT_KEY_DOWN,0,0); 
		break;
		case 'm':
		case 'M':
			glutIdleFunc(memutar);
			break;
		case 'n': 
		case 'N':
			glutIdleFunc(NULL);
			break;
		case 27 : exit(0); break;
		case '5':
		if(is_depth){
			is_depth=0;
			glDisable(GL_DEPTH_TEST);
		}
		else{
			is_depth=1;
			glEnable(GL_DEPTH_TEST);
		} 	
	}
}
void mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN)
			mouseState.leftButton = true;
		else 
			mouseState.leftButton = false;
	}
	if (button == GLUT_RIGHT_BUTTON){
		if(state == GLUT_DOWN)
			mouseState.rightButton = true;
		else 
			mouseState.rightButton = false;
	}
	mouseState.x = x;
	mouseState.y = y;
}
void mousemotion(int x,int y){
	int xDelta = mouseState.x - x;
	int yDelta = mouseState.y - y;
	mouseState.x = x;
	mouseState.y = y;
	if(mouseState.leftButton){
		xRotate += xDelta * UNITS_PER_PIXELS;
		yRotate -= yDelta * UNITS_PER_PIXELS;}
	else if(mouseState.rightButton){
		eye[0]+= xDelta * UNITS_PER_PIXELS;
		eye[1] -= yDelta * UNITS_PER_PIXELS;
		at[0]+= xDelta * UNITS_PER_PIXELS;
		at[1]-= yDelta * UNITS_PER_PIXELS;
}
	glutPostRedisplay();
}

void ikiinit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
	glLineWidth(3.0f);
	lighting();
 glEnableClientState (GL_VERTEX_ARRAY);
 glEnableClientState (GL_COLOR_ARRAY);
}
void ikiukuran(int lebar, int tinggi) {
	if (tinggi == 0)tinggi = 1;
	glViewport(0, 0, lebar, tinggi);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 0.1, 500.0);
	glTranslatef(0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(500, timer, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR - Kelompok 3");
	ikiinit();
	glutReshapeFunc(ikiukuran);
	glutDisplayFunc(tampil);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	glutSpecialFunc(specialkey);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(150, timer,0);
	glEnableClientState (GL_VERTEX_ARRAY);
 	glEnableClientState (GL_COLOR_ARRAY);
	glutMainLoop();
	return 0;
}

