#include "layer.h"
#include "neuron.h"
#include "math.h"
#include <iostream>
#include <fstream>

// (1c)
//creates a layer which defaults to the sigmoid function.
layer::layer(int size){
    this->size = size;
    for(int i = 0; i < size; i++){
        Neuron *n = new Neuron(0.00, "sigmoid");
        neurons.push_back(n);
    }
}

void layer::setVal(int i, double v){
    neurons.at(i)->setValue(v);
}



// (1b)
// creates a new layer *l1 and fills it with the values
// corresponding to the softmax equation
layer layer::activationSoft(){
    layer* l1 = new layer(size);
    double fullNSum = 0.00;  // placeholder for sum
    for (int i = 0; i < neurons.size(); i++){
        fullNSum = fullNSum + exp(neurons.at(i)->getValue());
    }
    for (int j = 0; j < neurons.size(); j++){
        l1->setVal(j, (exp(neurons.at(j)->getValue()) / fullNSum));
    }
    return *l1;
}



void layer::printLayer(){
    for(int i = 0; i < size; i++){
        cout << neurons.at(i)->getValue() << endl;
    }
}

// borrowed
matrix *layer::mfyV(){
    matrix* m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < neurons.size(); i++){
        m->setValue(0, i, neurons.at(i)->getValue());
    }

    return m;
}

// borrowed
matrix *layer::mfyAV(){
    matrix* m = new matrix(1, neurons.size(), false);
    for (int i = 0; i < neurons.size(); i++){
        m->setValue(0, i, neurons.at(i)->getActValue());
    }

    return m;
}


layer* layer::Input(std::string filename){
std::string num_neuron;
std::vector <int> help_neuron;
ifstream file;
file.open(filename);
if (!file) {
    cerr << "Die Datei konnte nicht gefunden werden." << endl;
}
while(file >> num_neuron){
    for (const auto digit : (num_neuron)) {  // Push_backs each character one after an other into the vector.
        help_neuron.push_back(digit - '0');
    }
}
        int size = help_neuron.size();
        layer* l2 = new layer(size);
        for (int i = 0; i < size; i++){
            l2->setVal(i, help_neuron.at(i));
        }
        return l2;

}

