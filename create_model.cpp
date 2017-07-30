#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#include "model.h"


model CreateModel ()
{
    model frame;

    get_model (frame);

    return frame;
}

void create_new_model (model& frame)
{
    frame.DeleteModel();
    get_model (frame);
}

void get_model (model& frame)
{
    std::string str_file;
    std::cout << "Введите путь к файлу (.../): ";
    std::cin >> str_file;
    //str_file = "/home/john/Git/3D-Viewer/Examples/";

    std::string file_name;
    std::cout << "Введите имя файла (*.txt):  ";
    std::cin >> file_name;
    //file_name = "cube.txt";
    //file_name = "bicone16.txt";

    str_file += file_name;

    std::ifstream file;

    file.open(str_file.c_str());

    if (!file.is_open())
        throw "No file";


    frame.get_count (file);
    frame.get_member ();
    frame.get_edge (file);

    frame.new_change();

    file.close();
}
