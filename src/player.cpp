#include "player.hpp"
#include <iostream>

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
#include <iomanip>

void Player::print_state()
// ai gen method, i dont know how to print this pretty :(
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "Cash  : $" << static_cast<unsigned int>(cash) << "\n";
    std::cout << "Cards :\n";
    if (cards.empty())
    {
        std::cout << "  (No cards)\n";
    }
    else
    {
        for (const auto &card : cards)
        {
            std::cout << "  " << std::setw(10) << std::left << card.type << " : " << std::setw(3)
                      << static_cast<unsigned int>(card.value) << "\n";
        }
    }
    std::cout << "---------------------------------------------------\n";
}

void Player::add_card(u8 value, std::string type)
{
    Card card_to_add;
    card_to_add.type = type;
    card_to_add.value = value;
    cards.push_back(card_to_add);
}
