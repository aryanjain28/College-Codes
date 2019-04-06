#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

void Display(void);
void init();

float x1,x2,y1,y2;
int n;

int main(int a, char **c)
{
	cout << "Enter coorinates { (X1,Y1)  (X2, Y2) } : ";
	cin >> x1 >> y1 >> x2 >> y2;	
	cout << "Enter number of intersections : ";
	cin >> n;

	glutInit(&a, c);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Koch Curves!");
	glutDisplayFunc(Display);
	init();
	glutMainLoop();
}

void Koch(float x1, float y1, float x2, float y2, int n)
{
	float x4,y4,x3,y3,x,y;

	x3 = (2*x1+x2)/3;
	y3 = (2*y1+y2)/3;

	x4 = (x1+2*x2)/3;
	y4 = (y1+2*y2)/3;	

	x = x3 + (x4-x3)*0.5 + (y4-y3)*0.8660;
	y = y3 - (x4-x3)*0.8660 + (y4-y3)*0.5;	
/*
	float Angle = (60*3.14)/2;
	x = x3 + (x4-x3)*cos(Angle) + (y4-y3)*sin(Angle);
	y = y3 - (x4-x3)*sin(Angle) + (y4-y3)*con(Angle);
*/	
	if(n>0)
	{
		Koch(x1,y1,x3,y3,n-1);
		Koch(x3,y3,x,y,n-1);
		Koch(x,y,x4,y4,n-1);
		Koch(x4,y4,x2,y2,n-1);
	}
	else
	{
		glBegin(GL_LINE_STRIP);

		glColor3f(1.0,0.0,1.0);
		glVertex2f(x1,y1);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(x3,y3);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(x,y);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(x4,y4);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(x2,y2);

		glEnd();
	}
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,600.0,600.0,0.0);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	Koch(x1,y1,x2,y2,n);
	glFlush();
}
