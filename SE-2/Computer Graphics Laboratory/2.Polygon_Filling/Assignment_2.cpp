#include<GL/glut.h>
#include<iostream>

using namespace std;

static int step=0;

struct Color
{	
	float red;
	float green;
	float blue;
};

Color OLD;
Color NEW;
Color SELECT;

Color getColor(int x, int y)
{
	Color color;
	glReadPixels(x,y,1,1,GL_RGB, GL_FLOAT,&color);
	return color;
}

void setColor(int x, int y, Color color)
{
	glColor3f(color.red, color.green, color.blue);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void Display();
void init();
void Mouse(int,int,int,int);
void Keyboard(unsigned char key, int x, int y);
void DrawLine(int x1, int y1, int x2, int y2);

int main(int a, char **c)
{
	glutInit(&a, c);	
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(200, 50);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Polygon Filling");
	init();
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(Display);
	glutMainLoop();
}

int xf, yf, xtemp, ytemp;

void FloodFill(int x, int y)
{
	NEW = getColor(x,y);
	if(OLD.red == NEW.red && OLD.green == NEW.green && OLD.blue == NEW.blue)
	{
		setColor(x,y,SELECT);
		FloodFill(x+1,y);
		FloodFill(x,y+1);
		FloodFill(x,y-1);
		FloodFill(x-1,y);	
	}
	glFlush();
}

void Keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		exit(0);

	DrawLine(xf, yf, xtemp, ytemp);
	glFlush();
	step = 2;
}

void Mouse(int button, int state, int x, int y)
{
	glColor3f(1.0,1.0,1.0);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(step == 0)
		{
			xf = x;
			yf = 650-y;
			xtemp = x;
			ytemp = 650-y;

			step = 1;
		}
		else if(step == 1)
		{
			DrawLine(xtemp, ytemp, x, 650-y);
			xtemp = x;
			ytemp = 650-y;
		}
		else if(step == 2)
		{
			SELECT = getColor(x,650-y);
			step = 3;
		}
		else if(step == 3)
		{
			OLD.red = 0.0f;
			OLD.green = 0.0f;
			OLD.blue = 0.0f;

			FloodFill(x,650-y);
		}
	}
	glFlush();
}

void DrawLine(int x1, int y1, int x2, int y2)
{
	float dx, dy;
	float steps;

	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>=dy)
		steps = dx;
	else
		steps = dy;

	float xinc = (x2-x1)/(float)steps;
	float yinc = (y2-y1)/(float)steps;

	float x = x1;
	float y = y1;

	for(int i=0; i<=steps; i++)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();

		x = x+xinc;
		y = y+yinc;
	}
	glFlush();
}

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,650,0,650);
	glMatrixMode(GL_MODELVIEW);
	glFlush();
}

void Display()
{
	glColor3f(1.0,0.0,0.0);
	glRecti(20, 20, 70, 70);
	glColor3f(0.0,1.0,0.0);
	glRecti(90, 20, 140, 70);
	glColor3f(0.0,0.0,1.0);
	glRecti(160, 20, 210, 70);

	glFlush();
}
