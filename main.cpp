#include <iostream>
using namespace std;
#include <vector>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"
#include "Neuron.h"
#include "Neural_Network.h"


int main(){

	int number_training_games = 100;
    int number_training_pieces = 10000;
    int number_game_pieces = 10000;

	// We instanciate our Q-learning model
    QBrain Q;

	// We train our Q-learning model
	Q.Train(number_training_games, number_training_pieces);

	// We test our Q-learning model
	// The game is displayed step by step
    Q.Game(number_game_pieces);

	return 0;


}