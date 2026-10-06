#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
private:
    int m_dieValue;
    int m_numOfSides;
public:
    Die();

    void rollDie();
    int getDieValue() const;
};

#endif //PIGDICE_DIE_H