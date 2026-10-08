#include <iostream>
#include "Turn.h"

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0';
}

//Turn(&){
//
//}

void Turn::takeTurn() {
    m_turnCount += 1;
    std::cout << "\nTURN " << m_turnCount;
              // ISSUE: Turn object "part" needs access to m_gameScore in "whole"
    while (!m_turnOver){
        std::cout << "roll or hold? (r/h): ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h'){
            m_turnOver = true;
        }
        else {
            std::cout << "Invalid Input!" << std::endl;
        }
    }
}

int Turn::getScoreThisTurn() const {

    return m_scoreThisTurn;
}

void Turn::resetTurnOver() {
    m_turnOver = false;
}

int Turn::getTurnCount() {
    return m_turnCount;
}

void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}

void Turn::roll() {
    m_myDie.rollDie();
    std::cout << "Die: " << m_myDie.getDieValue();
    if (m_myDie.getDieValue() == 1) {
        std::cout << "\nTurn over. No score.\n"
                  << "Score Banked This Turn: 0"
                  << std::endl;
        m_scoreThisTurn = 0;
        m_turnOver = true;
    }
    else {
        m_scoreThisTurn += m_myDie.getDieValue();
        std::cout << "Die: " << m_myDie.getDieValue()
                  << " - Running score this turn: "
                  << m_scoreThisTurn << std::endl;
    }
}