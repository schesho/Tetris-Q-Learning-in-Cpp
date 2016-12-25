
#ifndef NEURALNET_H
#define NEURALNET_H
class NeuralNet{
	private:
		int _nLayers;
		vector< vector<Neuron> > _Layers;

		vector<float> FromOneLayerToAnother(int& layer_number,vector<float>& neurons_values);
	public:
		NeuralNet();
		NeuralNet(vector< vector<Neuron> > Layers);
		virtual ~NeuralNet();

		vector<float> Result(vector<float>& Input);
}
;


#endif