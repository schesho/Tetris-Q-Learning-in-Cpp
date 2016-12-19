//
// Created by SrS on 07/12/16.
// This file contains the main information for the field class
// The information of the state of the game will be gather here
//


// IMPORTATIONS
#include "Field.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


// Definition of a specific constructor
// State 0 represents the following disposition on the field | 0 0 0 0 0 0 |
//                                                           | 0 0 0 0 0 0 |
Field::Field(){
    _state = 0;
    _height = 0;
}

// Destructor
Field::~Field() {
    // TODO Auto-generated destructor stub
}


// To access to the height of the field
int Field::GetHeight(){
    return _height;
}

// To access to the state of the field (either an int, or the 2 rows, 6 columns matrix of the binary representation of this int)
int Field::GetState() {
    return _state;
}

// In some cases, we will have to play above the toplevel, therefore the height will be incremented
void Field::NextHeight() {
    _height += 1;
}


void Field::Display(){

    int s = _state;

    cout << endl;
    //Line feed

    // The following block will print the top level of the state
    for(int i=11; i>5;i--) {

        if (pow(2, i) <= s) {
            cout << "1 ";
            s -= pow(2, i);

        } else {
            cout << "0 ";
        }
    }

    cout << endl;

    // The following block will print the (top level-1) line of the state
    for(int i=5; i > -1 ;i--){
        if (pow(2, i) <= s) {
            cout << "1 ";
            s -= pow(2, i);

        } else {
            cout << "0 ";
        }
    }
//    cout << endl;
}


void Field::MakeMove(Piece p, int rotation, int position) {
    // Recall: a state is either an in a matrix with 2 rows and 6 columns, therefore position respect:   0<=position<=5

    p.Rotate(rotation);
    int h = 0;
    int piece_shape = p.GetShape();


    //if after the rotation the piece is present only on the second level we push it on the bottom
    // Newton's rule for the piece (could'nt lie on nothing)
    if(((piece_shape&1)+(piece_shape&2))==0){
        piece_shape/=64;
    }
    piece_shape= piece_shape<<position;
    //leftshift operator is the equivalent of moving all the bits of a number a specified number of places to the left

    // when there is a space on the field for the piece
    if ((piece_shape&_state) == 0){
        _state = _state|piece_shape;
    // if there is no no space on the bottom line (we have to add another line)
    } else if (((64*piece_shape)&_state) == 0){
        _state = _state | (64 * piece_shape);
        h += 1;

    } else {
        // if we have to add 2 lines, then given that the state only represents the two top_level lines the new state will be the piece
        _state = piece_shape;
        h += 2;
        _height += 2;
    }

    //removing full lines:
    if ((_state&(4095-63)) == (4095-63)){
        h-=1;
        _state -= (4095-63); // erase de top_level line of the state (because |1 1 1 1 1 1|)
        _state += ((_state/4096)*64-4096*(_state/4096));
    }
    if ((_state&63) == 63){ // comparison with the first  line when full) |0 0 0 0 0 0|
                                        //                                |1 1 1 1 1 1|
        h -= 1;
        _state /= 64;
    }

    //if h>1 the first level is lost
    if(h == 1){
        _state /= 64;
        _height += 1;
    }


}