#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"

void start_model (int key)
{
    // Ввод модели.
    static model frame = CreateModel();

    // Изменение модели.
    change_model (frame, key);

    // Загрузить модель из нового файла
    if (key == GLUT_KEY_INSERT){
        create_new_model (frame);
    }

    // Отрисовка модели.
//    if (key == GLUT_KEY_HOME){
        draw_model(frame);
//    }

}

