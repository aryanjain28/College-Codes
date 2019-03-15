/*Draw the following pattern using any Line drawing algorithms.*/

#include<iostream>
#include<time.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

using namespace std;

void dis();
void dda(int x1,int y1, int x2, int y2);
void init();

int x1,x2,y1,y2;
int w;

int main(int a, char **c)
{
	cout << "Enter co-ordinates below : \n\n";
	cout << "Enter X1 & Y1 : ";
	cin >> x1 >> y1;
	
	cout << "Enter X2 & Y2 : ";
	cin >> x2 >> y2;

	cout << "Enter width of line (in pixel) : ";
	cin >> w;
	
	glutInit(&a, c);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(500, 500);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("CG :: Assignment_4.");
	init();
	glutDisplayFunc(dis);
	glutMainLoop();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);

	glMatrixMode(GL_MODELVIEW);
}

void dis()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	
	dda(x1,y1,x2,y1);
	dda(x1,y1,x1,y2);
	dda(x1,y2,x2,y2);
	dda(x2,y1,x2,y2);

	dda((x1+x2)/2,y1,x2,(y1+y2)/2);
	dda((x1+x2)/2,y1,x1,(y1+y2)/2);
	dda(x1,(y1+y2)/2,(x1+x2)/2,y2);
	dda(x2,(y1+y2)/2,(x1+x2)/2,y2);

	dda((((x1+x2)/2)+x1)/2,(((y1+y2)/2)+y1)/2,(((x1+x2)/2)+x2)/2, (((y1+y2)/2)+y1)/2);
	dda((((x1+x2)/2)+x1)/2,(((y1+y2)/2)+y1)/2,(((x1+x2)/2)+x1)/2, (((y1+y2)/2)+y2)/2);
	dda((((x1+x2)/2)+x1)/2, (((y1+y2)/2)+y2)/2,(((x1+x2)/2)+x2)/2,(((y1+y2)/2)+y2)/2);
	dda((((x1+x2)/2)+x2)/2, (((y1+y2)/2)+y1)/2,(((x1+x2)/2)+x2)/2,(((y1+y2)/2)+y2)/2);
	
	glFlush();
}
void dda(int x1,int y1, int x2, int y2)
{	
	int steps;
	int xinc, yinc;
	int dx, dy;

	dx = (x2-x1);
	dy = (y2-y1);

	if(dx>=dy)
	{
		steps = dx;
	}
	else if(dx<dy)
	{
		steps = dy;
	}

	int x = x1;
	int y = y1; 	
	
	xinc = dx/steps;
	yinc = dy/steps;

	for(int i=1; i<=steps; i++)
	{
		
		glPointSize(w);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();

		x = x + xinc;
		y = y + yinc;
	}
}
