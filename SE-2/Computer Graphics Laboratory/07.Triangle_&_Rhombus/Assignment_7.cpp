#include<iostream>
#include<math.h>
#include<GL/glut.h>

using namespace std;

void Init();
void Display();
void dda(int,int,int,int);
void ddas(int,int,int,int);
void ddar(int,int,int,int);
void ddat(int,int,int,int);
void ddax(int,int,int,int);
void dday(int,int,int,int);

int main(int a, char **c)
{
	glutInit(&a, c);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Triangle & Rhombus");
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
}

void Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000.0,1000.0,-1000.0,1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	int choice1, choice2;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	
	//draw
	do
	{
		cout << "\n\nPress 1 for triangle.\n";
		cout << "Press 2 for rhombus.\n";
		cout << "Press 9 to exit.\n";
		cout << "\nYour choice : ";
		cin >> choice1;
		cout << "\n\n";
		switch(choice1)
		{
			case 1:	do
				{
					glClear(GL_COLOR_BUFFER_BIT);
					glClearColor(0.0,0.0,0.0,1.0);
					
					cout << "\n\nPress 1 for normal triangle.\n";
					cout << "Press 2 for scaling of triangle.\n";
					cout << "Press 3 for rotation of triangle.\n";
					cout << "Press 4 for translation of triangle.\n";
					cout << "Press 5 for x-shearing of triangle.\n";
					cout << "Press 6 for y-shearing of triangle.\n";
					cout << "Press 9 to go back.\n";
					cout << "\nEnter your choice : ";
					cin >> choice2;

					switch(choice2)
					{
						case 1: dda(-1.73*200,-200,0,2*200);
							dda(-1.73*200,-200,1.73*200,-200);
							dda(1.73*200,-200,0,2*200);
							break;

						case 2: ddas(-1.73*200,-200,0,2*200);
							ddas(-1.73*200,-200,1.73*200,-200);
							ddas(1.73*200,-200,0,2*200);
							break;

						case 3: ddar(-1.73*200,-200,0,2*200);
							ddar(-1.73*200,-200,1.73*200,-200);
							ddar(1.73*200,-200,0,2*200);
							break;

						case 4: ddat(-1.73*200,-200,0,2*200);
							ddat(-1.73*200,-200,1.73*200,-200);
							ddat(1.73*200,-200,0,2*200);
							break;

						case 5: ddax(-1.73*200,-200,0,2*200);
							ddax(-1.73*200,-200,1.73*200,-200);
							ddax(1.73*200,-200,0,2*200);
							break;

						case 6: dday(-1.73*200,-200,0,2*200);
							dday(-1.73*200,-200,1.73*200,-200);
							dday(1.73*200,-200,0,2*200);
							break;

					}

				}while(choice2!=9);
			
				break;

			case 2:	do
				{
					glClear(GL_COLOR_BUFFER_BIT);
					glClearColor(0.0,0.0,0.0,1.0);
					

					cout << "\n\nPress 1 for normal rhombus.\n";
					cout << "Press 2 for scaling of rhombus.\n";
					cout << "Press 3 for rotation of rhombus.\n";
					cout << "Press 4 for translation of rhombus.\n";
					cout << "Press 5 for x-shearing of rhombus.\n";
					cout << "Press 6 for y-shearing of rhombus.\n";
					cout << "Press 9 to go back.\n";
					cout << "\nEnter your choice : ";
					cin >> choice2;

					switch(choice2)
					{
						case 1:
							dda(-1.73*100, -100, 0, 2*100);
							dda(0, 2*100, 2*1.73*100, 2*100);
							dda(-1.73*100,-100,1.73*100,-100);
							dda(1.73*100,-100,2*1.73*100,2*100);	

							break;

						case 2:	
							ddas(-1.73*100, -100, 0, 2*100);
							ddas(0, 2*100, 2*1.73*100, 2*100);
							ddas(-1.73*100,-100,1.73*100,-100);
							ddas(1.73*100,-100,2*1.73*100,2*100);
	
							break;

						case 3:
							ddar(-1.73*100, -100, 0, 2*100);
							ddar(0, 2*100, 2*1.73*100, 2*100);
							ddar(-1.73*100,-100,1.73*100,-100);
							ddar(1.73*100,-100,2*1.73*100,2*100);
	
							break;

						case 4:
							ddat(-1.73*100, -100, 0, 2*100);
							ddat(0, 2*100, 2*1.73*100, 2*100);
							ddat(-1.73*100,-100,1.73*100,-100);
							ddat(1.73*100,-100,2*1.73*100,2*100);
	
							break;

						case 5:
							ddax(-1.73*100, -100, 0, 2*100);
							ddax(0, 2*100, 2*1.73*100, 2*100);
							ddax(-1.73*100,-100,1.73*100,-100);
							ddax(1.73*100,-100,2*1.73*100,2*100);
	
							break;
	
						case 6:
							dday(-1.73*100, -100, 0, 2*100);
							dday(0, 2*100, 2*1.73*100, 2*100);
							dday(-1.73*100,-100,1.73*100,-100);
							dday(1.73*100,-100,2*1.73*100,2*100);
	
							break;

					}

				}while(choice2!=9);
				break;

			case 9: cout << "\n\nThank you!!\n\n";
				exit(0);
				break;
		
			default: cout << "\n\nINVALID \n\n";
		}
	}while(choice1 != 9);

	glFlush();
}

void dda(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}

//scaling
void ddas(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(2*x,2*y);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}

//rotation
void ddar(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(-y,x);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}

//translation
void ddat(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x+300, y+300);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}

//x-shear
void ddax(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x+2*y, y);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}

//y-shear
void dday(int x1, int y1, int x2, int y2)
{
	float dx, dy, step=0, m, xinc, yinc;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);

	if(dx>dy){step = dx;}
	else{step = dy;}
	
	xinc = (x2-x1)/(float)step;
	yinc = (y2-y1)/(float)step;

	float x=x1;
	float y=y1;

	for(int i=0; i<step; i++)
	{
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x, y+2*x);
		glEnd();
	
		x=x+xinc;
		y=y+yinc;
	}	
	glFlush();	
}
