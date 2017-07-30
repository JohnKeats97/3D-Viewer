#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"

void draw_model(model& frame)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    frame.draw_changes();

    // Выделяем только рёбра.
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    // Отрисовка ребер.
    frame.draw_edge();

    glFlush();
    glutSwapBuffers();
}

