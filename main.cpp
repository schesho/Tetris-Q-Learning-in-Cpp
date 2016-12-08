//
// Created by SrS on 07/12/16.
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


float* ChooseBestAction(Field& current_field, Piece& current_piece, const float* pQ, float gamma) {
    // Attention aux fuites mémoire

    float* best_utility_and_action = new float[3];
    best_utility_and_action[0] = -std::numeric_limits<float>::max();
    best_utility_and_action[1] = 0;
    best_utility_and_action[2] = 0;
    int initial_height = current_field.GetHeight();



    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            Field f = current_field;
            Piece p = current_piece;
            f.MakeMove(p, i, j);
            
            int reward = -100 * (f.GetHeight() - initial_height);
            float u = pQ[f.GetState()];

            if ((reward +gamma * u) >= best_utility_and_action[0]) {
                best_utility_and_action[0] = reward +gamma * u;
                best_utility_and_action[1] = i;
                best_utility_and_action[2] = j;
            }
        }
    }
    return best_utility_and_action;
}

void UpdateQTable(float* pQ,float* best_utility_and_action,Field f, Piece p, float alpha,float gamma){

    int state1 = f.GetState();

    int h1 = f.GetHeight();

    f.MakeMove(p, int(best_utility_and_action[1]), int(best_utility_and_action[2]));

    int state2 = f.GetState();

    int h2 = f.GetHeight();

    pQ[state1] = (1 - alpha) * pQ[state1] + alpha * (-100 * (h2-h1) + gamma * pQ[state2]);
}

void Game_training(float* pQ, int number_of_pieces, float alpha, float gamma){

    Field f;

    for (int i=0 ; i<number_of_pieces ; i++){

        Piece p;

        //cout<<"piece: "<<endl;
        //p.Display();
        float *a = ChooseBestAction(f, p, pQ, gamma);

		//cout<<endl;
        //cout<<pQ[f.GetState()]<<endl;

        UpdateQTable(pQ, a, f, p, alpha, gamma);

        //cout<<pQ[f.GetState()]<<endl;
        f.MakeMove(p, a[1], a[2]);

        //f.Display();

        //cout << f.GetHeight() << endl;
    }
    cout<<"hauteur "<<f.GetHeight()<<endl;
    cout<<"position finale :"<<endl;
    f.Display();
}

void Game_display(float* pQ,int number_of_pieces){
	Field f;
    for (int i=0 ; i<number_of_pieces ; i++){

	    Piece p;

	    cout<<"piece: "<<endl;
	    p.Display();
	    float *a = ChooseBestAction(f, p, pQ,0);

		//cout<<endl;
	    //cout<<pQ[f.GetState()]<<endl;

	    //cout<<pQ[f.GetState()]<<endl;
	    f.MakeMove(p, a[1], a[2]);

	    f.Display();

	    cout << f.GetHeight() << endl;
    }
    cout << "hauteur " << f.GetHeight() << endl;
    cout << "position finale :" << endl;
    f.Display();
}


int main(){
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
    float* pQ = new float[4096];
    for(int i=0; i<4096; i++){
        pQ[i] = 0;
    }
    for (int j = 0;j < 400;j++){
    	cout << "jeux numéro:" << j << endl;

      Game_training(pQ, 10000, 0.02, 0.8);
  	}

  	//Game_display(pQ,100);
}