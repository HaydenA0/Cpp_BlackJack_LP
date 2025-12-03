#include "objects.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <string_view>
#include <vector>

void Deck::init_deck()
{
    std::vector<std::string> types = {"Diamond", "Spade", "Heart", "Club"};
    for (const std::string_view type : types)
    {
        for (u8 i = 1; i < 10; i++)
        {
            cards.push_back(Card(i, type));
        }
        cards.push_back(Card(10, type));
        cards.push_back(Card(10, type));
        cards.push_back(Card(10, type));
        cards.push_back(Card(10, type));
    }
}
std::vector<Card> Deck::request_cards(u8 number_of_cards)
{
    std::vector<Card> output;
    for (int i = 0; i < number_of_cards; i++)
    {
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, cards.size() - 1);
        u8 index = dist(rd);
        output.push_back(cards[index]);
        cards.erase(std::next(cards.begin(), index));
    }
    return output;
}
void Player::add_cards(std::vector<Card> cards_to_add)
{
    cards.insert(cards.end(), cards_to_add.begin(), cards_to_add.end());
}
u8 Player::cards_sum()
{
    u8 sum = 0;
    for (u8 i = 0; i < cards.size(); i++)
    {
        sum = sum + cards[i].value;
    }
    return sum;
}
