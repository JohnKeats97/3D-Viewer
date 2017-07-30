#ifndef MODEL_H
#define MODELH

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

class model
{
public:
    // чтение модели из файла и выделение памяти
    void get_member ();
    void get_count (std::ifstream &file);
    void get_edge (std::ifstream &file);
    // освобождение памяти под модели
    void DeleteModel();
    // изменение модели
    void scale_model (int key);
    void transfer_model ( int key);
    void turn_model (int key);
    // отрисовка модели
    void draw_changes ();
    void draw_edge ();
    // откатывает изменения при загрузки новой модели
    void new_change ();

    ~model();

private:
    double* arrX;
    double* arrY;
    double* arrZ;
    int count_touch;
    int count;
    int* arr;
    double rotate_x;
    double rotate_y;
    double scale;
    double translated_x;
    double translated_y;
    double translated_z;
};


// создание модели
model CreateModel ();

// изменение модели
void change_model (model& frame, int key);

// отрисовка модели
void draw_model (model& frame);

// получение модели из файла
void get_model (model& frame);

// загрузка новой модели
void create_new_model (model& frame);

#endif // MODEL_H
