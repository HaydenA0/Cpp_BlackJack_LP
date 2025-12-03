

#include "objects.hpp"
#include <iostream>
#include <string>
#include <string_view>

std::string request_player_input()
// add enum later depending on what input do we want
{
    std ::cout << "Chose your option :\n";
    std ::cout << "1.Hit\n";
    std ::cout << "2.Stand\n";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

bool handle_hit_or_stand(std::string_view choice, Player &player, Deck &deck)
{
    if (choice == "1")
    {
        player.add_cards(deck.request_cards(1));
        return false;
    }
    else if (choice == "2")
    {
        return true;
    }
    else
    {
        std ::cout << "You entered something weird, TRY AGAIN\n";
        return false;
    }
}
void game_loop()
{
    Deck deck = Deck();
    Player player;
    Player dealer;
    player.add_cards(deck.request_cards(2));
    dealer.add_cards(deck.request_cards(2));
    std::cout << "Dealer have " << (unsigned int)dealer.cards_sum() << "\n";
    if (player.cards_sum() == 21)
    {
        std::cout << "You won !\n";
        return;
    }
    if (dealer.cards_sum() == 21)
    {
        std::cout << "You Lost, Dealer got 21 :( !\n";
        return;
    }

    while (player.cards_sum() < 21)
    {
        std::cout << "You have " << (unsigned int)player.cards_sum() << "\n";
        std::string choice = request_player_input();
        if (handle_hit_or_stand(choice, player, deck))
        {
            break;
        }
    }
    if (player.cards_sum() > 21)
    {
        std::cout << "You busted with " << (unsigned int)player.cards_sum() << "\n";
    }
    else
    {
        while (dealer.cards_sum() <= 17)
        {
            dealer.add_cards(deck.request_cards(1));
            std::cout << "Dealer have " << (unsigned int)dealer.cards_sum() << "\n";
        }
        if (dealer.cards_sum() > 21)
        {
            std::cout << "Dealer busted, You won !!\n ";
        }
        else if (player.cards_sum() < dealer.cards_sum())
        {
            std ::cout << "You lost :(\n";
            std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
            std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
        }
        else if (player.cards_sum() > dealer.cards_sum())
        {
            std ::cout << "You won :)\n";
            std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
            std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
        }
        else
        {
            std ::cout << "You Got tied :/\n";
            std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
            std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
        }
    }
}

int main()
{
    game_loop();
    return 0;
}
