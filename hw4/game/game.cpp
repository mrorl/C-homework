#include "game.h"
#include <vector>
#include <list>
#include <set>

game_t::game_t(const player_t &first, const player_t &second) :
        field() {
    players.push_back(first);
    players[0]->player_num = 0;
    players[0]->checkers_count = 12;

    players.push_back(second);
    players[1]->player_num = 1;
    players[1]->checkers_count = 12;
}

bool game_t::is_king(const pos_t &pos) const {

    char cell0 = field.fld[pos.x - 1][pos.y - 1];
    if(cell0=='W'||cell0=='B') {
        return true;
    } else {
        return false;
    }
}

void game_t::is_new_king(const step_t &step, int player_num) {

    std::list <char> men = {'b','w'};
    char &cell1 = field.fld[step.x1 - 1][step.y1 - 1];

    if (cell1 == men.front() || cell1 == men.back()) {

        if (player_num == 0) {
            if (step.x1 == 8) {
                cell1 = 'W';
            }
        } else {
            if (step.x1 == 1) {
                cell1 = 'B';
            }
        }
    }
}

bool game_t::direction_check(const step_t &step, int player_num) const {

    bool direction = false;

    if (player_num == 0) {
        if ((step.x1 - step.x0) > 0) {
            direction = true;
        }
    } else {
        if ((step.x1 - step.x0) < 0) {
            direction = true;
        }
    }
    return direction;
}

bool game_t::is_empty_between(const step_t &step, pos_t &not_empty, size_t &count_not_empty) {

    int count = abs(step.x1 - step.x0);
    bool is_empty = true;
    count_not_empty = 0;

    int m,n;
    if (step.x0 < step.x1 && step.y0 < step.y1) {
        m = 1;
        n = 1;
    } else if (step.x0 < step.x1 && step.y0 > step.y1) {
        m = 1;
        n = -1;
    } else if (step.x0 > step.x1 && step.y0 < step.y1) {
        m = -1;
        n = 1;
    } else {
        m = -1;
        n = -1;
    }

    while (count) {
        if (field.fld[step.x0 - 1 + count * m][step.y0 - 1 + count * n] != '#') {
            is_empty = false;
            not_empty.x = step.x0 + count * m;
            not_empty.y = step.y0 + count * n;
            count_not_empty++;
        }
        count--;
    }

    return is_empty;
}

bool game_t::nearest_is_empty(const pos_t &pos, int player_num) const {

    char nbr1 = field.fld[pos.x - 1 - 1][pos.y - 1 - 1];
    char nbr2 = field.fld[pos.x - 1 - 1][pos.y - 1 + 1];
    char nbr3 = field.fld[pos.x - 1 + 1][pos.y - 1 - 1];
    char nbr4 = field.fld[pos.x - 1 + 1][pos.y - 1 + 1];

    std::vector <char> neighbours = {nbr1, nbr2, nbr3, nbr4};

    int k1,k2;
    if (player_num == 0) {
        k1 = 2;
        k2 = 3;
    } else {
        k1 = 0;
        k2 = 1;
    }

    if (is_king(pos)) {
        return neighbours[0] == '#' || neighbours[1] == '#' || neighbours[2] == '#' || neighbours[3] == '#';
    } else {
        return neighbours[k1] == '#' || neighbours[k2] == '#';
    }

}

