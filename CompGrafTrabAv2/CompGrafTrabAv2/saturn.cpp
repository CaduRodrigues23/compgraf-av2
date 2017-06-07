#include <glut.h>
#include <stdio.h>
#include <math.h>
/*
void AumentaTela(int w, int h)
{
	int altura, largura;

	if (h == 0)
		h = 1;

	largura = w;
	altura = h;

	glViewport(0, 0, largura, altura);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (largura <= altura)
		gluOrtho2D(-1.0, 1.0, -1.0 * altura / largura, -1.0 * altura / largura);
	else
		gluOrtho2D(-1.0 * largura / altura, 1.0 * largura / altura, -1.0, 1.0);
}*/

void FuncaoAnel1() {
	glColor3f(0.0, 0.6, 0.5);
	glLoadIdentity();
	
	glutWireTorus(0.1, 0.7, 20, 20);
	//glRotatef(360, 0, 0, 0);
	glScalef(0.2, 1, 1);
	
}

void FuncaoAnel2() {
	glColor3f(0.0, 0.6, 0.5);
	glLoadIdentity();
	glutWireTorus(0.1, 0.7, 20, 20);
	glRotatef(90, 0.2, 0.1, 0.6);
	glScalef(0.2, 1, 1);
	
}

void FuncaoPlaneta() {
	glColor3f(0.0, 0.8, 0.8);
	glLoadIdentity();
	glutWireSphere(0.5, 10, 10);
	glRotatef(90, 1, 0, 1);
}

void DesenhaSaturno() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.8, 0.8, 0.05);

	//glRotatef(90, 0, 1, 1);
	//glutWireSphere(0.5, 10, 10);

	FuncaoPlaneta();
	FuncaoAnel2();
	FuncaoAnel1();


	//glutReshapeFunc(AumentaTela);
	glFlush();
}


/*
void init(void)
{
	glClearColor(0.0,0.0, 0.0, 1.0);
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Saturno");
	glutDisplayFunc(DesenhaSaturno);
	init();

	
	glutMainLoop();
	return(0);
}*/