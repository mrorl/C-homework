#pragma once

#include <string>

#include "../game/structures.h"
#include "../game/game.h"
#include "computer_interface.h"


class computer_strategy_1 : public computer_interface_t {
public:
    explicit computer_strategy_1(std::string name);
    step_t make_step(const field_t &field) override;

    void print_stat() const override;

private:
    std::string name;
    std::vector<std::pair<char, step_t>> steps_vector;
    std::vector<bool> is_fight;
};