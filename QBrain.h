// This class will update our decision matrix, the Q table
// We will train the model on number_of_games games.
// A game is defined like a succession of number_of_piece piece to play.
//

#ifndef TETRIS_RL_QTABLE_H
#define TETRIS_RL_QTABLE_H


#include "BestActionAndUtility.h"
#include "Field.h"
#include "Piece.h"

class QBrain {
private:
    const int _number_of_possible_states = 4096;
    const int _position_extent = 4; // the piece could be added between position 0 and 4 (because a piece is a 2*2 block)
    const int _number_of_rotation = 3;
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
    void Game(int);
};


#endif //TETRIS_RL_QTABLE_H