//
// Created by SrS on 07/12/16.
// This file contains the main information for the field class
// The information of the state of the game will be gather here
//


#ifndef TETRIS_RL_FIELD_H
#define TETRIS_RL_FIELD_H

#include "Piece.h"

class Field {
private:
    // _state est un int compris entre 0 et 4095, son écriture représente l'état du jeu
    int _state;
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
