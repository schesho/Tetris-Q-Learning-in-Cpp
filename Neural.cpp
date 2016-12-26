//
// Created by Yoan Russac on 26/12/2016.
//

#include <iostream>
using namespace std;
#include <vector>
#include "Neural.h"





// constructor
Neural::Neural(){}


// Destructor
Neural::~Neural() {
    // TODO Auto-generated destructor stub
}


Neural::Neural(vector<float> weights_input){
    _number_input = weights_input.size();
    _weight = weights_input;
}


float Neural::Activation_function(vector<float> activated_input){
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