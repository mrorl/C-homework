#pragma once

#include <memory>
#include <vector>
#include "../strategies/interface.h"
#include "structures.h"


class game_t {
public:
    using player_t = std::shared_ptr<strategy_interface_t>;
    game_t(const player_t &first, const player_t &second);

    void play();

private:
    enum game_outcome_t {
        WIN,
        TIE,
        IN_PROGRESS
    };

    bool is_king(const pos_t &pos) const;
    void is_new_king(const step_t &step, int player_num);

    bool nearest_is_empty(const pos_t &pos, int player_num) const;
    bool is_empty_between(const step_t &step, pos_t &not_empty, size_t &count_not_empty);

    bool nearest_is_enemy(const pos_t &pos, int player_num) const;
    bool direction_check(const step_t &step, int player_num) const;

    bool apply_step(const step_t &step, int player_num);
    bool next_move(const step_t &step, bool is_correct, int player_num);
    game_outcome_t is_win() const;

    field_t field;
    std::vector<player_t> players;
};
