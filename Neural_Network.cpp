//
// Created by Yoan Russac on 26/12/2016.
//

#include <iostream>
using namespace std;
#include <vector>
#include "Neural.h"
#include "Neural_Network.h"


Neural_Network::Neural_Network(){

}

Neural_Network::~Neural_Network(){

}

Neural_Network::Neural_Network(vector< vector<Neural> > Layers){
    _Layers=Layers;
    _nLayers=Layers.size();
}

vector<float> Neural_Network::Propagation(int& layer_number,vector<float>& neuron_values){
    //returns a vector containing values taken by neurons of the next to layer_number layer
    vector<Neural> FirstLayer=_Layers[layer_number];
    vector<Neural> NextLayer=_Layers[layer_number+1];
    int NextLayerSize=NextLayer.size();

    vector<float> next_layer_neuron_values;

    for (int i = 0 ; i < NextLayerSize; i++){
        next_layer_neuron_values.push_back(NextLayer[i].Activation_function(neuron_values));
    }
    return next_layer_neuron_values;
}

vector<float> Neural_Network::Result(vector<float>& Input){
    //Returning an output of the NeuralNetwork function given an input
    for(int i = 0; i < _nLayers-1; i++){
        Input=Propagation(i,Input);
    }
    return Input;
}