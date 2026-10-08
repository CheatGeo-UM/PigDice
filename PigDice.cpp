#include <iostream>
#include "DIE.h"
#include "PDGame.h"

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

int main() {
    PDGame game;

    return 0;
}
