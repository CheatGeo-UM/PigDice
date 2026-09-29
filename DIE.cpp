#include <random>
#include "DIE.h"

Die::Die() {
    m_numOfSides = 6;
    set_DieValue();
}

void Die::set_numOfSides(int numOfSides) {
    switch (numOfSides) {
        case 2:
            m_numOfSides = 2;
            break;
        case 4:
            m_numOfSides = 4;
            break;
        case 6:
            m_numOfSides = 6;
            break;
        case 8:
            m_numOfSides = 8;
            break;
        default:
            m_numOfSides = 6;
    }

} //This sets the die side amount, which will be used in a function made at a later date.

void Die::set_DieValue() {
    std::random_device rd;
    std::mt19937 gen (rd());
    std::uniform_int_distribution<int> dis (1,m_numOfSides);
    m_dieValue = dis(gen);
}//This sets the value to be between 1 and the number of sides.

int Die::get_DieValue() {
    // rules for accessing the data
    set_DieValue();
    return m_dieValue;
} //This gets the random die value and makes it returnable for use later.

int Die::get_NumOfSides() {
    int num_Sides;
    set_numOfSides(num_Sides);
    return m_numOfSides;
}//This gets the number of sides for a die and makes it returnable for use later.