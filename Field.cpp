//
// Created by Nicolas on 07/12/16.
//

#include "Field.h"

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
