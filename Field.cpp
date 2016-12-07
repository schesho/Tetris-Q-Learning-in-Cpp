//
// Created by Nicolas on 07/12/16.
//

#include "Field.h"
#include "Math.h"
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

Field::Field(){
    _state = 0;
    _height = 0;
}

Field::~Field() {
    // TODO Auto-generated destructor stub
}

int Field::GetHeight(){
    return _height;
}

int Field::GetState() {
    return _state;
}

void Field::NextHeight() {
    _height += 1;
}

void Field::Display(){
    int s = _state;

    cout << endl;

    for(int i=11; i>5;i--) {

        if (pow(2, i) <= s) {
            cout << "1 ";
            s -= pow(2, i);

        } else {
            cout << "0 ";
        }
    }

    cout << endl;

    for(int i=5; i > -1 ;i--){

        if (pow(2, i) <= s) {
            cout << "1 ";
            s -= pow(2, i);

        } else {
            cout << "0 ";
        }
    }
    cout << endl;

}

void Field::MakeMove(Piece &p, int rotation, int position) {
    // position < 6

    p.Rotate(rotation);

    int piece_shape = int(p.GetShape() * pow(2, position));


    if ((piece_shape&_state) == 0){
        _state = _state|piece_shape;
    } else if ((64*piece_shape&_state) == 0){
        _state = (_state | (64 * piece_shape)) / 32;
        _height += 1;

    } else {
        _state = piece_shape;
        _height += 2;
    }
}