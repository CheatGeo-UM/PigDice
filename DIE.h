#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
private:
    int m_dieValue;
    int m_numOfSides;
public:
    Die();
    void set_numOfSides(int numOfSides); //Sides can be 4, 6, or 8
    void set_DieValue();
    int get_DieValue();
    int get_NumOfSides();
};

#endif //PIGDICE_DIE_H