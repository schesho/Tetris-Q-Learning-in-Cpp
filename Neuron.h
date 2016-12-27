//
// Created by Yoan Russac on 26/12/2016.
//

#ifndef TETRIS_RL_NEURAL2_H
#define TETRIS_RL_NEURAL2_H


class Neuron{
    private:
        int _number_input;
        vector<float> _weight;

    public:
        Neuron();
        Neuron(vector<float> initial_weight);
        ~Neuron();
        float Activation_function(vector<float> activated_input);
        vector<float> get_weight(void);


    }
    ;



#endif //TETRIS_RL_NEURAL2_H
