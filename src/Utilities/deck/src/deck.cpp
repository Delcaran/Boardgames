#include "deck.h"

#include <algorithm>
#include <random>

namespace CardLib {
Deck::Deck(std::deque< Card > &cards) : _cards(cards)
{
}

Deck::Deck() : _cards(0)
{
}

void Deck::shuffle()
{
    if (!_cards.empty())
    {
        std::random_device seeder;
        std::mt19937 generator(seeder()); // mersenne_twister engine
        std::uniform_int_distribution<> shuffles(7, 10);

        for (int s = 0; s < shuffles(generator); ++s)
        {
            std::shuffle(_cards.begin(), _cards.end(), generator);
        }
    }
}

Card *Deck::draw()
{
    Card *card = NULL;
    if (!_cards.empty())
    {
        card = &(_cards.front());
        _cards.pop_front();
    }
    return card;
}

void Deck::insert(Card *card)
{
    _cards.push_back(*card);
}

void Deck::append(Deck &deck)
{
    for (unsigned int s = 0; s < deck.size(); ++s)
    {
        _cards.insert(deck.draw());
    }
}
}