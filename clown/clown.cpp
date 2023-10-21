/*
 * Computacao Grafica
 * Codigo Exemplo: Primeira Janela GLUT/OpenGL
 * Autor: Prof. Laurindo de Sousa Britto Neto
 */
 
// Bibliotecas utilizadas pelo OpenGL
#ifdef _APPLE_ // MacOS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else // Windows e Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <cmath>
#include <iostream>
#include "shapes.h"
#define ESC 27


// Declaracoes antecipadas (forward) de funcoes para as funcoes callback do OpenGL
void glut_initializer(int argc, char** argv);
void window_editor(int largura, int altura);
void keyboard(unsigned char key, int x, int y);
void plotar_objetos(void);

/*
 * Funcao principal
 */
int main(int argc, char** argv){
    glut_initializer(argc, argv); // Chama a funcao inicializador_do_glut();
    glutReshapeFunc(window_editor);
	glutDisplayFunc(plotar_objetos);
	glutKeyboardFunc(keyboard);
    glutMainLoop(); // executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}

/*
 * Inicializa alguns parametros do GLUT
 */
void glut_initializer(int argc, char** argv){
	
	glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (512, 512);  // Tamanho da janela do OpenGL
    glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow ("Computcao Grafica: Primeira Janela GLUT/OpenGL"); // Da nome para uma janela OpenGL
	
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
}


/*
 * Ajusta a projecao para o redesenho da janela
 */
void window_editor(int largura, int altura){
	
	largura = 1000;
	altura = 1000;
	
	glMatrixMode(GL_PROJECTION); // nesse modo, a projeção é setada e modificada
	glLoadIdentity(); // reinicializa-se o sistema de coordenadas

    // define-se a área de dentro janela a ser trabalhada
	glViewport(0, 0, 500, 500);

	// define-se como ocorrerá a projeção ortográfica, ou seja,
    //os limites da projeção, em relação ao tamanho da janela, são delimitados
	
	glOrtho (0, largura, 0, altura, -1 ,1);  // Nesse caso, o ponto (0,0,0) se encontra no
                                      // canto inferior esquerdo da tela e o viewport
                                      // tem 0 a 512 pixel no eixo x, 0 a 512 pixel no
                                      // eixo y. Como sera trabalhado imagens 2D definimos
                                      // o eixo z com tamanho -1 a 1;

// glOrtho (-256, 256, -256, 256, -1 ,1); // Nesse caso, continuamos com 512 pixels, porem o
                                            // centro dos eixos passa a se localizar no centro
                                            // da tela.

// glOrtho (-(largura/2), (largura/2),-(altura/2),(altura/2), -1 ,1);   // Nesse caso, ficamos com a quantidade de pixels variavel,
                                                    // dependente da largura e altura da janela, e o
                                                    // centro dos eixos continua a se localizar no centro
                                                    // da tela.
    
	// muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
	//enquanto estivermos desenhando na tela)
	// nesse modo, o objeto é desenhado
	glMatrixMode(GL_MODELVIEW);
}

/*
 * Funcao usada na funcao callback para controlar as teclas comuns (1 Byte) do teclado
 */
void keyboard(unsigned char key, int x, int y){
    switch (key) { // key - variavel que possui valor ASCII da tecla precionada
        case ESC: exit(EXIT_SUCCESS); break; //encerra o programa com sucesso
    }
}

void desenhaCabeca(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500, 700, 0);
	glScalef(2.5, 2.5, 1);
	desenhaCirculo(255, 255, 0);

	glPopMatrix();
}

void desenhaOlhos(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(450, 745, 0);
	glScalef(0.45, 0.45, 1);
	desenhaCirculo(0, 0, 0);
	
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(550, 745, 0);
	glScalef(0.45, 0.45, 1);
	desenhaCirculo(0, 0, 0);
	
	glPopMatrix();
	
}

void desenhaNariz(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500, 700, 0);
	glScalef(0.50, 0.50, 1);
	desenhaCirculo(255, 0, 0);
	
	glPopMatrix();
	
}

void desenhaBoca(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500, 615, 0);
	glScalef(0.25, 0.25, 1);
	desenhaCirculo(255, 255, 255);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(462, 623, 0);
	glScalef(0.25, 0.25, 1);
	desenhaCirculo(255, 255, 255);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(430, 640, 0);
	glScalef(0.25, 0.25, 1);
	desenhaCirculo(255, 255, 255);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(538, 623, 0);
	glScalef(0.25, 0.25, 1);
	desenhaCirculo(255, 255, 255);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(570, 640, 0);
	glScalef(0.25, 0.25, 1);
	desenhaCirculo(255, 255, 255);
	
	glPopMatrix();
	
}

