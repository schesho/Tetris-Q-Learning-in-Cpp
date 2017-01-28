// A piece object will be represented as a board with 0's and 1's (2 rows, 6 columns)
// This is an example of piece      |000001|
//                                  |000011|
// We will use a mathematical trick to represent the pieces :
// Each 2*6 binary matrix is associated with the (unique) int which has the first and the second row of the matrix
// as binary decomposition
// For example, the matrix given right before is associated with the int 1*1 + 2*1 + 64*1 = 67
// This representation has the advantage of speeding up the computations needed

#ifndef TETRIS_RL_PIECE_H
#define TETRIS_RL_PIECE_H


class Piece {
private:
    int _shape;
public:
    Piece();
    ~Piece();
    void Rotate(int nb_rotations);
    int GetShape(void);
    void Display();

};

#endif //TETRIS_RL_PIECE2_H
