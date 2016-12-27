//
// Created by Yoan Russac on 26/12/2016.
//

#ifndef TETRIS_RL_NEURAL_NETWORK_H
#define TETRIS_RL_NEURAL_NETWORK_H


class Neural_Network {
private:
    int _nLayers;
    vector<vector<Neuron>> _Layers;

    vector<float> Propagation(int& layer_number,vector<float>& neurons_values);
public:
    Neural_Network();
    Neural_Network(vector<vector<Neuron>> Layers);
    ~Neural_Network();
    int get_number_layer(void);
    vector<vector<Neuron>> get_Layers(void);
    vector<vector<float>> all_activations(vector<float>& Input);
    vector<float> One_Step_Backpropagation(int& layer_number,vector<float>& weight);
    vector<vector<float>> Backpropagation(vector<float>& output_wanted,vector<float> real_output);
};


#endif //TETRIS_RL_NEURAL_NETWORK_H
