#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"

void start_model (int key);

void special_keys(int key, int x, int y)
{
    try {
        // Работа с моделью.
        start_model(key);
    }

    // Обработка ошибок.
    catch (char const* error) {
        std::cerr << error << "\n";
    }
}




