//
// Created by Yoan Russac on 26/12/2016.
//

#ifndef TETRIS_RL_NEURAL_NETWORK_H
#define TETRIS_RL_NEURAL_NETWORK_H


class Neural_Network {
private:
    int _nLayers;
    vector<vector<Neural>> _Layers;

    vector<float> Propagation(int& layer_number,vector<float>& neurons_values);
public:
    Neural_Network();
    Neural_Network(vector<vector<Neural>> Layers);
    ~Neural_Network();
    vector<float> Result(vector<float>& Input);
};


#endif //TETRIS_RL_NEURAL_NETWORK_H
