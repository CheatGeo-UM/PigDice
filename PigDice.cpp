#include <iostream>
#include <ctime>
#include <random>


// Build your solution starting from this code.

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
    int m_value;
    int m_numOfSides;
public:
    Die() {
        m_value = 0;
        m_numOfSides = 6;
    }

    void set_numOfSides(int numOfSides) {
        switch (numOfSides) {
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

    }

    void setValue() {
        std::random_device rd;
        std::mt19937 gen (rd());
        std::uniform_int_distribution<int> dis (1,m_numOfSides);
        m_value = dis(gen);
    }

    int getValue() {
        // rules for accessing the data
        return m_value;
    }
};

void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold (GameState &g);
void display_rules();


int main() {
    GameState my_game; // instantiate a GameState object
    Die myDie;
    myDie.setValue();
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void take_turn(GameState &g) {
    g.turn_count += 1;
    std::cout << "\nTURN " << g.turn_count
              << " - Game Score: " << g.game_score << std::endl;
    while (!g.turn_over){
        std::cout << "roll or hold? (r/h): ";
        std::cin >> g.choice;
        if (g.choice == 'r') {
            roll(g);
        }
        else if (g.choice == 'h'){
            hold(g);
        }
        else {
            std::cout << "Invalid Input!" << std::endl;
        }
    }
}

void play_game(GameState &g) {
    while (!g.game_over) {
        take_turn(g);
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

void roll(GameState &g) {
    srand(time(NULL));
    int dieRoll = rand() % 6 + 1;

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