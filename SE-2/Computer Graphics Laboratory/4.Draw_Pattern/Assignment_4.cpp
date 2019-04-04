#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;

void Display();
void Initiate();
void dda(int x1, int y1, int x2, int y2);

int x1,x2,y1,y2;

int main(int a, char **c)
{
	cout << "Enter (X1,Y1) : ";
	cin >> x1 >> y1;
	cout << "Enter (X2,Y2) : ";
	cin >> x2 >> y2;

	glutInit(&a, c);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("Assignment--1");
	Initiate();
	glutDisplayFunc(Display);	
	glutMainLoop();
}

void Initiate()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);

	dda(x1, y1, x2, y1);
	dda(x1, y1, x1, y2);
	dda(x2, y2, x1, y2);
	dda(x2, y2, x2, y1);

	dda((x1+x2)/2,y1,x2,(y1+y2)/2);	
	dda((x1+x2)/2,y1,x1,(y1+y2)/2);
	dda((x1+x2)/2,y2,x1,(y1+y2)/2);
	dda((x1+x2)/2,y2,x2,(y1+y2)/2);

	dda((x1+(x1+x2)/2)/2,(y1+(y1+y2)/2)/2,(x2+(x1+x2)/2)/2,(y1+(y1+y2)/2)/2);
	dda((x1+(x1+x2)/2)/2,(y1+(y1+y2)/2)/2,(x1+(x1+x2)/2)/2,(y2+(y1+y2)/2)/2);
	dda((x2+(x1+x2)/2)/2,(y2+(y1+y2)/2)/2,(x1+(x1+x2)/2)/2,(y2+(y1+y2)/2)/2);
	dda((x2+(x1+x2)/2)/2,(y2+(y1+y2)/2)/2,(x2+(x1+x2)/2)/2,(y1+(y1+y2)/2)/2);

	glFlush();
}

void dda(int x1, int y1, int x2, int y2)
{
	float xinc, yinc;
	float steps;
	float dx, dy;

	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>=dy)
		steps = dx;
	else
		steps = dy;

	xinc = (x2-x1)/(float)steps;
	yinc = (y2-y1)/(float)steps;
	
	float x=x1;
	float y=y1;
	
	for(int i=0; i<steps; i++)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();

		x=x+xinc;
		y=y+yinc;

	}
}
