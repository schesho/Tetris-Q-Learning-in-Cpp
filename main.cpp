//
// Created by SrS on 07/12/16.
//

// emscripten JS + C++
// enlever magic numbers



#include <iostream>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"
using namespace std;



int main(){
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
    QBrain Q;

    Q.Train(1000,10000);

    Q.Game(100);
}