bool game_t::nearest_is_enemy(const pos_t &pos, int player_num) const {

    bool nearest_is_enemy = false;
    int count;
    char this_men, this_king, enemy_men, enemy_king;

    if (player_num == 0) {
        enemy_men = 'b';
        enemy_king = 'B';
        this_men = 'w';
        this_king = 'W';
    } else {
        enemy_men = 'w';
        enemy_king = 'W';
        this_men = 'b';
        this_king = 'B';
    }

    if (!is_king(pos)) {
        count = 3;
    } else {
        count = 8;
    }

    std::vector <char> neighbours;

    std::set <char> direction1;
    std::set <char> direction2;
    std::set <char> direction3;
    std::set <char> direction4;

    for (int i = 2; i < count; i++) {

        char nbr1 = field.fld[pos.x - 1 - (i - 1)][pos.y - 1 - (i - 1)];
        char next_to_nbr1 = field.fld[pos.x - 1 - i][pos.y - 1 - i];
        char nbr2 = field.fld[pos.x - 1 - (i - 1)][pos.y - 1 + (i - 1)];
        char next_to_nbr2 = field.fld[pos.x - 1 - i][pos.y - 1 + i];
        char nbr3 = field.fld[pos.x - 1 + (i - 1)][pos.y - 1 - (i - 1)];
        char next_to_nbr3 = field.fld[pos.x - 1 + i][pos.y - 1 - i];
        char nbr4 = field.fld[pos.x - 1 + (i - 1)][pos.y - 1 + (i - 1)];
        char next_to_nbr4 = field.fld[pos.x - 1 + i][pos.y - 1 + i];

        if (next_to_nbr1 == '#' && direction1.find(this_men) == direction1.end() && direction1.find(this_king) == direction1.end() && nbr1 != this_men && nbr1 != this_king) {

            if (i > 2) {
                if (direction1.find(enemy_men) == direction1.end() && direction1.find(enemy_king) == direction1.end()) {
                    neighbours.push_back(nbr1);
                }
            } else {
                neighbours.push_back(nbr1);
            }
        } else {neighbours.push_back(0);}

        if (next_to_nbr2 == '#' && direction2.find(this_men) == direction2.end() && direction2.find(this_king) == direction2.end()) {

            if (i > 2) {
                if (direction2.find(enemy_men) == direction2.end() && direction2.find(enemy_king) == direction2.end()) {
                    neighbours.push_back(nbr2);
                }
            } else {
                neighbours.push_back(nbr2);
            }
        } else {neighbours.push_back(0);}

        if (next_to_nbr3 == '#' && direction3.find(this_men) == direction3.end() && direction3.find(this_king) == direction3.end()) {

            if (i > 2) {
                if (direction3.find(enemy_men) == direction3.end() && direction3.find(enemy_king) == direction3.end()) {
                    neighbours.push_back(nbr3);
                }
            } else {
                neighbours.push_back(nbr3);
            }
        } else {neighbours.push_back(0);}

        if (next_to_nbr4 == '#' && direction4.find(this_men) == direction4.end() && direction4.find(this_king) == direction4.end()) {

            if (i > 2) {
                if (direction4.find(enemy_men) == direction4.end() && direction4.find(enemy_king) == direction4.end()) {
                    neighbours.push_back(nbr4);
                }
            } else {
                neighbours.push_back(nbr4);
            }

        } else {neighbours.push_back(0);}

        direction1.insert(nbr1);
        direction2.insert(nbr2);
        direction3.insert(nbr3);
        direction4.insert(nbr4);

        for (int j = 0; j < neighbours.size(); j++) {
            if (neighbours[j] == enemy_men || neighbours[j] == enemy_king ) {
                nearest_is_enemy = true;
                break;
            }
        }
    }

    return nearest_is_enemy;
}

