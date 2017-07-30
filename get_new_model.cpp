#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "create_data.h"
#include "start_work.h"
#include "model.h"
#include "change_model.h"
#include "draw_model.h"
#include "error_processing.h"

int get_new_model (struct model& frame, int &input_error, struct information* data)
{
    int error = 0;

    data->str_file = "/home/john/OOP/lab1/Examples/";

    data->str_file += get_file_name ();

    std::ifstream file;

    file.open(data->str_file.c_str());
    if (!file.is_open()){
        input_error = 2;
    }

    error += get_count (frame, input_error, file);
    error += DeleteModel (frame, input_error);
    error += get_member (frame, input_error);
    error += get_edge (frame, input_error, file);
    error += get_change (frame, input_error);

    file.close();

    return error;

}


