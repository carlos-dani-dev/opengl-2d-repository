/*
 * Computacao Grafica
 * Codigo Exemplo: Biblioteca com fucao para desenhar circulo em OpenGL
 * Autor: Prof. Laurindo de Sousa Britto Neto
 */

#ifndef shapes_h
#define shapes_h

#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265f
#endif

void desenhaCirculo(int R, int G, int B){
    
    int i;
    float raio = 50;
	float num_linhas = 30;
    GLfloat angulo;
    
	angulo = (2 * M_PI) / num_linhas; //divide 360 graus em radianos pela quantidade de linhas que serao desenhadas
    

    glBegin(GL_TRIANGLE_FAN);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum
    
	glColor3f(R, G, B);
	    
    for(i = 1; i <= num_linhas; i++){ // FOR usado para o calculo de cada ponto pertencente aos extremos das retas
		// comando que calcula as coord. da rotacao e desenha as retas na tela
        glVertex2f(-raio*sin(i * angulo) , raio*cos(i * angulo));	// centro = (0,0), x = 0 e y = raio;
//		glVertex2f(raio*cos(i * angulo) , raio*sin(i * angulo));	// centro = (0,0), x = raio e y = 0;
	}

    glEnd(); 
}

void desenhaTriangulo(int R, int G, int B){
    
    // glTranslatef(x, y, 1);
    
    glBegin(GL_TRIANGLES);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum

	glColor3f(R, G, B);

    glVertex2f(0, 0);
    glVertex2f(50, 75);
    glVertex2f(100, 0);
    
    glEnd();
}

void desenhaRetangulo(int R, int G, int B){
    
    // glTranslatef(x, y, 1);
    
    glBegin(GL_QUADS);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum

	glColor3f(R, G, B);

    glVertex2f(0, 0);
    glVertex2f(0, 50);
    glVertex2f(125, 50);
    glVertex2f(125, 0);
    
    glEnd();
}

void desenhaRetanguloDaMao(int R, int G, int B){
    
    // glTranslatef(x, y, 1);
    
    glBegin(GL_QUADS);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum

	glColor3f(R, G, B);

    glVertex2f(0, 0);
    glVertex2f(0, 75);
    glVertex2f(50, 75);
    glVertex2f(50,0);
    
    glEnd();
}


void desenhaQuadrado(int R, int G, int B){
    
    // glTranslatef(x, y, 1);
    
    glBegin(GL_QUADS);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum

	glColor3f(R, G, B);

    glVertex2f(0, 0);
    glVertex2f(0, 100);
    glVertex2f(100, 100);
    glVertex2f(100, 0);
    
    glEnd();
}
#endif /* circulo_h */
