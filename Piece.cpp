#include "Piece.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;



// Constructor
// The piece is initialized randomly (but for the 4 spaces marked HERE)
// |0 0 0 0 x y| x, y, w & z are randomly assigned the value 0 or 1
// |0 0 0 0 w z|
Piece::Piece(){
    _shape=0;

    while(_shape==0){

        _shape = 1 * (rand()%2) + 2 * (rand()%2) + 64 * (rand()%2) + 128 * (rand()%2);
        //       1                2                2^6               2^7       for binary numeral system
    }
}

// Destructor
Piece::~Piece() {
}


// Rotate function will rotate the piece anticlockwise by using bitwise operations
// For example, one rotation gives :
// |0 0 0 0 0 0|----> |0 0 0 0 0 1|
// |0 0 0 0 1 1|----> |0 0 0 0 0 1|
// We use the & operator for bitwise operations

void Piece::Rotate(int nb_rotations){
    for(int i = 0; i<nb_rotations; i++){
        int new_shape = 0;

        if ((1&_shape) != 0){
            new_shape += 64;
        }

        if ((2&_shape) != 0){
            new_shape += 1;
        }

        if ((64&_shape) != 0){
            new_shape += 128;
        }

        if ((128&_shape) != 0){
            new_shape += 2;
        }

        _shape = new_shape;
    }
}


int Piece::GetShape(void) {
    return _shape;
}


// Displays the piece as a binary 2*6 matrix
void Piece::Display(){
    if ((128&_shape)!=0){
        cout<<"1 ";
    }
    else{
        cout<<"0 ";
    }

    if ((64&_shape)!=0){
        cout<<"1 ";
    }
    else{
        cout<<"0 ";
    }

    cout<<endl;

    if ((2&_shape)!=0){
        cout<<"1 ";
    }
    else{
        cout<<"0 ";
    }

    if ((1&_shape)!=0){
        cout<<"1 ";
    }
    else{
        cout<<"0 ";
    }

    cout<<endl;

}