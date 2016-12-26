//
// Created by Yoan Russac on 26/12/2016.
//

#ifndef TETRIS_RL_NEURAL2_H
#define TETRIS_RL_NEURAL2_H


class Neural{
    private:
        int _number_input;
        vector<float> _weight;

    public:
        Neural();
        Neural(vector<float> initial_weight);
        ~Neural();
        float Activation_function(vector<float> activated_input);

    }
    ;



#endif //TETRIS_RL_NEURAL2_H
