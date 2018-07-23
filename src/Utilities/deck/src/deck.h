#ifndef DECK_H
#define DECK_H

#include <card.h>

#include <deque>

class Deck
{
    unsigned int _size;
    std::deque< Card > _cards;

    public:
    Deck();
    Deck(std::deque< Card > &cards);
    void shuffle();
    Card *draw();
    void insert(Card *card);
    void append(Deck &deck);
    unsigned int size() const
    {
        return _size;
    }
};

#endif // DECK_H
