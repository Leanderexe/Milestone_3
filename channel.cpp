#include "channel.h"
#include <string>
#include "kernel.h"
#include "matrix.h"
#include <iostream>
#include <random>
#include "time.h"
#include <map>

Channel::Channel(int number_channel,std::string object_name){
    this->num_channel = number_channel;
    this->object_name = object_name;
}

void Channel::LReLU(){
 for(int i = 0; i < (this->rows); i++)
 for(int z = 0; z < (this->column);z++){
    if (kernel[i][z] < 0){
        kernel[i][z] = kernel[i][z] * 0.01;
     }
   else{
}
    }
}

 void Channel::Print(){
     for(int i = 0; i < (rows); i++){
     for(int z = 0; z < (column);z++){
         cout << this->kernel[i][z] << ' ';
 }
     cout << endl;
     }
     cout << endl;
 }

void Channel::Get_rc(int row, int column){
    this->rows = row;
    this->column = column;
}

void Channel::Get_Kernel(vector<vector<double>> kernel){
    vector <double> temp;
    for(int i = 0; i < (rows); i++){
    for(int z = 0; z < (column);z++){
        temp.push_back(kernel[i][z]);
}
this->kernel.push_back(temp);
temp.clear();
}
    }


vector<vector<double>> Channel::Getter_Kernel(){
    vector <vector <double>> help;
    vector <double> temp;
    for(int i = 0; i < (rows); i++){
    for(int z = 0; z < (column);z++){
        temp.push_back(this->kernel[i][z]);
    }
    help.push_back(temp);
    temp.clear();
    }
    return(help);   // Returns the Kernel.
}

void Channel::Clear(){
    vector <vector<double>> vector;
    vector.swap(this->kernel);
    this->rows = 0;
    this->column = 0;
    // this->kernel.shrink_to_fit();
}



void Channel::Set(vector<vector<double>> input){
    this->kernel.swap(input);
}


void Channel::Add(vector<vector<double> > input){
    vector<double> temp;
    for(int i = 0; i < (input.size()); i++){
    for(int z = 0; z < (input[0].size());z++){
        temp.push_back(input[i][z]);
}
this->kernel.push_back(temp);
temp.clear();
  }
    this->rows += input.size();  // Adds the number of added rows to the attribute.
    this->column = input[0].size();
   }

int Channel::Getter_Rows(){
    return(this->rows);
}

int Channel::Getter_Column(){
    return(this->column);
}
