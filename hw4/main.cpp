#include <memory>
#include "game/game.h"
#include "strategies/human.h"
#include "strategies/computer_strategy_1.h"
#include "strategies/computer_strategy_2.h"

int main() {

    /*auto player1 = std::make_shared<computer_strategy_2>("White");
    auto player2 = std::make_shared<computer_strategy_2>("Black");

    for (int i = 0; i < 1000; ++i) {
        game_t game(player1, player2);
        game.play();
    }

    player1->print_stat();
    player2->print_stat();*/

    auto player1 = std::make_shared<human_strategy_t>("White");
    auto player2 = std::make_shared<human_strategy_t>("Black");

    game_t game(player1, player2);
    game.play(); /**/

  return 0;
}