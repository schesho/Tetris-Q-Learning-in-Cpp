// This class is necessary to define the action taken for a give piece and a given field (state of the game)
// The action n°1 is the rotation
// The action n°2 is the position of the piece
//

#ifndef TETRIS_RL_BESTACTIONANDUTILITY_H
#define TETRIS_RL_BESTACTIONANDUTILITY_H


class BestActionAndUtility {
private:
    float _utility;
    int _best_action1;
    int _best_action2;
public:
    BestActionAndUtility();
    ~BestActionAndUtility();
    float GetUtility();
    int GetBestAction1();
    int GetBestAction2();
    void SetUtility(float);
    void SetBestAction1(int);
    void SetBestAction2(int);


};


#endif //TETRIS_RL_BESTACTIONANDUTILITY_H
