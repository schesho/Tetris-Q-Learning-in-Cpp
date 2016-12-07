//
// Created by Nicolas on 07/12/16.
//

#include <iostream>
#include "Field.h"
#include "Piece.h"
#include <vector>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    Field f = Field();

    f.Display();

    Piece p = Piece();

    f.MakeMove(p, 1, 2);

    f.Display();
}