//
// Created by SrS on 07/12/16.
//

// emscripten JS + C++
// enlever magic numbers



#include <iostream>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "Piece.h"
#include <vector>
#include <limits>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;


BestActionAndUtility ChooseBestAction(Field& current_field, Piece& current_piece, const float* pQ, float gamma) {

    BestActionAndUtility best_utility_and_action = BestActionAndUtility();

    int initial_height = current_field.GetHeight();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            Field f = current_field;
            Piece p = current_piece;
            f.MakeMove(p, i, j);
            
            int reward = -100 * (f.GetHeight() - initial_height);

            float u = pQ[f.GetState()];

            if ((reward + gamma * u) >= best_utility_and_action.GetUtility()) {
                best_utility_and_action.SetUtility(reward + gamma * u);
                best_utility_and_action.SetBestAction1(i);
                best_utility_and_action.SetBestAction2(j);
            }
        }
    }
    return best_utility_and_action;
}

void UpdateQTable(float* pQ, BestActionAndUtility& best_utility_and_action, Field f, Piece p, const float& alpha,
                  const float& gamma){

    int state1 = f.GetState();

    int h1 = f.GetHeight();

    f.MakeMove(p, best_utility_and_action.GetBestAction1(), best_utility_and_action.GetBestAction2());

    int state2 = f.GetState();

    int h2 = f.GetHeight();

    pQ[state1] = (1 - alpha) * pQ[state1] + alpha * (-100 * (h2-h1) + gamma * pQ[state2]);
}

void Game_training(float* pQ, int number_of_pieces, float alpha, float gamma){

    Field f;

    for (int i=0 ; i<number_of_pieces ; i++){

        Piece p;

        // cout<<"piece: "<<endl;
        //p.Display();
        BestActionAndUtility a = ChooseBestAction(f, p, pQ, gamma);

		// cout<<endl;
        // cout<<pQ[f.GetState()]<<endl;

        UpdateQTable(pQ, a, f, p, alpha, gamma);

        // cout<<pQ[f.GetState()]<<endl;
        f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());


        //f.Display();

        // cout << f.GetHeight() << endl;
    }
    cout<<"hauteur "<<f.GetHeight()<<endl;
    cout<<"position finale :" << endl;
    f.Display();
}

void Game_display(float* pQ,int number_of_pieces){
	Field f;

    for (int i=0 ; i<number_of_pieces ; i++){

	    Piece p;

	    cout << "piece: " << endl;

        p.Display();

	    BestActionAndUtility a = ChooseBestAction(f, p, pQ,0);

		//cout<<endl;

	    //cout<<pQ[f.GetState()]<<endl;

	    f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());

        f.Display();

        //delete[] a;

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
    for (int j = 0;j < 100 ;j++){
    	cout << "Jeu numéro:" << j << endl;

      Game_training(pQ, 10000, 0.02, 0.8);
  	}

    //Game_display(pQ, 100);
  	delete[] pQ;

  	//Game_display(pQ,100);
}