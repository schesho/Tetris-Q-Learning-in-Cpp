
#include <vector>
using namespace std;
#include "Neuron.h"
#include "NeuralNet.h"

NeuralNet::NeuralNet(){

}

NeuralNet::~NeuralNet() {

}

NeuralNet::NeuralNet(vector< vector<Neuron> > Layers){
	_Layers=Layers;
	_nLayers=Layers.size();
}

vector<float> NeuralNet::FromOneLayerToAnother(int& layer_number,vector<float>& neuron_values){
	//returns a vector containing values taken by neurons of the next to layer_number layer
	vector<Neuron> FirstLayer=_Layers[layer_number];
	vector<Neuron> NextLayer=_Layers[layer_number+1];
	int NextLayerSize=NextLayer.size();

	vector<float> next_layer_neuron_values;

	for (int i = 0 ; i < NextLayerSize; i++){
		next_layer_neuron_values.push_back(NextLayer[i].Activation_function(neuron_values));
	}
	return next_layer_neuron_values;
}

vector<float> NeuralNet::Result(vector<float>& Input){
	//Returning an output of the NeuralNetwork function given an input
	vector<float> Output;
	for(int i = 0; i < _nLayers-1; i++){
		Input=FromOneLayerToAnother(i,Input);
	}
	return Input;
}