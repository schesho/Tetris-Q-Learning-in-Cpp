// emscripten JS + C++

#include <iostream>
using namespace std;
#include <vector>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"
#include "Neuron.h"
#include "Neural_Network.h"


int main(){
	//Dans les commentaires je vérifie juste que mes classes Neuron et NeuralNet fonctionnent correctement
	Neuron input1;
	Neuron input2;
	vector<float> input_weights1;
	vector<float> input_weights2;
	vector<float> input_weights3;
	// weigths for the first layre
	input_weights1.push_back(0);
	input_weights1.push_back(1);

	input_weights2.push_back(1);
	input_weights2.push_back(0);

	input_weights3.push_back(1);
	input_weights3.push_back(1);

	Neuron output1(input_weights1);
	Neuron output2(input_weights2);
	Neuron output3(input_weights3);

	vector<float> input_weights1_layer2;
	input_weights1_layer2.push_back(0.2);
	input_weights1_layer2.push_back(0);
	input_weights1_layer2.push_back(0.8);

	Neuron output1_layer2(input_weights1_layer2);


    vector<Neuron> Layer1;//première couche composée de deux neurones
	Layer1.push_back(input1);
	Layer1.push_back(input2);
	vector<Neuron> Layer2;//deuxème composée de trois
	Layer2.push_back(output1);
	Layer2.push_back(output2);
	Layer2.push_back(output3);

	vector<Neuron> Layer3;// troisième couche qui sera composée d'un seul neurone
	Layer3.push_back(output1_layer2);

	vector< vector<Neuron> > Net;
	Net.push_back(Layer1);
	Net.push_back(Layer2);
	Net.push_back(Layer3);

	// define the neural Network
	Neural_Network NNet(Net);

	vector<vector<float>> OutputValues = NNet.all_activations(input_weights3);
	//on regarde les resultats avec les deux neurones de la première couche actifs, ça donne bien en sortie 1,1,2
	cout<<"Number of layers "<<NNet.get_number_layer() << endl;

	cout<<"Valeur sortant du réseau de neurones"<< endl;
	vector<float> final_output;
	final_output = OutputValues[NNet.get_number_layer()-1];
	for(int i = 0; i< final_output.size();i++){
		cout<<final_output[i]<<endl;
	}
	cout<<"Valeur en entrée du réseau de neurones"<< endl;
	vector<float> initial_input;
	initial_input = OutputValues[0];
	for(int i = 0; i< initial_input.size();i++){
		cout<<initial_input[i]<<endl;
	}

	cout<<"------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Avoir tous les poids d'un neurone"<<endl;
	int nombre_poids = output1_layer2.get_weight().size();
	for (int i = 0; i<nombre_poids;i++){
		cout<< output1_layer2.get_weight()[i]<<endl;
	}

	cout<< "Avoir les poids d'un neurone à partir du réseau de neurone et du numéro d'un layer"<<endl;
	vector <float> poids_neurones_1_layer_2=NNet.get_Layers()[2][0].get_weight();
	for (int i = 0; i<poids_neurones_1_layer_2.size();i++){
		cout<< poids_neurones_1_layer_2[i]<<endl;
	}
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	vector<float> output_wanted;
	output_wanted.push_back(1.75);
	vector<vector<float>> all_delta = NNet.Backpropagation(output_wanted,final_output);







    /*int number_training_games = 100;
    int number_training_pieces = 1000;
    int number_game_pieces = 1000;

    QBrain Q;

    Q.Train(number_training_games, number_training_pieces);

    Q.Game(number_game_pieces);*/
}