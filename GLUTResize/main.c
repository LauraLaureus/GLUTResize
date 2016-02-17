//
//  main.c
//  GLUTResize
//
//  Created by Laura del Pino Díaz on 17/2/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>

float red = 1.0, green = 1.0, blue = 1.0;
int win1, win2;

void Init(){
    glClearColor(1.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display1(){
    glClear(GL_COLOR_BUFFER_BIT); //fondo negro
    glutWireTeapot(0.5);
    glFlush();
}

void Display2(){
    glClear(GL_COLOR_BUFFER_BIT); //fondo negro
    glutWireTeapot(0.5);
    glFlush();
}

void Dimensiones(int ancho, int alto){
    float dx = 2.0;
    float dy = 2.0;
    
    if (ancho > alto){
        dx = 2.0 * (float)ancho / (float)alto;
    }
    if (alto > ancho){
        dy = 2.0 * (float)alto / (float)ancho;
    }
    
    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, 1.0f, 0.0f);
    glutPostRedisplay();
    
    
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    
    win1 = glutCreateWindow("OpenGL Practica 2_3 1 Laura del Pino Díaz");
    Init();
    glutDisplayFunc(Display1); // define la funcion de rendering
       
    win1 = glutCreateWindow("OpenGL Practica 2_3 2 Laura del Pino Díaz");
    Init();
    glutDisplayFunc(Display2); // define la funcion de rendering
    glutReshapeFunc(Dimensiones);
    
    
    glutMainLoop();
    
    return 0;
}

