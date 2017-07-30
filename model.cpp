#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"


model::~model ()
{
    DeleteModel ();
}


// Очищение памяти под модель
void model::DeleteModel ()
{
    if (arr != NULL)
        delete[] arr;
    if (arrX != NULL)
        delete[] arrX;
    if (arrY != NULL)
        delete[] arrY;
    if (arrZ != NULL)
        delete[] arrZ;
}

void model::new_change()
{
    rotate_x = 0;
    rotate_y = 0;
    scale = 1;
    translated_x = 0;
    translated_y = 0;
    translated_z = 0;
}

void model::get_count (std::ifstream &file)
{

    file >> count_touch;
    file >> count;

    if (!count || !count_touch)
        throw "Error: count || count_touch == 0";

    count *= 2;
}

void model::get_member ()
{
    arrX = new double [count_touch];
    arrY = new double [count_touch];
    arrZ = new double [count_touch];
    arr = new int [count];

    if (!arrX || !arrY || !arrZ || !arr)
        throw "Member error";
}

void model::get_edge (std::ifstream &file)
{
    // Считываем ребра.
    for (int i = 0; i < count_touch; i++){
        file >> arrX[i] >> arrY[i] >> arrZ[i];
    }

    // Считываем соединения ребер.
    for (int i = 0; i < count; i+=2){
        file >> arr[i] >> arr[i+1];
    }
}

void model::scale_model ( int key )
{
    if (key == GLUT_KEY_F9)
      scale /= 1.08;

    else if (key == GLUT_KEY_F10)
      scale *= 1.08;
}

void model::transfer_model (int key)
{
    if (key == GLUT_KEY_F1)
      translated_x += 0.04;

    else if (key == GLUT_KEY_F2)
      translated_x -= 0.04;

    else if (key == GLUT_KEY_F3)
      translated_y += 0.04;

    else if (key == GLUT_KEY_F4)
      translated_y -= 0.04;

    else if (key == GLUT_KEY_F5)
      translated_z += 0.04;

    else if (key == GLUT_KEY_F6)
      translated_z -= 0.04;
}

void model::turn_model ( int key )
{

    if (key == GLUT_KEY_RIGHT)
      rotate_y += 5;

    else if (key == GLUT_KEY_LEFT)
      rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
      rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
      rotate_x -= 5;
}

void model::draw_changes ()
{
    // Поворот при отрисовке.
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    // Масштабирование при отрисовке.
    glScalef(scale, scale, scale);

    // Перенос при отрисовке.
    glTranslated(translated_x, translated_y, translated_z);
}

void model::draw_edge ()
{
    for (int i = 0; i < count; i+=2){
        glBegin(GL_POLYGON);
        glColor3f(   128,  128, 128 );
        glVertex3f(  arrX[arr[i]], arrY[arr[i]], arrZ[arr[i]] );
        glVertex3f(  arrX[arr[i+1]], arrY[arr[i+1]], arrZ[arr[i+1]] );
        glVertex3f(  arrX[arr[i]], arrY[arr[i]], arrZ[arr[i]] );
        glEnd();
    }
}
