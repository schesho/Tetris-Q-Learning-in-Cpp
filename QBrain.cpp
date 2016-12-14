//
// Created by Nicolas on 14/12/16.
//

#include "QBrain.h"
#include <iostream>
using namespace std;

QBrain::QBrain() {
    _alpha = 0.02;
    _gamma = 0.8;
    _reward_coefficient = 100;
    _pQ = new float[4096];
    for(int i=0; i<4096; i++){
        _pQ[i] = 0;
    }
}

QBrain::QBrain(float alpha, float gamma, int reward_coefficient) {
    _alpha = alpha;
    _gamma = gamma;
    _reward_coefficient = reward_coefficient;
    _pQ = new float[4096];
    for(int i=0; i<4096; i++){
        _pQ[i] = 0;
    }
}

QBrain::~QBrain() {
    // Destructor
}

float QBrain::GetAlpha() {
    return _alpha;
}


float QBrain::GetGamma() {
    return _gamma;
}

float* QBrain::GetQ() {
    return _pQ;
}



void QBrain::Update(BestActionAndUtility best_action_and_utility, Field f, Piece p) {

    int state1 = f.GetState();

    int h1 = f.GetHeight();

    f.MakeMove(p, best_action_and_utility.GetBestAction1(), best_action_and_utility.GetBestAction2());

    int state2 = f.GetState();

    int h2 = f.GetHeight();

    _pQ[state1] = (1 - _alpha) * _pQ[state1] + _alpha * (-100 * (h2-h1) + _gamma * _pQ[state2]);

}

BestActionAndUtility QBrain::ChooseBestAction(Field current_field, Piece current_piece) {

    BestActionAndUtility best_utility_and_action;

    int initial_height = current_field.GetHeight();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            Field f = current_field;
            Piece p = current_piece;
            f.MakeMove(p, i, j);

            int reward = -_reward_coefficient * (f.GetHeight() - initial_height);

            float u = _pQ[f.GetState()];

            if ((reward + _gamma * u) >= best_utility_and_action.GetUtility()) {
                best_utility_and_action.SetUtility(reward + _gamma * u);
                best_utility_and_action.SetBestAction1(i);
                best_utility_and_action.SetBestAction2(j);
            }
        }
    }
    return best_utility_and_action;
}


void QBrain::Train(int number_of_games, int number_of_pieces) {

        Field f;

        for (int i=0 ; i<number_of_pieces ; i++){

            Piece p;

            // cout<<"piece: "<<endl;
            //p.Display();
            BestActionAndUtility a = ChooseBestAction(f, p);

            // cout<<endl;
            // cout<<pQ[f.GetState()]<<endl;

            Update(a, f, p);

            // cout<<pQ[f.GetState()]<<endl;
            f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());


            //f.Display();

            // cout << f.GetHeight() << endl;
        }
        //cout<<"hauteur "<<f.GetHeight()<<endl;
        //cout<<"position finale :" << endl;
        //f.Display();
    }

int QBrain::Game(int number_of_pieces) {
        Field f;

        for (int i=0 ; i<number_of_pieces ; i++){

            Piece p;
            cout << "piece: " << endl;
            p.Display();

            BestActionAndUtility a = ChooseBestAction(f, p);

            //cout<<endl;

            // cout<<_pQ[f.GetState()]<<endl;

            f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());

            f.Display();

            //delete[] a;

            cout << f.GetHeight() << endl;
            cout << endl;
        }
        cout << "Final height: " << f.GetHeight() << endl;
    }

