
#ifndef NEURON_H
#define NEURON_H

class Neuron{
	private:
		int _n_input;//number of inputs to which this neuron is connected
		vector<float> _weights_input;
	public:
		Neuron();
		Neuron(vector<float> weights_input);

		virtual ~Neuron();
		float Activation_function(vector<float> activated_input);

}
;
#endif