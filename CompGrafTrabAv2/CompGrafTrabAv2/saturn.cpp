#include <glut.h>

//OBS: faltam as funções de iluminação

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

void FuncaoAnel1() {
	glColor3f(0.0, 0.6, 0.5);
	glPushMatrix();
		glLoadIdentity();
		glScalef(0.2, 1, 1);
		glutWireTorus(0.1, 0.7, 20, 20);
	glPopMatrix();
	
}

void DesenhaSaturno() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.7, 0.5, 0.2);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(90, 1.0, 0.0, 0.0);
		glutSolidSphere(0.5, 10, 10);
	glPopMatrix();

	glColor3f(0.5, 0.3, 0.1);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(90, 0.2, 0.1, 0.6);
	glScalef(0.2, 1, 1);
	glTranslatef(0, 0, 0);
	glutSolidTorus(0.1, 0.7, 20, 20);
	glPopMatrix();

	glFlush();
}



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
}