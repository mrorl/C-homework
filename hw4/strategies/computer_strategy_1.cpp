#include "computer_strategy_1.h"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include <set>

computer_strategy_1::computer_strategy_1(std::string name) :
        name(std::move(name)) {}

step_t computer_strategy_1::make_step(const field_t &fld) {

    std::vector<pos_t> checkers_coordinates;
    std::vector<step_t> possible_step;
    std::vector<int> regular_steps;
    int possible_attack = 0;
    char this_men, this_king, enemy_men, enemy_king;
    int player;

    if (name == "White") {
        this_men = 'w';
        this_king = 'W';
        enemy_men = 'b';
        enemy_king = 'B';
        player = 0;
    } else {
        this_men = 'b';
        this_king = 'B';
        enemy_men = 'w';
        enemy_king = 'W';
        player = 1;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (fld.fld[i][j] == this_men || fld.fld[i][j] == this_king ) {
                checkers_coordinates.emplace_back(i, j);
            }
        }
    }

    int count = checkers_coordinates.size();

    for (int i = 0; i < count; i++) {

        char cell = fld.fld[checkers_coordinates[i].x][checkers_coordinates[i].y];
        pos_t pos(checkers_coordinates[i].x,checkers_coordinates[i].y );

        std::set <char> direction1;
        std::set <char> direction2;
        std::set <char> direction3;
        std::set <char> direction4;

        int a = 0;
        if (cell == this_men) {
            a = 1;
        } else if (cell == this_king) {
            a = 8;
        }

        int n = 1 ;
        while (n < a + 1) {

            bool direction_check_nbr1 = true;
            bool direction_check_nbr2 = true;
            bool direction_check_nbr3 = true;
            bool direction_check_nbr4 = true;

            if(player == 0 && cell == this_men) {
                direction_check_nbr1 = false;
                direction_check_nbr2 = false;
            } else if (player == 1 && cell == this_men) {
                direction_check_nbr3 = false;
                direction_check_nbr4 = false;
            }

            char nbr1 = fld.fld[pos.x - n][pos.y - n];
            char nbr2 = fld.fld[pos.x - n][pos.y + n];
            char nbr3 = fld.fld[pos.x + n][pos.y - n];
            char nbr4 = fld.fld[pos.x + n][pos.y + n];

            char nbr11 = fld.fld[pos.x - (n + 1)][pos.y - (n + 1)];
            char nbr22 = fld.fld[pos.x - (n + 1)][pos.y + (n + 1)];
            char nbr33 = fld.fld[pos.x + (n + 1)][pos.y - (n + 1)];
            char nbr44 = fld.fld[pos.x + (n + 1)][pos.y + (n + 1)];

            if (nbr11 == '#' && (nbr1 == enemy_men || nbr1 == enemy_king) && direction1.find(this_men) == direction1.end() && direction1.find(this_king) == direction1.end() \
             && nbr1 != this_men && nbr1 != this_king) {

                if (a == 8) {
                    if (direction1.find(enemy_men) == direction1.end() && direction1.find(enemy_king) == direction1.end()) {
                        possible_step.emplace_back(pos.x, pos.y, pos.x - (n + 1), pos.y - (n + 1));
                        possible_attack++;
                    }
                } else {
                    possible_step.emplace_back(pos.x, pos.y, pos.x - (n + 1), pos.y - (n + 1));
                    possible_attack++;
                }

            }
            if (nbr22 == '#' && (nbr2 == enemy_men || nbr2 == enemy_king) && direction2.find(this_men) == direction2.end() && direction2.find(this_king) == direction2.end() \
             && nbr2 != this_men && nbr2 != this_king) {

                if (a == 8) {
                    if (direction2.find(enemy_men) == direction2.end() && direction2.find(enemy_king) == direction2.end()) {
                        possible_step.emplace_back(pos.x, pos.y, pos.x - (n + 1), pos.y + (n + 1));
                        possible_attack++;
                    }
                } else {
                    possible_step.emplace_back(pos.x, pos.y, pos.x - (n + 1), pos.y + (n + 1));
                    possible_attack++;
                }

            }
            if (nbr33 == '#' && (nbr3 == enemy_men || nbr3 == enemy_king) && direction3.find(this_men) == direction3.end() && direction3.find(this_king) == direction3.end() \
            && nbr3 != this_men && nbr3 != this_king) {

                if (a == 8) {
                    if (direction3.find(enemy_men) == direction3.end() && direction3.find(enemy_king) == direction3.end()) {
                        possible_step.emplace_back(pos.x, pos.y, pos.x + (n + 1), pos.y - (n + 1));
                        possible_attack++;
                    }
                } else {
                    possible_step.emplace_back(pos.x, pos.y, pos.x + (n + 1), pos.y - (n + 1));
                    possible_attack++;
                }

            }
            if (nbr44 == '#' && (nbr4 == enemy_men || nbr4 == enemy_king) && direction4.find(this_men) == direction4.end() && direction4.find(this_king) == direction4.end() \
            && nbr4 != this_men && nbr4 != this_king) {

                if (a == 8) {
                    if (direction4.find(enemy_men) == direction4.end() && direction4.find(enemy_king) == direction4.end()) {
                        possible_step.emplace_back(pos.x, pos.y, pos.x + (n + 1), pos.y + (n + 1));
                        possible_attack++;
                    }
                } else {
                    possible_step.emplace_back(pos.x, pos.y, pos.x + (n + 1), pos.y + (n + 1));
                    possible_attack++;
                }

            }

            direction1.insert(nbr1);
            direction2.insert(nbr2);
            direction3.insert(nbr3);
            direction4.insert(nbr4);

            if (possible_attack == 0) {
                if (nbr1 == '#' && direction_check_nbr1 && direction1.find(this_men) == direction1.end() && direction1.find(this_king) == direction1.end()) {

                    if (a == 8) {
                        if (direction1.find(enemy_men) == direction1.end() && direction1.find(enemy_king) == direction1.end()) {
                            possible_step.emplace_back(pos.x, pos.y, pos.x - n, pos.y - n);
                            regular_steps.emplace_back(possible_step.size() - 1);
                        }
                    } else {
                        possible_step.emplace_back(pos.x, pos.y, pos.x - n, pos.y - n);
                        regular_steps.emplace_back(possible_step.size() - 1);
                    }
                }
                if (nbr2 == '#' && direction_check_nbr2 && direction2.find(this_men) == direction2.end() && direction2.find(this_king) == direction2.end()) {

                    if (a == 8) {
                        if (direction2.find(enemy_men) == direction2.end() && direction2.find(enemy_king) == direction2.end()) {
                            possible_step.emplace_back(pos.x, pos.y, pos.x - n, pos.y + n);
                            regular_steps.emplace_back(possible_step.size() - 1);
                        }
                    } else {
                        possible_step.emplace_back(pos.x, pos.y, pos.x - n, pos.y + n);
                        regular_steps.emplace_back(possible_step.size() - 1);
                    }
                }
                if (nbr3 == '#' && direction_check_nbr3 && direction3.find(this_men) == direction3.end() && direction3.find(this_king) == direction3.end()) {

                    if (a == 8) {
                        if (direction3.find(enemy_men) == direction3.end() && direction3.find(enemy_king) == direction3.end()) {
                            possible_step.emplace_back(pos.x, pos.y, pos.x + n, pos.y - n);
                            regular_steps.emplace_back(possible_step.size() - 1);
                        }
                    } else {
                        possible_step.emplace_back(pos.x, pos.y, pos.x + n, pos.y - n);
                        regular_steps.emplace_back(possible_step.size() - 1);
                    }
                }
                if (nbr4 == '#' && direction_check_nbr4 && direction4.find(this_men) == direction4.end() && direction4.find(this_king) == direction4.end()) {

                    if (a == 8) {
                        if (direction4.find(enemy_men) == direction4.end() && direction4.find(enemy_king) == direction4.end()) {
                            possible_step.emplace_back(pos.x, pos.y, pos.x + n, pos.y + n);
                            regular_steps.emplace_back(possible_step.size() - 1);
                        }
                    } else {
                        possible_step.emplace_back(pos.x, pos.y, pos.x + n, pos.y + n);
                        regular_steps.emplace_back(possible_step.size() - 1);
                    }
                }
            }

            n++;
        }
    }

    bool fight = false;

    if (possible_attack != 0) {
        for (int i = 0; i < regular_steps.size(); i++) {

            auto iter = possible_step.cbegin();
            auto num = regular_steps.operator[](regular_steps.size() - i - 1);
            possible_step.erase(iter + num);
        }
        fight = true;
    }

    assert(!possible_step.empty());
    std::random_shuffle(possible_step.begin(), possible_step.end());
    auto pos = possible_step.front();
    if (!is_fight.empty() && is_fight.back() == true && fight) {
        for (int n = 0; n < possible_step.size(); n++) {

            if ( possible_step.operator[](n).x0 == steps_vector.back().second.x1 && possible_step.operator[](n).y0 == steps_vector.back().second.y1) {
                pos = possible_step.operator[](n);
            }
        }
    }
    char cell = fld.fld[pos.x0][pos.y0];
    steps_vector.emplace_back(cell, pos);
    is_fight.emplace_back(fight);

    return {pos.x0 + 1, pos.y0 + 1, pos.x1 + 1, pos.y1 + 1};
}

void computer_strategy_1::print_stat() const {
    std::cout << "Random model [" << name << "]: " << std::endl;
    computer_interface_t::print_stat();
}