void desenhaChapeu(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(375, 820, 0);
	glScalef(2.5, 2.5, 1);
	desenhaTriangulo(0, 0, 255);
	
	glPopMatrix();
	
}


void desenhaBracos(void){
	glLoadIdentity();
	glPushMatrix();
	
	//glTranslatef(0, 0, 0);
	glScalef(2.5, 2.5, 1);
	glRotatef(30, 0, 0, 1);
	glTranslatef(330, 22, 0);
	desenhaRetangulo(255, 0, 0);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	//glTranslatef(0, 0, 0);
	glRotatef(-30, 0, 0, 1);
	glTranslatef(-273, 553, 0);
	glScalef(2.5, 2.5, 1);
	desenhaRetangulo(255, 0, 0);
	
	glPopMatrix();
}

void desenhaMaos(void){
	glLoadIdentity();
	glPushMatrix();
	
	//glTranslatef(0, 0, 0);
	glScalef(1.5, 1.5, 1);
	glRotatef(30, 0, 0, 1);
	glTranslatef(760, 42, 0);
	desenhaRetanguloDaMao(255, 255, 0);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	//glTranslatef(0, 0, 0);
	glRotatef(-30, 0, 0, 1);
	glTranslatef(-350, 558, 0);
	glScalef(1.5, 1.5, 1);
	desenhaRetanguloDaMao(255, 255, 0);
	
	glPopMatrix();
}


void desenhaBotoes(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500, 525, 0);
	glScalef(0.50, 0.50, 1);
	desenhaCirculo(0, 255, 0);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500,450, 0);
	glScalef(0.50, 0.50, 1);
	desenhaCirculo(0, 255, 0);
	
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(500, 375, 0);
	glScalef(0.50, 0.50, 1);
	desenhaCirculo(0, 255, 0);
	
	glPopMatrix();
	
}

void desenhaCorpo(void){
	glLoadIdentity();
	glPushMatrix();
	
	glTranslatef(375, 325, 0);
	glScalef(2.5, 2.5, 1);
	desenhaQuadrado(0, 0, 255);
	
	glPopMatrix();
	
}

void desenhaPernas(void){
	glLoadIdentity();
	glPushMatrix();
	
	
	glColor3f(1, 0, 0);
	glTranslatef(350, 345, 0);	
	glRotatef(-20, 0 ,0 ,1);
	
	glBegin(GL_QUADS);
	glVertex2f(160, -10);
	glVertex2f(160, -280);
	glVertex2f(30, -280);
	glVertex2f(30, -10);
	glEnd();
	glPopMatrix();
	
	glLoadIdentity();
	glPushMatrix();
	
	
	glColor3f(1, 0, 0);
	glTranslatef(465, 280, 0);	
	glRotatef(20, 0 ,0 ,1);
	
	glBegin(GL_QUADS);
	glVertex2f(160, -10);
	glVertex2f(160, -280);
	glVertex2f(30, -280);
	glVertex2f(30, -10);
	glEnd();
	glPopMatrix();
	
}

void desenhaPes(void){
	
	glLoadIdentity();
	glPushMatrix();
	
	glColor3f(1, 1, 0);
	glTranslatef(270, 85, 0);
	glRotatef(-20, 0, 0, 1);
	
	glBegin(GL_QUADS);
	glVertex2f(150, -10);
	glVertex2f(150, -50);
	glVertex2f(10, -50);
	glVertex2f(10, -10);
	glEnd();	
	glPopMatrix();

	glLoadIdentity();
	glPushMatrix();
	
	glColor3f(1, 1, 0);
	glTranslatef(570, 30, 0);
	glRotatef(20, 0, 0, 1);

	glBegin(GL_QUADS);
	glVertex2f(150, -10);
	glVertex2f(150, -50);
	glVertex2f(10, -50);
	glVertex2f(10, -10);
	glEnd();	
	glPopMatrix();
}

void plotar_objetos(void){
	
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	desenhaCabeca();
	desenhaOlhos();
	desenhaNariz();
	desenhaBoca();
	desenhaChapeu();
	
	desenhaCorpo();
	desenhaBotoes();
	
	desenhaBracos();
	desenhaMaos();
	
	desenhaPernas();
	desenhaPes();
	
    glFlush(); // manda o OpenGl renderizar as primitivas
}