//
// This file contains the main information for the field class
// The information on the state of the game will be gathered here
//


#ifndef TETRIS_RL_FIELD_H
#define TETRIS_RL_FIELD_H

#include "Piece.h"

class Field {
private:
    // _state is an int between 0 and 4095, his structure completely determines the state of the game
    // it is defined exactly like a _shape in the Piece class
    int _state;
    // current height of the game (see our definition of the game)
    int _height;

public:
    Field();
    virtual ~Field();
    int GetHeight(void);
    int GetState(void);
    void NextHeight();
    void MakeMove(Piece p, int rotation, int position);
    void Display(void);
}
;


#endif //TETRIS_RL_FIELD2_H
