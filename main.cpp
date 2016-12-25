// emscripten JS + C++
using namespace std;
#include <iostream>
#include <vector>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"

#include "Neuron.h"
#include "NeuralNet.h"




int main(){
	//Dans les commentaires je vérifie juste que mes classes Neuron et NeuralNet fonctionnent correctement
	Neuron input1;
	Neuron input2;
	vector<float> input_weights1;
	vector<float> input_weights2;
	vector<float> input_weights3;

	input_weights1.push_back(0);
	input_weights1.push_back(1);

	input_weights2.push_back(1);
	input_weights2.push_back(0);

	input_weights3.push_back(1);
	input_weights3.push_back(1);

	Neuron output1(input_weights1);
	Neuron output2(input_weights2);
	Neuron output3(input_weights3);

	vector<Neuron> Layer1;//première couche composée de deux neurones 
	Layer1.push_back(input1);
	Layer1.push_back(input2);
	vector<Neuron> Layer2;//deuxème composée de trois
	Layer2.push_back(output1);
	Layer2.push_back(output2);
	Layer2.push_back(output3);

	vector< vector<Neuron> > Net;
	Net.push_back(Layer1);
	Net.push_back(Layer2);


	NeuralNet NNet(Net);

	vector<float> OutputValues=NNet.Result(input_weights3);
	//on regarde les resultats avec les deux neurones de la première couche actifs, ça donne bien en sortie 1,1,2
	cout<<OutputValues.size() << endl;
	for(int i = 0; i<OutputValues.size(); i++){
		cout << OutputValues[i] << endl;
	}


	cout<<"------------------------------------------------------------------------------------------------"<<endl;

    /*int number_training_games = 100;
    int number_training_pieces = 1000;
    int number_game_pieces = 1000;

    QBrain Q;

    Q.Train(number_training_games, number_training_pieces);

    Q.Game(number_game_pieces);*/
}