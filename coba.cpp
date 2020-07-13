#include <math.h>
#include <iostream>
#include <windows.h>
#include <gl/glut.h>

int is_depth;
const double Pi = 3.141592653589793;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
static GLfloat spin = 0.0;
bool mouseDown = false;
void ikiinit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth =1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
	glLineWidth(3.0f);
}
void ikigambar(void){
	if(is_depth)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else 
	glClear(GL_COLOR_BUFFER_BIT);
glRotatef(xrot,1.0f,0.0f,0.0f);
glRotatef(yrot,0.0f,1.0f,0.0f);
glRotatef(spin,0.0f,1.0f,0.0f);

glPushMatrix();
glColor3f(0.7,0.7,0.7);
GLfloat x = 0.0;GLfloat y = 50.0;GLfloat angle_stepsize = 1.0;GLfloat height = 30.0;GLfloat radius = -40.0;GLfloat jumlah_titik=20;
    glBegin(GL_QUAD_STRIP);
    int k;
        for(k=0;k<=360;k++) {
    float sudut=k*(2*Pi/jumlah_titik);
            x = radius * cos(sudut);
            y = (radius+4) * sin(sudut);
            glVertex3f(x,height, y);
            glVertex3f(x, 0.0,y);
            sudut = sudut + angle_stepsize;
        }
        glVertex3f(radius, height,0.0);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);
	int i,x_tengah=0,y_tengah=50;
	for (i=0;i<=360;i++){
        float sudut=i*(2*Pi/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+(radius+4)*sin(sudut);
		glVertex3f(x,0.0,y-50);
	}
glEnd();
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
	int j;
	for (j=3.5;j<=jumlah_titik-10.5;j++){
        float sudut=j*(2*Pi/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+(radius+4)*sin(sudut);
		glVertex3f(x,30.0,y-50);
	}
glEnd();
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
	int f;
	for (f=13.5;f<=jumlah_titik-0.5;f++){
        float sudut=f*(2*Pi/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+(radius+4)*sin(sudut);
		glVertex3f(x,30.0,y-50);
	}
glEnd();
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
	int g;
	for (g=8.5;g<=jumlah_titik-5.5;g++){
        float sudut=g*(2*Pi/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+(radius+4)*sin(sudut);
		glVertex3f(x,30.0,y-50);
	}
glEnd();
glColor3f(0.8,0.8,0.8);
glBegin(GL_POLYGON);
	int h;
	for (h=-2.5;h<=jumlah_titik-15.5;h++){
        float sudut=h*(2*Pi/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+(radius+4)*sin(sudut);
		glVertex3f(x,30.0,y-50);
	}
glEnd();
float pxx,pzz,pii,pyy,Mgh,Cgh,ax=-13,ay=30,az=-33.5,bx=-32.5,by=30,bz=21,cx=32,cy=30,cz=-21,dx=13,dy=30,dz=33,ex=-23,ey=30,ez=-29,fx=38,fy=30,fz=-11,gx=-38,gy=30,gz=11,hx=23,hy=30,hz=29,Mab,Mcd,Cab,Mef,Cef,Ccd,px,py,pz,pi;
	glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex3f(ax,ay,az);
	glVertex3f(bx,by,bz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex3f(cx,cy,cz);
	glVertex3f(dx,dy,dz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex3f(ex,ey,ez);
	glVertex3f(fx,fy,fz);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.9f,0.9f,0.9f);
	glVertex3f(gx,gy,gz);
	glVertex3f(hx,hy,hz);
	glEnd();
	//rumus perpotongan
	Mab=(bz-az)/(bx-ax);
	Mcd=(dz-cz)/(dx-cx);
	Mef=(fz-ez)/(fx-ex);
	Mgh=(hz-gz)/(hx-gx);
	Cab=az-(ax*Mab);
	Ccd=cz-(cx*Mcd);
	Cef=ez-(ex*Mef);
	Cgh=gz-(gx*Mgh);
	
	//titik potong
	px=(Cab-Cgh)/(Mgh-Mab);
	py=(Mab*px)+Cab;
	pz=(Cef-Cab)/(Mab-Mef);
	pi=(Mef*pz)+Cef;
	pxx=(Cgh-Ccd)/(Mcd-Mgh);
	pyy=(Mcd*pxx)+Ccd;
	pzz=(Cef-Ccd)/(Mcd-Mef);
	pii=(Mcd*pzz)+Ccd;
	
	//Hasil
	glColor3f(0.9f,0.9f,0.9f);
	glBegin(GL_POINTS);
	glVertex3f(px,30.0,py);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pz,30.0,pi);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pxx,30.0,pyy);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(pzz,30.0,pii);
	glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-13.0,30.0,-33.5);
glVertex3f(-17.75,35.0,-19.875);
glVertex3f(-22.75,36.0,-6.25);
glVertex3f(-27.5,35.0,7.375);
glVertex3f(-32.5,30.0,21.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-15.75,30.0,-24.875);
glVertex3f(-17.75,35.0,-19.875);
glVertex3f(-19.75,30.0,-14.875);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-19.75,30.0,-14.875);
glVertex3f(-22.75,36.0,-6.25);
glVertex3f(-25.75,30.0,2.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-25.75,30.0,2.5);
glVertex3f(-27.5,35.0,7.375);
glVertex3f(-29.75,30.0,12.5);
glEnd();
glColor3f(0.9f,0.9f,0.9f);
glBegin(GL_LINE_STRIP);
glVertex3f(32.0,30.0,-21.0);
glVertex3f(27.25,35.0,-7.5);
glVertex3f(22.5,36.0,6.0);
glVertex3f(17.75,35.0,19.5);
glVertex3f(13.0,30.0,33.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(19.75,30.0,14.875);
glVertex3f(22.75,36.0,6.25);
glVertex3f(25.75,30.0,-2.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(25.75,30.0,-2.5);
glVertex3f(27.5,35.0,-7.375);
glVertex3f(29.75,30.0,-12.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(15.75,30.0,24.875);
glVertex3f(17.75,35.0,19.875);
glVertex3f(19.75,30.0,14.875);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-23.0,30.0,-29.0);
glVertex3f(-7.75,35.0,-24.5);
glVertex3f(7.5,36.0,-20.0);
glVertex3f(22.75,35.0,-15.5);
glVertex3f(38.0,30.0,-11.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-12.75,30.0,-26.0);
glVertex3f(-7.75,35.0,-24.5);
glVertex3f(-2.75,30.0,-22.75);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-2.75,30.0,-22.75);
glVertex3f(3.75,35.75,-21.0);
glVertex3f(8.75,30.0,-19.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(8.75,30.0,-19.5);
glVertex3f(13.75,35.75,-17.75);
glVertex3f(18.75,30.0,-16.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(18.75,30.0,-16.0);
glVertex3f(23.75,35.0,-14.5);
glVertex3f(28.75,30.0,-13.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-38.0,30.0,11.0);
glVertex3f(-22.75,35.0,15.5);
glVertex3f(-7.5,36.0,20.0);
glVertex3f(7.75,35.0,24.5);
glVertex3f(23.0,30.0,29.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-18.75,30.0,16.0);
glVertex3f(-23.75,35.0,14.5);
glVertex3f(-28.75,30.0,13.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-8.75,30.0,19.5);
glVertex3f(-13.75,35.75,17.75);
glVertex3f(-18.75,30.0,16.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(12.75,30.0,26.0);
glVertex3f(7.75,35.0,24.5);
glVertex3f(2.75,30.0,22.75);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(2.75,30.0,22.75);
glVertex3f(-3.75,35.75,21.0);
glVertex3f(-8.75,30.0,19.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-3.75,35.75,21.0);
glVertex3f(-8.0,30.0,35.0);
glVertex3f(-3.75,30,21.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(7.75,35.0,24.5);
glVertex3f(4.75,30.0,35.5);
glVertex3f(7.75,30.0,24.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-23.75,35.0,14.5);
glVertex3f(-27.75,30.75,25.5);
glVertex3f(-23.75,30.0,14.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-13.75,35.75,17.75);
glVertex3f(-18.75,30.0,31.75);
glVertex3f(-13.75,30,17.75);
glEnd();
//belakang
glBegin(GL_LINE_STRIP);
glVertex3f(3.75,35.75,-21.0);
glVertex3f(8.0,30.0,-35.0);
glVertex3f(3.75,30,-21.0);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-7.75,35.0,-24.5);
glVertex3f(-4.75,30.0,-35.5);
glVertex3f(-7.75,30.0,-24.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(23.75,35.0,-14.5);
glVertex3f(27.75,30.75,-25.5);
glVertex3f(23.75,30.0,-14.5);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(13.75,35.75,-17.75);
glVertex3f(18.75,30.0,-31.75);
glVertex3f(13.75,30,-17.75);
glEnd();
//kiri
glBegin(GL_LINE_STRIP);
glVertex3f(-17.75,35.0,-19.875);
glVertex3f(-29.75,30.0,-22.875);
glVertex3f(-17.75,30.0,-19.875);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-22.75,36.0,-6.25);
glVertex3f(-37.75,30.0,-10.75);
glVertex3f(-22.75,30.0,-6.25);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-27.5,35.0,7.375);
glVertex3f(-39.5,30.0,4.375);
glVertex3f(-27.5,30.0,7.375);
glEnd();
//kanan
glBegin(GL_LINE_STRIP);
glVertex3f(17.75,35.0,19.875);
glVertex3f(29.75,30.0,22.875);
glVertex3f(17.75,30.0,19.875);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(22.75,36.0,6.25);
glVertex3f(37.75,30.0,10.75);
glVertex3f(22.75,30.0,6.25);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(27.5,35.0,-7.375);
glVertex3f(39.5,30.0,-4.375);
glVertex3f(27.5,30.0,-7.375);
glEnd();
glPopMatrix();
glutSwapBuffers();
}
void ikikeyboard(unsigned char key, int x,int y){
	switch(key){
		case 'w':
		case 'W':
			glTranslatef(0.0,0.0,5.0);
			break;
		case 'd':
		case 'D':
			glTranslatef(3.0,0.0,0.0);
			break;
		case 's':
		case 'S':
			glTranslatef(0.0,0.0,-3.0);
			break;
		case 'a':
		case 'A':
			glTranslatef(-3.0,0.0,0.0);
			break;
		case '7':
			glTranslatef(0.0,3.0,0.0);
			break;
		case '9':
			glTranslatef(0.0,-3.0,0.0);
			break;
		case '2':
			glRotatef(2.0,1.0,0.0,0.0);
			break;
		case '8':
			glRotatef(-2.0,1.0,0.0,0.0);
			break;
		case '6':
			glRotatef(2.0,0.0,1.0,0.0);
			break;
		case '3':
			glRotatef(-2.0,0.0,0.0,1.0);
			break;
		case '4':
			glRotatef(-2.0,0.0,1.0,0.0);
			break;
		case '5':
		if(is_depth){
			is_depth=0;
			glDisable(GL_DEPTH_TEST);
		}
		else{
			is_depth=1;
			glEnable(GL_DEPTH_TEST);
		} break;	
		default : break;
		}ikigambar();
}
void memutar(void){
	glLoadIdentity();
	spin = spin + 0.1;
	if(spin > 360.0)
	spin = spin - 360.0;
	glutPostRedisplay();
}
void idle(){
	glLoadIdentity();
	if(!mouseDown){
		xrot +=0.3f;
		yrot +=0.4f;
	}
	glutPostRedisplay();
}
 void mouse(int button, int state, int x, int y){
 	switch(button){
 		case  GLUT_RIGHT_BUTTON : 
		 if (state ==GLUT_DOWN)
	 		glutIdleFunc(memutar); break; 
	 	case GLUT_LEFT_BUTTON: 
		 if (state ==GLUT_DOWN)
 			mouseDown = true;
 			xdiff=x-yrot;
 			ydiff=-y+xrot; break;
		default: break;
	 }
 }
 
 void mouseMotion(int x, int y){
 	
gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glLoadIdentity();
 	if(mouseDown){
		xrot = x-xdiff;
		yrot = y+ydiff;
	}
	glutPostRedisplay();
 }
 void ikiukuran(int lebar,int tinggi){
 	if(tinggi==0)tinggi=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
	glTranslatef(0.0,-5.0,-150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("Graciela Fausten Novindri - 672018057");
	ikiinit();
	glutDisplayFunc(ikigambar);
	glutKeyboardFunc(ikikeyboard);
	glutReshapeFunc(ikiukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;	
}





