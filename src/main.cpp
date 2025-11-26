#include "./deck.cpp"
#include "io.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<Card> deck = {};
std::vector<std::string> suits = {"Diamond", "Heart", "Club", "Spade"};
void fill_deck(std::vector<Card> &deck, std::vector<std::string> suits)
{
    for (const auto &suit : suits)
    {
        for (int value = 1; value <= 9; ++value)
        {
            deck.emplace_back(value, suit);
        }
        for (int i = 0; i < 4; ++i)
        {
            deck.emplace_back(10, suit);
        }
    }
}

void main_loop(bool &game_closed, Player &player, std::string_view user_choice)
{
    if (user_choice == "1")
    {
        std::cout << "You choose hit !\n";
        Card random_card = gen_card_and_remove(deck);
        player.add_card(random_card.value, random_card.type);
        u8 cards_sum = sum_card(player.get_cards());
        if (cards_sum > 21)
        {
            std ::cout << "You busted with " << (unsigned int)cards_sum << "\n";
            game_closed = true;
        }
        return;
    }
    if (user_choice == "2")
    {
        std::cout << "You choose to stand !\n";
        game_closed = true;
        return;
    }
    if (user_choice == "3")
    {
        std::cout << "You choose to quite !\n";
        game_closed = true;
        return;
    }
    else
    {
        std::cout << "ERROR : Enter a valid number\n";
        return;
    }
}

int main()
{
    fill_deck(deck, suits);
    Player player;
    player.print_state();
    bool game_closed = false;
    while (!game_closed)
    {
        print_options();
        std::string user_input = player_input();
        main_loop(game_closed, player, user_input);
        player.print_state();
    }

    return 0;
}
