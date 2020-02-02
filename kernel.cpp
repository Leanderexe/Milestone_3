#include "kernel.h"
#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>


Kernel::Kernel(int row,int column){
    this->rows = row;
    this->column = column;
}


void Kernel::Weight(){

    srand (time(NULL));
    vector <double> temp;
    for(int i = 0; i < (rows); i++){
    for(int z = 0; z < (column);z++){
        int random_int = (rand( )% 2);  // Decides by random if the weigth number is negativ (0) or positiv (1).
        if (random_int < 1){
            temp.push_back((double)-(rand()% 10000)/10000);  // Inputs random weigths number between 0 and -1 with max 4 digits after the comma.
        }
        else {
            temp.push_back((double)(rand()% 10000)/10000);  // Inputs random weigths number between 0 and 1 with max 4 digits after the comma.
        }
    }
    this->kernel.push_back(temp);
    temp.clear();
}
}

void Kernel::Dimension(int r, int c){
    this->rows = r;
    this->column = c;

}

    void Kernel::Print(){
        for(int i = 0; i < (rows); i++){
        for(int z = 0; z < (column);z++){
            cout << this->kernel[i][z] << ' ';
    }
        cout << endl;
        }
        cout << endl;
    }


    void Kernel::Reset(){
        vector <vector<double>> vector;
        vector.swap(this->kernel);
        this->rows = 0;
        this->column = 0;
    }


    vector <vector <double>> Kernel::Getter_Kernel(){
        vector <vector <double>> help;
        vector <double> temp;
        for(int i = 0; i < (rows); i++){
        for(int z = 0; z < (column);z++){
            temp.push_back(this->kernel[i][z]);
        }
        help.push_back(temp);
        temp.clear();
        }
        return(help);
    }

    int Kernel::Getter_Rows(){
        return(this->rows);
    }

    int Kernel::Getter_Column(){
        return(this->column);
    }


    void Kernel::Get_Kernel(vector<vector<double>> kernel){
        this->kernel.swap(kernel);
    }


    void Kernel::Get_rc(int row, int column){
        this->rows = row;
        this->column = column;
    }
