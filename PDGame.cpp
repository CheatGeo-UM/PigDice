#include <iostream>
#include "PDGame.h"


PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;
    displayRules();
    playGame();
}

void PDGame::displayRules() {
    std::cout << "Welcome To PIG Dice.\n" << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points.\n"
              << "* A turn ends when you hold or roll a 1.\n"
              << "* If you roll a 1, you lose all your points for that turn.\n"
              << "* If you hold, you bank all points for the turn to your game score.\n";
}

void PDGame::playGame() {
    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gameOver = true;
        }
        else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }
    std::cout << "\nYou finished with a final score of "
              << m_gameScore << " in " << m_myTurn.getTurnCount() << " turn(s)!"
              << std::endl;
    std::cout << "Thanks for playing PIG Dice!";
}


