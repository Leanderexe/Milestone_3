#ifndef CHANNEL_H
#define CHANNEL_H
#include <string>
#include <kernel.h>
#include "matrix.h"


class Channel
{
public:
    Channel(int num_channel, std::string object_name, int rows, int columns);
    void Set(matrix* input);   // Sets a new Kernel.
    void Add(vector<vector<double>> input);
    // Adds something to a allready existing Kernel.

    void set_numrows(int rows);
    void set_numcols(int columns);



    void Clear();
    void LReLU();
    void Get_rc(int row, int column);
    void Get_Kernel(vector<vector<double>> kernel);
    void Print();
    vector<vector<double>> Getter_Kernel();
    int Getter_Rows();
    int Getter_Column();


    int num_channel;
    std::string object_name;
    int rows;
    int columns;
    matrix*  kernel;

    //replaced vector<vector<double>> with matrix* objects

};


#endif // CHANNEL_H
