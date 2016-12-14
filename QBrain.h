//
// Created by Nicolas on 14/12/16.
//

#ifndef TETRIS_RL_QTABLE_H
#define TETRIS_RL_QTABLE_H


#include "BestActionAndUtility.h"
#include "Field.h"
#include "Piece.h"

class QBrain {
private:
    float* _pQ;
    float _alpha;
    float _gamma;
    int _reward_coefficient;

public:
    QBrain();
    QBrain(float, float, int);
    ~QBrain();
    float* GetQ();
    float GetAlpha();
    float GetGamma();
    void Update(BestActionAndUtility, Field, Piece);
    BestActionAndUtility ChooseBestAction(Field, Piece);
    void Train(int, int);
    int Game(int);
};


#endif //TETRIS_RL_QTABLE_H