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
    u32 player_get_cash(void)
    {
        return cash;
    }
    std::vector<u8> player_get_cards(void)
    {
        return cards;
    }
    void player_add_card(u8 card_number);
    void player_add_cash(u32 change, bool sign); // sign can be 1(+) or 0(-1)
    void player_print_state(void);
};

#endif
