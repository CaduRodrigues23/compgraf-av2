#include <glut.h>
#include <stdio.h>
#include <math.h>

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
}


void FuncaoCubo() {
	glColor3f(0.0, 0.8, 0.8);
	//glLoadIdentity();
	glScalef(0.8, 0.2, 1);
	//glRotatef(80, 0, 0, 0);
	glTranslatef(0.4, 0, 0);
	//
	glutWireCube(0.8);
	
	
	//
	
}



void DesenhaRetangulos() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.8, 0.8, 0.05);

	//glRotatef(90, 0, 1, 1);
	//glutWireSphere(0.5, 10, 10);
	
	FuncaoCubo();

	glutReshapeFunc(AumentaTela);
	glFlush();
}



void init(void)
{
	glClearColor(0.0,0.0, 0.0, 1.0);
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Retângulos");
	glutDisplayFunc(DesenhaRetangulos);
	init();

	
	glutMainLoop();
	return(0);
}