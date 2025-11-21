#include "player.hpp"
#include <iostream>

void Player::add_card(u8 card_number)
{
    cards.push_back(card_number);
}
void Player::add_cash(u32 change, bool sign)
{
    if (sign)
    {
        cash += change;
    }
    else
    {
        cash -= change;
    }
}
void Player::print_state()
{
    std::cout << "Player Cash : " << (unsigned int)cash << "\n";
    std::cout << "Player Cards : " << "\n";
    for (const auto &card : cards)
    {
        std::cout << static_cast<unsigned int>(card) << ",";
    }
    std::cout << "\n";
}
