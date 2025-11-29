
#include "io.hpp"
#include <iostream>
void main_loop_print_options()
{
    std::cout << "Choose a number :\n";
    std::cout << "1. Hit\n";
    std::cout << "2. Stand\n";
    std::cout << "3. quit\n";
}
void new_game_print_options()
{
    std ::cout << "Enter how much you want to bet :\n";
}
std::string player_input()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}
