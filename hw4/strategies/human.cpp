#include "human.h"
#include <iostream>
#include <set>

human_strategy_t::human_strategy_t(std::string player) :
        player(std::move(player)) {}

void human_strategy_t::on_win() {
    std::cout << player << " wins!" << std::endl;
}
void human_strategy_t::on_lose() {
    std::cout << player << " loses!" << std::endl;
}
void human_strategy_t::on_tie() {
    std::cout << "Tie!" << std::endl;
}

step_t human_strategy_t::make_step(const field_t &fld) {

    std::cout << "Field:" << std::endl;
    int i = 1;

    for (const auto &line : fld.fld) {
        std::cout << i << "  ";
        i++;
        for (char c : line) {
            std::cout << c << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "   A  B  C  D  E  F  G  H" << std::endl;

    std::cout << player << "'s turn!" << std::endl;

    std::cout << "Type coordinates of the checker: " << std::endl;
    char x0 = '0';
    int y0 = 0;
    char char_y0;
    std::cin >> char_y0 >> x0;

    std::cout << "Type new coordinates of the checker: " << std::endl;
    char x1 = '0';
    int y1 = 0;
    char char_y1;
    std::cin >> char_y1 >> x1;

    y0 = char_y0 - '0';
    if (char_y0 == 'A') { y0 = 1;}
    if (char_y0 == 'B') { y0 = 2;}
    if (char_y0 == 'C') { y0 = 3;}
    if (char_y0 == 'D') { y0 = 4;}
    if (char_y0 == 'E') { y0 = 5;}
    if (char_y0 == 'F') { y0 = 6;}
    if (char_y0 == 'G') { y0 = 7;}
    if (char_y0 == 'H') { y0 = 8;}

    y1 = char_y1 - '0';
    if (char_y1 == 'A') { y1 = 1;}
    if (char_y1 == 'B') { y1 = 2;}
    if (char_y1 == 'C') { y1 = 3;}
    if (char_y1 == 'D') { y1 = 4;}
    if (char_y1 == 'E') { y1 = 5;}
    if (char_y1 == 'F') { y1 = 6;}
    if (char_y1 == 'G') { y1 = 7;}
    if (char_y1 == 'H') { y1 = 8;}

    int x00 = x0 -'0';
    int x11 = x1 -'0';

    return {x00, y0, x11, y1};
}

void human_strategy_t::on_incorrect_step(const step_t &step) const {

    std::set<int> nums{1,2,3,4,5,6,7,8};
    std::set<char> letters{'A','B','C','D','E','F','G','H'};

    char y_0 = step.y0, y_1 = step.y1;

    if (step.y0 == 1) {y_0 = 'A';}
    if (step.y0 == 2) {y_0 = 'B';}
    if (step.y0 == 3) {y_0 = 'C';}
    if (step.y0 == 4) {y_0 = 'D';}
    if (step.y0 == 5) {y_0 = 'E';}
    if (step.y0 == 6) {y_0 = 'F';}
    if (step.y0 == 7) {y_0 = 'G';}
    if (step.y0 == 8) {y_0 = 'H';}

    if (step.y1 == 1) {y_1 = 'A';}
    if (step.y1 == 2) {y_1 = 'B';}
    if (step.y1 == 3) {y_1 = 'C';}
    if (step.y1 == 4) {y_1 = 'D';}
    if (step.y1 == 5) {y_1 = 'E';}
    if (step.y1 == 6) {y_1 = 'F';}
    if (step.y1 == 7) {y_1 = 'G';}
    if (step.y1 == 8) {y_1 = 'H';}

    if (nums.find(step.x0) == nums.end() || nums.find(step.x1) == nums.end()) {
        std::cout << "Incorrect input: try again!" << std::endl;
    } else {
        std::cout << "Incorrect step: " << y_0 << step.x0 << " - " << y_1 << step.x1<< std::endl;
    }

}


