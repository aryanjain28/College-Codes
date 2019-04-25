#include<GL/glut.h>
#include<math.h>

struct Color
{
	float red;
	float green;
	float blue;
};

Color BLACK;
Color WHITE = {1.0,1.0,1.0};
Color OLD;

void Display(void);
void Structure(int x1, int y1, int x2, int y2);
int sign(int);
void init(void);
void FillColor(int x, int y);
void Mouse(int button ,int state, int x, int y);

int main(int a, char **c)
{
	glutInit(&a, c);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Chess Board!");
	glutDisplayFunc(Display);
	glutMouseFunc(Mouse);
	init();
	glutMainLoop();
}

Color getColor(int x, int y)
{
	Color color;
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&color);
	return color;
}

void setColor(int x, int y, Color color)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);	
	glEnd();
	glFlush();
}

void FillColor(int x, int y)
{
	BLACK = getColor(x,y);
	if(BLACK.red == OLD.red && BLACK.green == OLD.green && BLACK.blue == OLD.blue)
	{
		setColor(x,y,WHITE);
		FillColor(x,y-1);
		FillColor(x,y+1);
		FillColor(x-1,y);
		FillColor(x+1,y);
	}
	glFlush();
}

void Mouse(int button ,int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	
		OLD = getColor(x, 600-y);
		FillColor(x, 600-y);
	}
	glFlush();
}

void Structure(int x1, int y1, int x2, int y2)
{
	float dx,dy,s1,s2,swap=0,temp, G;
	float x,y;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	
	s1 = sign(x2-x1);
	s2 = sign(y2-y1);

	x = x1;
	y = y1;

	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		swap=1;
	}

	G = 2*dy - dx;

	for(int i=0; i<=dx; i++)
	{
		float a = x*cos(45*(3.14/180)) + y*sin(45*(3.14/180));
		float b = -x*sin(45*(3.14/180)) + y*cos(45*(3.14/180));

		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(a,b);
		glEnd();
	
		while(G>=0)
		{
			if(swap == 1)
				x = x + s1;
			else
				y = y + s2;

			G = G - 2*dx;
		}

		if(swap == 1)
			y = y + s2;
		else
			x = x + s1;

		G = G + 2*dy;
	}
	glFlush();	
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);

	Structure(50,350,250,350);
	Structure(50,400,250,400);
	Structure(50,450,250,450);	
	Structure(50,500,250,500);
	Structure(50,550,250,550);

	Structure(50,550,50,350);
	Structure(250,350,250,550);

	Structure(100,350,100,550);
	Structure(150,350,150,550);
	Structure(200,350,200,550);	
	
	glFlush();
}

int sign(int x)
{
	if(x>=0) return 1;
	return -1;
}
