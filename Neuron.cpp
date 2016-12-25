#include <vector>
using namespace std;
#include "Neuron.h"


Neuron::Neuron(){
}
Neuron::~Neuron() {
    // TODO Auto-generated destructor stub
}

Neuron::Neuron(vector<float> weights_input){
	_n_input = weights_input.size();
	_weights_input = weights_input;
}
float Neuron::Activation_function(vector<float> activated_input){
	//Value that neuron takes depending on the values takes by neurons of the previous layer
	float sum = 0;
	int n_input = activated_input.size();
	for(int i = 0; i < n_input; i++){
		sum += activated_input[i]*_weights_input[i];
	}
	if (sum > 0){
		return sum;
	}
	else{
		return 0;
	}

}