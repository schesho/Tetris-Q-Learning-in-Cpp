//
// Created by Yoan Russac on 26/12/2016.
//

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include "Neuron.h"
#include "Neural_Network.h"


Neural_Network::Neural_Network(){

}

Neural_Network::~Neural_Network(){

}

Neural_Network::Neural_Network(vector< vector<Neuron> > Layers){
    _Layers = Layers;
    _nLayers = Layers.size();
}

int Neural_Network::get_number_layer() {
    return _nLayers;
}


vector<vector<Neuron>> Neural_Network::get_Layers() {
    return _Layers;
}

vector<float> Neural_Network::Propagation(int& layer_number,vector<float>& neuron_values){
    //returns a vector containing values taken by neurons of the next to layer_number layer
    vector<Neuron> FirstLayer = _Layers[layer_number];
    vector<Neuron> NextLayer = _Layers[layer_number+1];
    int NextLayerSize = NextLayer.size();

    vector<float> next_layer_neuron_values;

    for (int i  = 0 ; i < NextLayerSize; i++){
        next_layer_neuron_values.push_back(NextLayer[i].Activation_function(neuron_values));
    }
    return next_layer_neuron_values;
}

vector<vector<float>> Neural_Network::all_activations(vector<float>& Input){
    //Returning an output of the NeuralNetwork function given an input
    vector<vector<float>> intermediary_activation;
    intermediary_activation.push_back(Input);
    for(int i  = 0; i < _nLayers-1; i++) {
        Input  = Propagation(i, Input);
        intermediary_activation.push_back(Input);
    }
    return intermediary_activation;
}

vector<float> Neural_Network::One_Step_Backpropagation(int& layer_number, vector<float> &delta) {
    vector<float> Previous_delta;
    vector<Neuron> FirstLayer  = _Layers[layer_number-1];
    vector<Neuron> NextLayer  = _Layers[layer_number];
    int FirstLayerSize  = FirstLayer.size();
    cout<< "FirstLayerSize "<<FirstLayerSize <<endl;

    int NextLayerSize  = NextLayer.size();
    cout<< "Nextlayersize "<<NextLayerSize <<endl;
    float delta_i = 0;
    for (int i = 0;i<FirstLayerSize;i++) {
        for (int j  = 0; j < NextLayerSize; j++) {
            vector<float>  neuron_weight = NextLayer[j].get_weight();
            cout<<"poids neurone "<<neuron_weight[i]<<endl;
            cout<<"delta "<<delta[j]<<endl;
            delta_i = delta_i+ neuron_weight[i]*delta[j];

        }
        Previous_delta.push_back(delta_i);
        cout<<"Changement de neurone dans la même couche"<<endl;
    }
    cout<< "Fin de l'étape de backpropagation----------"<<endl;
    return Previous_delta;
}


vector<vector<float>> Neural_Network::Backpropagation(vector<float>& output_wanted,vector<float> real_output) {
    vector<vector<float>> all_delta;
    vector<float> initial_delta;
    int initial_delta_size  = _Layers[_nLayers - 1].size();
    for (int i  = 0; i < initial_delta_size; i++) {
        cout<<"valeur d'initialisation pour delta: "<<real_output[i] - output_wanted[i]<<endl;
        initial_delta.push_back(real_output[i] - output_wanted[i]);
    }
    all_delta.push_back(initial_delta);
    for (int i  = _nLayers - 1; i > 0; i--) {
        initial_delta  = One_Step_Backpropagation(i, initial_delta);
        all_delta.push_back(initial_delta);
    }
    reverse(all_delta.begin(),all_delta.end());
    return all_delta;
}

