#include "globals.hpp"
#include <string>
#include <vector>

class Card
{
public:
    u8 value;
    std::string type;

public:
    Card(u8 _value, std::string_view _type)
    {
        value = _value;
        type = _type;
    }
};

class Deck
{
private:
    std::vector<Card> cards;

public:
    void init_deck();
    Deck()
    {
        cards = {};
        init_deck();
    }
    std::vector<Card> request_cards(u8 number_of_cards); // remove the cards requested
};
class Player
{
private:
    u32 cash;
    std::vector<Card> cards;

public:
    void add_cards(std::vector<Card> cards_to_add);
    u8 cards_sum();
    void set_cash(u32 cash_to_set);
    void change_cash(u32 cash_diff, bool sign); // 1 -> +1, 0 -> -1
    u32 get_cash()
    {
        return cash;
    }
    void reset_cards()
    {
        cards = {};
    }
};

class Dealer : public Player
{
    void show_card();
};

class Game
{
public:
    bool is_on;
    bool lost;
};
