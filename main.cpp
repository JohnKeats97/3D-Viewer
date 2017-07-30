#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"

void special_keys(int key, int x, int y);


void first_display(){}


int main(int argc, char* argv[]){

    glutInit(&argc,argv);

    // Создаём окно
    glutCreateWindow("Figure");

    // Отрисовка сцены
    glutDisplayFunc(first_display);

    // Преобразования (Вход в программу)
    glutSpecialFunc(special_keys);

    glutPostRedisplay();

    glutMainLoop();

    return 0;

}
