//
// Created by Nicolas on 14/12/16.
//

#include "BestActionAndUtility.h"#include <iostream>
#include <limits>
using namespace std;

BestActionAndUtility::BestActionAndUtility() {
    _utility = -std::numeric_limits<float>::max();
    _best_action1 = 0;
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