//
// Created by SrS on 07/12/16.
// This file contains the main information for the piece class
//


#ifndef TETRIS_RL_PIECE_H
#define TETRIS_RL_PIECE_H


class Piece {
private:
    int _shape;
public:
    Piece();
    ~Piece();
    // Rotation anti-horaire
    void Rotate(int nb_rotations);
    int GetShape(void);
    void Display();
    // int GetNumberOfPossibleRotation(void);

};

#endif //TETRIS_RL_PIECE2_H
