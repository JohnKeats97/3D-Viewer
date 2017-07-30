#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>


#include "model.h"


void change_model (model& frame, int key)
{
    switch(key){

    // Поворот.
    case (GLUT_KEY_RIGHT):
        frame.turn_model(key);
        break;
    case (GLUT_KEY_LEFT):
        frame.turn_model(key);
        break;
    case (GLUT_KEY_UP):
        frame.turn_model(key);
        break;
    case (GLUT_KEY_DOWN):
        frame.turn_model(key);
        break;

    // Перенос.
    case (GLUT_KEY_F1):
        frame.transfer_model(key);
        break;
    case (GLUT_KEY_F2):
        frame.transfer_model(key);
        break;
    case (GLUT_KEY_F3):
        frame.transfer_model(key);
        break;
    case (GLUT_KEY_F4):
        frame.transfer_model(key);
        break;
    case (GLUT_KEY_F5):
        frame.transfer_model(key);
        break;
    case (GLUT_KEY_F6):
        frame.transfer_model(key);
        break;

    // Масштабирование.
    case (GLUT_KEY_F9):
        frame.scale_model(key);
        break;
    case (GLUT_KEY_F10):
        frame.scale_model(key);
        break;

    }

}


