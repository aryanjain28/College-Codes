#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<time.h>
#include<sys/timeb.h>
using namespace std;


int window;
float rtri=0.0f;


void InitGL(int width,int height)
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode (GL_MODELVIEW);
}

float ballX=-0.5f;
float ballY=0.0f;
float ballZ=0.0f;

void Drawball(void)
{
	glColor3f(0.0,1.0,0.0);
	glTranslatef(ballX,ballY,ballZ);
	glRotatef(ballX,ballX,ballY,ballZ);
	glutWireSphere(0.3,20,20);
	glTranslatef(ballX+1.5,ballY,ballZ);
	glutWireSphere(0.3,20,20);

}

void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(rtri,0.0f,-6.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(0.4f,1.0f,0.0f);
	glVertex3f(1.0f,0.4f,0.0f);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(1.0f,0.0f,0.0f);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.0f,0.0f,0.0f);
	glEnd();

	Drawball();
	rtri+=0.005f;
	if(rtri>2)
	rtri=-2.0f;
	glutSwapBuffers();
}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA| GLUT_DEPTH);
	glutInitWindowSize(650,650);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Moving CAR");
	glutDisplayFunc(DrawGLScene);
	glutIdleFunc(DrawGLScene);
	InitGL(650,650);
	glutMainLoop();
	return 0;
}
