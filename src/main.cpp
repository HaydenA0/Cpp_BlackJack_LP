#include "io.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<u8> deck = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

std::vector<std::string_view> types = {"Diamond", "Heart"};

void main_loop(bool &game_closed, Player &player, std::string_view user_choice)
{
    if (user_choice == "1")
    {
        std::cout << "You choose hit !\n";
        Card random_card = gen_card(deck, types);
        player.add_card(random_card.value, random_card.type);
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
