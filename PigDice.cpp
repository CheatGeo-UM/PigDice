#include <iostream>
#include <cstdlib>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void instructions();
void addScore(GameState &gs);
int diceRoll (int dice, GameState &ts);


int main() {
    GameState my_game; // instantiate a GameState object
    //int dice;

    //instructions();
    //diceRoll(dice, my_game);
    //addScore(my_game);
    //std::cout << "Game score is: " << my_game.game_score << std::endl;
    // display_rules(); // call the display_rules function
    // play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}


void instructions() {
    std::cout << "Welcome to Pig Dice.\n"
              << "* See how many turns it takes you to get to 20 points.\n"
              << "* A turn ends when you hold or roll a 1.\n"
              << "* If you roll a 1, you lose all your points for that turn.\n"
              << "* If you hold, you bank all points for the turn to your game score.\n";
}

void addScore(GameState &gs) {
    //gs.game_score += 10;
}

int diceRoll (int dice, GameState &ts) {
    dice = rand() % 6 + 1;
    std::cout << "You rolled a " << dice << " on this roll.\n"
              << "Would you like to roll again or hold?: ";
    //std::cin >> choice;
    ts.score_this_turn += dice;
     return ts.score_this_turn;
}