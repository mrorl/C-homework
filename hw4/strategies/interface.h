#pragma once

#include "../game/structures.h"

class strategy_interface_t {
public:
    virtual step_t make_step(const field_t &field) = 0;
    virtual void on_incorrect_step(const step_t &step) const = 0;

    virtual void on_lose() = 0;
    virtual void on_win() = 0;
    virtual void on_tie() = 0;

    size_t player_num;
    size_t checkers_count;
    size_t move_count = 0;
};