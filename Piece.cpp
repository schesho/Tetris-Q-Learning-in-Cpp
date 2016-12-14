//
// Created by SrS on 07/12/16.
// This file contains the main information for the piece class
// A piece object will be represented as a board with 0 and 1 (2 rows, 6 columns)
// This is an example of piece      |000001|
//                                  |000011|
// We will also use a mathematical trick: the bijection between the piece as matrix ( Pas vraiment une matrice )
// and the int represented by this matrix (into 0 and 2^11-1)



// FILE IMPORTATIONS
#include "Piece.h"
// OTHER IMPORTATIONS
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;



// Specific constructor
// The piece is initialized randomly (but for the 4 spaces marked HERE)
// |0 0 0 0 HERE HERE| and HERE randomly equals 0 or 1
// |0 0 0 0 HERE HERE|

Piece::Piece(){
    _shape=0;
while(_shape==0){
    _shape = 1 * (rand()%2) + 2 * (rand()%2) + 64 * (rand()%2) + 128 * (rand()%2);
    //       1                2                2^6               2^7       for decomposition in base 2
    }
}

// Destructor
Piece::~Piece() {
    // TODO Auto-generated destructor stub
}


// Rotate function will Rotate the piece by using bitwise operation
// Example: |0 0 0 0 0 0|---- after 1 rotation will become |0 0 0 0 0 1|
//          |0 0 0 0 1 1|----                              |0 0 0 0 0 1|
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