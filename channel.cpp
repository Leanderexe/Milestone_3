#include "channel.h"
#include <string>
#include "kernel.h"
#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>

Channel::Channel(int number_channel,std::string object_name, int rows, int columns){
    this->num_channel = number_channel;
    this->object_name = object_name;
    this->columns = columns;
    this->rows = rows;
}

void Channel::set_numcols(int columns){
    this->columns = columns;
}

void Channel::set_numrows(int rows){
    this->rows = rows;
}


void Channel::LReLU(){
 for(int i = 0; i < (this->rows); i++)
 for(int z = 0; z < (this->columns);z++){
    if (kernel->getValue(i, z) < 0){
        kernel->setValue(i,z, kernel->getValue(i, z) * 0.01);
     }
   else{
}
    }
}

 void Channel::Print(){
     for(int i = 0; i < (rows); i++){
     for(int z = 0; z < (columns);z++){
         cout << kernel->getValue(i, z) << ' ';
 }
     cout << endl;
     }
     cout << endl;
 }

void Channel::Get_rc(int row, int column){
    this->rows = row;
    this->columns = column;
}

// Get_Kernel, ist glaube ich überflüssig wenn man mit pointer arbeitet.
void Channel::Get_Kernel(vector<vector<double>> kern){  // Pushes a given matrix into the kernel.
    vector <double> temp;
    for(int i = 0; i < (rows); i++){
    for(int z = 0; z < (columns);z++){
    kernel->setValue(i,z,kern[i][z]);
    }
}
    }

// keine ahnung was die macht bitte anpassen/verpassen
// gleiche gilt für die unteren funktionen


vector<vector<double>> Channel::Getter_Kernel(){ // Returns the matrix of the kernel. Use it to get the initialized random Matrix from class Kernel.
    vector <vector <double>> help;
    vector <double> temp;
    for(int i = 0; i < (rows); i++){
    for(int z = 0; z < (columns);z++){
        temp.push_back(kernel->getValue(i, z));
    }
    help.push_back(temp);
    temp.clear();
    }
    return(help);   // Returns the Kernel.
}

void Channel::Clear(){
    matrix* vector = new matrix(0, 0, false);
    this->kernel = vector;
    this->rows = 0;
    this->columns = 0;
    // this->kernel.shrink_to_fit();
}



void Channel::Set(matrix* input){
    this->kernel = input;
}


void Channel::Add(vector<vector<double>> input){  // Adds a given input to the allready existing kernel.
    vector<double> temp;
    for(int i = 0; i < (input.size()); i++){
    for(int z = 0; z < (input[0].size());z++){
        kernel->setValue(i,z,input[i][z]);
}
  }
    this->rows += input.size();  // Adds the number of added rows to the attribute.
    this->columns = input[0].size();
   }

int Channel::Getter_Rows(){
    return(this->rows);
}

int Channel::Getter_Column(){
    return(this->columns);
}