bool game_t::apply_step(const step_t &step, int player_num) {

    char &cell0 = field.fld[step.x0 - 1][step.y0 - 1];
    char &cell1 = field.fld[step.x1 - 1][step.y1 - 1];
    pos_t pos(step.x0, step.y0);
    bool is_correct_step = false;
    pos_t not_empty(8,8);
    size_t count_not_empty = 0;

    char this_men, this_king, enemy_men, enemy_k;
    if (player_num == 0) {
        this_men = 'w';
        this_king = 'W';
        enemy_men = 'b';
        enemy_k = 'B';

    } else {
        this_men = 'b';
        this_king = 'B';
        enemy_men = 'w';
        enemy_k = 'W';
    }

    if (cell0 == this_men || cell0 == this_king) {
        if (cell1 == '#') {

            bool victim_check = false;
            bool attack = false;

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    pos_t pos_ij(i + 1,j + 1);
                    if (field.fld[i][j] == this_men || field.fld[i][j] == this_king) {
                        victim_check = nearest_is_enemy(pos_ij, player_num);
                    }
                    if (victim_check) {
                        attack = true;
                    }
                }
            }

            if (!is_king(pos) && abs(step.x1-step.x0) == 1 && abs(step.y1-step.y0) == 1 && direction_check(step, player_num) && !attack) {

                cell0 = '#';
                cell1 = this_men;
                players[player_num]->move_count++;
                is_correct_step = true;
                is_new_king(step, player_num);

            } else if (is_king(pos) && abs(step.x1-step.x0) == abs(step.y1-step.y0) && is_empty_between(step, not_empty, count_not_empty) && !attack) {

                if (is_empty_between(step, not_empty, count_not_empty)) {
                    cell0 = '#';
                    cell1 = this_king;
                    players[player_num]->move_count++;
                    is_correct_step = true;
                }

            } else if (!is_king(pos) && abs(step.x1-step.x0) == 2 && abs(step.y1-step.y0) == 2 && \
            (field.fld[(step.x0 + step.x1) / 2 - 1][(step.y0 + step.y1) / 2 - 1] == enemy_men || field.fld[(step.x0 + step.x1) / 2 - 1][(step.y0 + step.y1) / 2 - 1] == enemy_k)) {

                cell0 = '#';
                cell1 = this_men;
                field.fld[(step.x0 + step.x1)/2 - 1][(step.y0 + step.y1)/2 - 1] = '#';
                players[abs(player_num - 1)]->checkers_count --;
                players[player_num]->move_count++;
                is_correct_step = true;
                is_new_king(step, player_num);

            } else if(is_king(pos) && abs(step.x1-step.x0) == abs(step.y1-step.y0) && !is_empty_between(step, not_empty, count_not_empty)) {

                if (!is_empty_between(step, not_empty, count_not_empty)) {

                    if (count_not_empty == 1) {
                        if (field.fld[not_empty.x - 1][not_empty.y - 1] == enemy_men || field.fld[not_empty.x - 1][not_empty.y - 1] == enemy_k ) {

                            cell0 = '#';
                            cell1 = this_king;
                            field.fld[not_empty.x - 1][not_empty.y - 1] = '#';
                            players[abs(player_num - 1)]->checkers_count --;
                            players[player_num]->move_count++;
                            is_correct_step = true;
                        }
                    }
                }
            }
        }
    }

    return is_correct_step;
}

game_t::game_outcome_t game_t::is_win() const {

    pos_t pos(8,8);
    int cant_move_white = 0;
    int cant_move_black = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            pos.x = i + 1;
            pos.y = j + 1;
            if (field.fld[pos.x - 1][pos.y - 1] == 'w' || field.fld[pos.x - 1][pos.y - 1] == 'W') {
                if (!nearest_is_empty(pos, 0)) {
                    cant_move_white++;
                }
            } else if (field.fld[pos.x - 1][pos.y - 1] == 'b' || field.fld[pos.x - 1][pos.y - 1] == 'B') {
                if (!nearest_is_empty(pos, 1)) {
                    cant_move_black++;
                }
            }
        }
    }

    if (cant_move_white == players[0]->checkers_count || cant_move_black == players[1]->checkers_count) {
        return WIN;
    }else if (players[0]->checkers_count == 0 || players[1]->checkers_count == 0 ) {
        return WIN;
    } else if (players[0]->move_count > 10000) {
        return TIE;
    } else {
        return IN_PROGRESS;
    }
}

void game_t::play() {

    int counter = 1;
    while (is_win() == IN_PROGRESS) {
        counter = (counter + 1) % 2;
        bool is_correct = false;
        while (!is_correct) {
            step_t step = players[counter]->make_step(field);
            is_correct = next_move(step, is_correct, counter);
        }
    }

    if (is_win() == TIE) {
        for (const auto &p : players) {
            p->on_tie();
        }
        return;
    }

    for (int i = 0; i < players.size(); ++i) {
        if (i == counter) {
            players[i]->on_win();
        } else {
            players[i]->on_lose();
        }
    }
}

bool game_t::next_move(const step_t &step, bool is_correct, int player_num) {

    int enemy_checkers = players[abs(player_num - 1)]->checkers_count;
    is_correct = apply_step(step, player_num);

    if (!is_correct) {
        players[player_num]->on_incorrect_step(step);
    }
    pos_t pos(step.x1, step.y1);

    if (enemy_checkers != players[abs(player_num - 1)]->checkers_count) {
        while (nearest_is_enemy(pos, player_num)) {
            step_t step = players[player_num]->make_step(field);
            if (step.x0 == pos.x && step.y0 == pos.y ) {

                is_correct = apply_step(step, player_num);
                if (!is_correct) {
                    players[player_num]->on_incorrect_step(step);
                } else {
                    pos.x = step.x1;
                    pos.y = step.y1;
                }

            } else {
                players[player_num]->on_incorrect_step(step);
            }
        }
    }

    return is_correct;
}
