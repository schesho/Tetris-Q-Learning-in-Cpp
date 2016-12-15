// emscripten JS + C++

#include <iostream>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"
using namespace std;



int main(){

	cout<<"------------------------------------------------------------------------------------------------"<<endl;

    int number_training_games = 1000;
    int number_training_pieces = 10000;
    int number_game_pieces = 10000;

    QBrain Q;

    Q.Train(number_training_games, number_training_pieces);

    Q.Game(number_game_pieces);
}