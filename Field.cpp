//
// Created by SrS on 07/12/16.
//

#include "Field.h"
#include <math.h>
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

void Field::MakeMove(Piece p, int rotation, int position) {
    // position < 5

    p.Rotate(rotation);
    int h = 0;
    int piece_shape = p.GetShape() <<position;//using bitwise operator << to move the piece


    if ((piece_shape&_state) == 0){
        _state = _state|piece_shape;

    } else if (((64*piece_shape)&_state) == 0){
        _state = _state | (64 * piece_shape);
        h += 1;

    } else {
        _state = piece_shape;
        h += 2;
        _height += 2;
    }


    if ((_state&(4095-63)) == (4095-63)){
        h-=1;
        _state -= (4095-63);
        _state += ((_state/4096)*64-4096*(_state/4096));
    }
    if ((_state&63) == 63){
        h -= 1;
        _state /= 64;
    }


    if(h == 1){
        _state /= 64;
        _height += 1;
    }


}