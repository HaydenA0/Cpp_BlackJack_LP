#ifndef LIB1_HPP
#define LIB1_HPP
#include "globals.hpp"
#include <vector>

class Player
{
private:
    u32 cash = 0;
    std::vector<u8> cards = {};

public:
    u32 &get_cash()
    {
        return cash;
    }
    std::vector<u8> &get_cards()
    {
        return cards;
    }
    void add_card(u8 card_number);
    void add_cash(u32 change, bool sign); // sign can be 1(+) or 0(-1)
    void print_state();
};

#endif
