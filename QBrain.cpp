#include "QBrain.h"
#include <iostream>
using namespace std;

QBrain::QBrain() {
    _alpha = 0.2;
    _gamma = 0.8;
    _reward_coefficient = 100;
    _pQ = new float[_number_of_possible_states];
    for(int i=0; i<_number_of_possible_states; i++){
        _pQ[i] = 0;
    }
}

QBrain::QBrain(float alpha, float gamma, int reward_coefficient) {
    _alpha = alpha;
    _gamma = gamma;
    _reward_coefficient = reward_coefficient;
    _pQ = new float[_number_of_possible_states];
    for(int i=0; i<_number_of_possible_states; i++){
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
    // we make the move given the piece p and the current state of the field f and given our actual decision policy best_action_and_utility

    int state2 = f.GetState();
    int h2 = f.GetHeight();
    // new state of the game after adding the piece p
    _pQ[state1] = (1 - _alpha) * _pQ[state1] + _alpha * (-100 * (h2-h1) + _gamma * _pQ[state2]);

}

BestActionAndUtility QBrain::ChooseBestAction(Field current_field, Piece current_piece) {

    BestActionAndUtility best_utility_and_action;

    int initial_height = current_field.GetHeight();

    for (int i = 0; i <= _number_of_rotation; i++) {
        // i corresponds to the number of rotation for the current_piece
        for (int j = 0; j <= _position_extent; j++) {
            // j correponds to the position where we try to insert the piece
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
    // we will find the best utility and actions given the current state of the field and the current piece (by examining every possibilities)
    return best_utility_and_action;
}

// The following function will allow us to train our model by updating several times our Q table
// It is the training part of the reinforcement learning
void QBrain::Train(int number_of_games, int number_of_pieces) {

    for (int j = 0; j < number_of_games; j++) {
        Field f;
        // The usual definition of the field (height = 0 and state = 0)
        for (int i = 0; i < number_of_pieces; i++){

            Piece p;

            BestActionAndUtility a = ChooseBestAction(f, p);

            // cout<<pQ[f.GetState()]<<endl;

            Update(a, f, p);

            // cout<<pQ[f.GetState()]<<endl;
            f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());


            //f.Display();

            // cout << f.GetHeight() << endl;
        }
    }
    cout << endl;
    cout<< endl;
}

// Plays the game once for a given number of pieces
// We can play the game before and after training the model to see the difference
// We also implement the random player strategy to compare to the Q-learning strategy
void QBrain::Game(int number_of_pieces) {

        // Field on which the Q-learning player plays
        Field f;
        // Field on which the random player plays
        Field random_f;
        cout<<"Beginning of the game"<<"\n";
        cout<<"Number of pieces = "<<number_of_pieces<<'\n';
        cout<<endl;

        for (int i=0 ; i < number_of_pieces ; i++){

            // Displays current height of the game
            cout << "Current height : " << f.GetHeight() << endl;
            cout << endl;

            // Instantiates the next piece and displays it
            Piece p;
            cout << "Next piece: " << endl;
            p.Display();
            cout << endl;

            // Returns best action for a given state of the game and the next piece
            BestActionAndUtility a = ChooseBestAction(f, p);

            // Displays current state of the game (before putting the new piece)
            cout << "Current state :" << endl;
            f.Display();

            // Q-learning player move
            f.MakeMove(p, a.GetBestAction1(), a.GetBestAction2());

            // Random player move
            random_f.MakeMove(p, rand()%4, rand()%5);

            // Uncomment next line to see the random player moves
            // random_f.Display();

            cout << endl;
        }

        cout << "Deletion of the unused objects..."<< endl;
        delete[] _pQ;
        cout << "Objects deleted"<<endl;
        cout << "Final height Q-learning: " << f.GetHeight() << endl;
        cout << "Final height random player: " << random_f.GetHeight() << endl;
    }


