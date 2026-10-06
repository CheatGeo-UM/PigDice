#include <random>
#include "DIE.h"

Die::Die() {
    m_dieValue = 0;
}

void Die::rollDie() {
    std::random_device rd;
    std::mt19937 gen (rd());
    std::uniform_int_distribution<int> dis (1,6);
    m_dieValue = dis(gen);
}//This sets the value to be between 1 and the number of sides.

int Die::getDieValue() const {
    // rules for accessing the data
    return m_dieValue;
}