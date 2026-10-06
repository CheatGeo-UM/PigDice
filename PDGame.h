#ifndef PIGDICE_PDGAME_H
#define PIGDICE_PDGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore; //This will cause some problems that need to be figured out as part of the assignment
public:
    PDGame();
private:
    void displayRules();
    void playGame();
};


#endif //PIGDICE_PDGAME_H