//
// Created by Yoan Russac on 26/12/2016.
//

#include <iostream>
using namespace std;
#include <vector>
#include "Neuron.h"





// constructor
Neuron::Neuron(){}


// Destructor
Neuron::~Neuron() {
    // TODO Auto-generated destructor stub
}


Neuron::Neuron(vector<float> weights_input){
    _number_input = weights_input.size();
    _weight = weights_input;
}


vector <float> Neuron::get_weight(){
    return _weight;



}


float Neuron::Activation_function(vector<float> activated_input){
    //Value that neuron takes depending on the values takes by neurons of the previous layer
    float sum = 0;
    int number_input = activated_input.size();
    for(int i = 0; i < number_input; i++){
        sum += activated_input[i]*_weight[i];
    }
    if (sum > 0){
        return sum;
    }
    else{
        return 0;
    }

}