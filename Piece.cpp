//
// Created by SrS on 07/12/16.
//


#include "Piece.h"

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

Piece::Piece(){
    _shape=0;
while(_shape==0){
    _shape = 1 * (rand()%2) + 2 * (rand()%2) + 64 * (rand()%2) + 128 * (rand()%2);
    }
}

Piece::~Piece() {
    // TODO Auto-generated destructor stub
}

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