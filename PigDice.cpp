#include <iostream>
#include <random>


struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

class Die {
private:
    int m_dievalue;
    int m_numOfSides;
public:
    Die() {
        m_dievalue = 0;
        m_numOfSides = 6;
    }

    void set_numOfSides(int numOfSides) {
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

    void set_DieValue() {
        std::random_device rd;
        std::mt19937 gen (rd());
        std::uniform_int_distribution<int> dis (1,m_numOfSides);
        m_dievalue = dis(gen);
    }//This sets the value to be between 1 and the number of sides.

    int get_DieValue() {
        // rules for accessing the data
        set_DieValue();
        return m_dievalue;
    } //This gets the random die value and makes it returnable for use later.

    int get_NumOfSides() {

        return m_numOfSides;
    }//This gets the number of sides for a die and makes it returnable for use later.
};

void play_game(GameState &g, Die &d);
void take_turn(GameState &g, Die &d);
void roll(GameState &g, Die &d);
void hold (GameState &g);
void display_rules();


int main() {
    GameState my_game; // instantiate a GameState object
    Die myDie;

    display_rules(); // call the display_rules function
    play_game(my_game, myDie); // call the play_game function and pass the GameState object
    return 0;
}

void take_turn(GameState &g, Die &d) {
    g.turn_count += 1;
    std::cout << "\nTURN " << g.turn_count
              << " - Game Score: " << g.game_score << std::endl;
    while (!g.turn_over){
        std::cout << "roll or hold? (r/h): ";
        std::cin >> g.choice;
        if (g.choice == 'r') {
            roll(g, d);
        }
        else if (g.choice == 'h'){
            hold(g);
        }
        else {
            std::cout << "Invalid Input!" << std::endl;
        }
    }
}

void play_game(GameState &g, Die &d) {
    while (!g.game_over) {
        take_turn(g, d);
        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
        }
    }
    std::cout << "\nYou finished with a final score of "
              << g.game_score << " in " << g.turn_count << " turn(s)!"
              << std::endl;
    std::cout << "Thanks for playing PIG Dice!";
}

void roll(GameState &g, Die &d) {
    int dieRoll = d.get_DieValue();
    if (dieRoll == 1) {
        g.turn_over = true;
        g.score_this_turn = 0;
        std::cout << "Die: " << dieRoll
                  << "\nTurn over. No score.\n"
                  << "Score Banked This Turn: 0"
                  << std::endl;
    }
    else {
        g.score_this_turn += dieRoll;
        std::cout << "Die: " << dieRoll
                  << " - Running score this turn: "
                  << g.score_this_turn << std::endl;
        }
}

void hold(GameState &g) {
    g.game_score += g.score_this_turn;
    std::cout << "Score Banked This Turn: " << g.score_this_turn
              << std::endl;
    g.turn_over = true;
    g.score_this_turn = 0;
}

void display_rules() {
    std::cout << "Welcome To PIG Dice.\n" << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points.\n"
              << "* A turn ends when you hold or roll a 1.\n"
              << "* If you roll a 1, you lose all your points for that turn.\n"
              << "* If you hold, you bank all points for the turn to your game score.\n";
}