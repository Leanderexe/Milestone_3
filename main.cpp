#include <QCoreApplication>
#include "neuron.h"
#include "layer.h"
#include "matrix.h"
#include "network.h"
#include "math.h"
#include "kernel.h"
#include "channel.h"


int main(int argc, char *argv[])
{
    /*
    Neuron *n = new Neuron(0.9);
    cout << "Val: " << n->getValue() << endl;
    cout << "actVal: " << n->getActValue() << endl;
    return 0;
    */
    /*
    matrix *m = new matrix(3, 2, true);
    m->print();
    */
    /*
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    network *nn = new network(topology);
    nn->setInput(input);
    nn->printNN();
    */


    /*
    layer *l = new layer(4);
    l->setVal(0, 1.2);
    l->setVal(1, 0.8);
    l->setVal(2, 2.0);
    l->setVal(3, 0.4);
    l->activationSoft().printLayer();
    */
    /*
    matrix *m = new matrix(3, 2, true);
    matrix *m2 = new matrix(2, 3, true);
    m->printM();
    cout << "-------------" << endl;
    m2->printM();
    cout << "-------------" << endl;
    m->mult(m, m2).printM();
    */
/*
    vector<double> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(1);
    std::string filename;
    layer* lay = new layer(7);
    cout << "filename:";
    cin >> filename;
    lay->Input(filename);
    vector<int> topology;
    cout << "Hello" << endl;
    lay->printLayer();
    topology.push_back(4);
    topology.push_back(2);
    topology.push_back(3);

    network* nn = new network(topology);
    nn->setInput(input);
    nn->feedForward();
    nn->printNN();
    cout << "======" << endl;
    nn->printOutput();
*/

    Kernel* kern1 = new Kernel(4 ,2);
    kern1->Weight();
    kern1->Print();
    Channel* channel1 = new Channel(3, "kern1");
    channel1->Get_rc(kern1->Getter_Rows(),kern1->Getter_Column());
    channel1->Get_Kernel(kern1->Getter_Kernel());
    channel1->LReLU();
    channel1->Print();
    kern1->Get_Kernel(channel1->Getter_Kernel());
    kern1->Print();
    channel1->Clear();
    channel1->Add({{1, 2}});
    channel1->Print();
    kern1->Get_Kernel(channel1->Getter_Kernel());
    kern1->Get_rc(channel1->Getter_Rows(),channel1->Getter_Column());
    kern1->Print();
    // kern1->Print();
    return 0;
}
