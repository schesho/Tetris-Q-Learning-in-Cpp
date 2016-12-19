//
// Created by Nicolas on 14/12/16.
// The action n°1 is the rotation
// The action n°2 is the position of the piece
//

#include "BestActionAndUtility.h"
#include <iostream>
#include <limits>
using namespace std;

BestActionAndUtility::BestActionAndUtility() {
    _utility = -std::numeric_limits<float>::max();
    // remark: std::numeric_limits<float>::max() give us the largest value for type float
    // Thus _utility is initialized with the lowest possible value
    _best_action1 = 0;
    // action1 is the equivalent for the rotation (ie how many times should we rotate a given piece before inserting it in the game)
    // action2 is the equivalent for the position ( given a piece and a state, the position where we will insert a piece)

    _best_action2 = 0;
}

BestActionAndUtility::~BestActionAndUtility() {
// Destructor
}


float BestActionAndUtility::GetUtility() {
    return _utility;
}

int BestActionAndUtility::GetBestAction1() {
    return _best_action1;
}

int BestActionAndUtility::GetBestAction2() {
    return _best_action2;
}

void BestActionAndUtility::SetUtility(float utility) {
    _utility = utility;
}

void BestActionAndUtility::SetBestAction1(int best_action1) {
    _best_action1 = best_action1;
}

void BestActionAndUtility::SetBestAction2(int best_action2) {
    _best_action2 = best_action2;
}