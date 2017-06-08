#include <glut.h>

void DesenhaRetangulos() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glLoadIdentity();
	glRotatef((GLfloat) 60.0, 0.1, 0.0, 1.0);
	glScalef(1, 0.2, 0.5);
	glTranslatef(0.4, -0.5, 0.0);
	glutWireCube(0.8);
	glPopMatrix();


	glPushMatrix();
	glLoadIdentity();
	glRotatef((GLfloat) 40.0, 0.2, 0.0, -1.0);
	glScalef(1, 0.2, 0.5);
	glTranslatef(-0.3, 0.1, 0);
	glutWireCube(0.8);
	glPopMatrix();

	glFlush();
}

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

void init(void)
{
	glClearColor(0.0,0.0, 0.0, 1.0);
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Paralelepipedos");
	init();
	glutDisplayFunc(DesenhaRetangulos);
	glutReshapeFunc(AumentaTela);
	glutMainLoop();
	return(0);
}