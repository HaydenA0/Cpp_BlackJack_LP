#include "player.hpp"
#include <iostream>
#include <string>

void print_options(void)
{
    std::cout << "Choose a number :\n";
    std::cout << "1. Hit\n";
    std::cout << "2. Stand\n";
    std::cout << "3. quit\n";
}
std::string player_input(void)
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void main_loop(std::string user_choice)
{
    if (user_choice == "1")
    {
        std::cout << "You chose 1 !\n";
        return;
    }
    if (user_choice == "2")
    {
        std::cout << "You chose 2 !\n";
        return;
    }
    if (user_choice == "3")
    {
        std::cout << "You chose 3 !\n";
        return;
    }
    else
    {
        std::cout << "ERROR : Enter a valid number\n";
    }
}

int main(void)
{
    Player player;
    std::cout << "Program beginns \n";

    player.player_print_state();
    player.player_add_cash(10, 0);
    std::cout << "Added 10 cash" << "\n";
    player.player_print_state();

    return 0;
}
