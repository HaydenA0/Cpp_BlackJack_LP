#include "player.hpp"
#include <iostream>

void Player::player_add_card(u8 card_number)
{
    cards.push_back(card_number);
}
void Player::player_add_cash(u32 change, bool sign)
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
void Player::player_print_state(void)
{
    std::cout << "Player Cash : " << cash << "\n";
    std::cout << "Player Cards : " << "\n";
    for (u8 card : cards)
    {
        std::cout << card << "\n";
    }
}
