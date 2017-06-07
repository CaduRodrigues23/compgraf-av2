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
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0, 0.8, 0.8);
	//glLoadIdentity();
	glPushMatrix();
		glScalef(1, 0.2, 0.5);	
		//glRotatef((GLfloat)60, 0.5, 1, 0.5);
		//glRotatef((GLfloat)20, 0, 1, 0);
		//glRotatef((GLfloat)60, 1, 0, 1);
		//glRotatef((GLfloat)30, 0, 0, 1);
		glTranslatef(0.5, 0.0, 0);
		glPushMatrix();
			glRotatef((GLfloat)30, 1, 0, 0);
			glutWireCube(0.8);
		glPopMatrix();
		
	glPopMatrix();

	glColor3f(0.8, 0.0, 0.8);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.5, 0.2, 1);
	glRotatef((GLfloat)-90, 0, 0, 1);
	glRotatef((GLfloat)-20, 0, 1, 0);
	glRotatef((GLfloat)-60, 1, 0, 1);
	//glRotatef((GLfloat)30, 0, 0, 1);
	glTranslatef(0.0, -0.4, 0);
	glutWireCube(0.8);
	glPopMatrix();
	//
	
	
	
	
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
	glutReshapeFunc(AumentaTela);
	glutDisplayFunc(DesenhaRetangulos);
	init();

	
	glutMainLoop();
	return(0);
}