#include<iostream>
#include<GL/glut.h>

using namespace std;

void Display();
void init();
void Circle(int);

float r, xc, yc;

int main(int a, char **c)
{
	r = 400;
	cout << "Enter radius of outer circle : ";
	cin >> r;

	glutInit(&a, c);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 100);

	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Circle Drawing");
	glutDisplayFunc(Display);
	init();
	glutMainLoop();
}

void Line(float x1, float y1, float x2, float y2)
{
	float dx, dy, steps, m;
	float xinc, yinc;
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx >= dy)
		steps = dx;
	else
		steps = dy;

	xinc = (x2-x1)/steps;
	yinc = (y2-y1)/steps;

	float x=x1;
	float y=y1;
	
	for(int i=0; i<=steps; i++)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();

		x=x+xinc;
		y=y+yinc;
	}

}

void Circle(int r)
{
	int sum, x, y;
	x = 0;	
	y = r;
	sum = 3-(2*r);
	
	while(x < y)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(-x,y);
		glVertex2i(-x,-y);
		glVertex2i(x,-y);
		glVertex2i(y,x);
		glVertex2i(y,-x);
		glVertex2i(-y,x);
		glVertex2i(-y,-x);			

		glEnd();

		if(sum < 0)
		{
			sum = sum + 4*x + 6;
			x = x+1;
		}
		else
		{
			sum = sum + 4*(x-y) + 10;
			y = y-1;
			x = x+1;
		}
	}
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000,1000,-1000,1000);
	glMatrixMode(GL_MODELVIEW);
	//modelview
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.0,0.0,1.0);
	Circle(r);
	Circle(r/2);
	
	Line(0,r,-(1.732*r)/2, -r/2);
	Line(0,r,(1.732*r)/2, -r/2);
	Line(-(1.732*r)/2, -r/2,(1.732*r)/2, -r/2);
	
	glFlush();
}
