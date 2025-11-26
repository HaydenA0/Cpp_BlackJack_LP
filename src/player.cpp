#include "player.hpp"
#include <iostream>
#include <random>
#include <vector>

u8 gen_random_number(u8 min, u8 max)
{
    std::random_device r_d;
    std::mt19937 gen(r_d());
    std::uniform_real_distribution<> dis(min, max);
    return static_cast<u8>(dis(gen));
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

Card gen_card(const std::vector<Card> &deck)
{
    u8 value_index = gen_random_number(0, deck.size());
    return deck[value_index];
}
u8 sum_card(const std::vector<Card> user_cards)
{
    u8 sum = 0;
    for (u8 i = 0; i < user_cards.size(); i++)
    {
        sum += user_cards[i].value;
    }
    return sum;
}
