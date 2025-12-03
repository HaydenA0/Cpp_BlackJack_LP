

#include "objects.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

void greet()
{
    std ::cout << "HELLO TO THIS BAD BLACKJACK GAME \n";
    std ::cout << "---------------------------------\n";
    std ::cout << "\n";
}
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

std::string request_user_input()
// add enum later depending on what input do we want
{
    std ::cout << "Chose your option :\n";
    std ::cout << "1.Bet\n";
    std ::cout << "2.Exit\n";
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
u32 get_bet(Player &player, std::string_view user_input)
{
    std::string input;
    if (user_input == "2")
    {
        exit(0);
    }
    if (user_input == "1")
    {
        std ::cout << "You got " << player.get_cash() << "$ \n";
        std ::cout << "Enter your bet : \n";
        std::getline(std::cin, input);
    }
    return std::stoi(input);
}
void game_loop()
{
    Game o_game;
    o_game.is_on = true;
    greet();
    Player player;
    player.set_cash(100);
    Deck deck = Deck();
    while (o_game.is_on)
    {
        if (player.get_cash() == 0)
        {
            std::cout << "You got cleared\nDon't worry, it HAPPENS to the best of us.\n";
            exit(0);
        }
        std::string user_input = request_user_input();
        u32 bet = get_bet(player, user_input);
        while (bet > player.get_cash())
        {
            std::cout << "You cant bet more than what you have bro\n";
            bet = get_bet(player, user_input);
        }
        player.reset_cards();
        Player dealer;
        player.add_cards(deck.request_cards(2));
        dealer.add_cards(deck.request_cards(2));
        std::cout << "Dealer have " << (unsigned int)dealer.cards_sum() << "\n";
        if (player.cards_sum() == 21)
        {
            std::cout << "You won !\n";
            player.change_cash(bet, true);
            return;
        }
        if (dealer.cards_sum() == 21)
        {
            std::cout << "You Lost, Dealer got 21 :( !\n";
            player.change_cash(bet, false);
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
            player.change_cash(bet, false);
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
                std::cout << "Dealer busted, You won !!\n";
                player.change_cash(bet, true);
            }
            else if (player.cards_sum() < dealer.cards_sum())
            {
                std ::cout << "You lost :(\n";
                std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
                std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
                player.change_cash(bet, false);
            }
            else if (player.cards_sum() > dealer.cards_sum())
            {
                std ::cout << "You won :)\n";
                std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
                std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
                player.change_cash(bet, true);
            }
            else
            {
                std ::cout << "You Got tied :/\n";
                std ::cout << "     Dealer got " << (unsigned int)dealer.cards_sum() << "\n";
                std ::cout << "     You got " << (unsigned int)player.cards_sum() << "\n";
                player.change_cash(0, true);
            }
        }
        std ::cout << "----------------------------------------\n";
        std ::cout << "----------------------------------------\n";
        std ::cout << "----------------------------------------\n";
    }
}

int main()
{
    game_loop();
    return 0;
}
