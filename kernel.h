#ifndef KERNEL_H
#define KERNEL_H
#include "neuron.h"
#include "matrix.h"

class Kernel
{
public:
    Kernel(int row, int columns);

    void Dimension(int rows, int column);
    void Weight();
    void Print();
    void Reset();
    // Getter are returns the specific value\vector.
    vector<vector<double>>  Getter_Kernel();
    int Getter_Rows();
    int Getter_Column();
    // Get receives arguments and changes the values for the certain object.
    void Get_Kernel(vector<vector<double>> kernel);
    void Get_rc(int row, int column);


    vector<vector<double>> kernel;
    int rows;
    int column;

    };
#endif // KERNEL_H
