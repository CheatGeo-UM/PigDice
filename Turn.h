#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "DIE.h"
//#include "PDGame.h"

class PDGame; //Step 3 from PDF.

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    Die m_myDie;
    PDGame* m_parentGame = nullptr; //Step 4 from PDF.
public:
    Turn();
    void setParentGame(PDGame* parentGame); //Step 5 from PDF.
    void takeTurn();
    int getScoreThisTurn() const;
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();
private:
    void roll();

};


#endif //PIGDICE_TURN_H