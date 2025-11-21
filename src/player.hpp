#ifndef LIB1_HPP
#define LIB1_HPP
#include "globals.hpp"
#include <string>
#include <vector>

struct Card
{
    u8 value;
    std::string type;
};

class Player
{
private:
    u32 cash = 0;
    std::vector<Card> cards = {};

public:
    u32 get_cash()
    {
        return cash;
    }
    std::vector<Card> get_cards()
    {
        return cards;
    }
    void add_cash(u32 change, bool sign); // sign can be 1(+) or 0(-1)
    void print_state();
    void add_card(u8 value, std::string type);
};

Card gen_card(const std::vector<u8> &deck, const std::vector<std::string_view> &types);
#endif
