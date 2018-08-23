#ifndef DECK_H
#define DECK_H

#ifdef Deck_EXPORTS
#define DECK_DLL_API __declspec(dllexport) 
#else
#define DECK_DLL_API __declspec(dllimport) 
#endif

#include <card.h>

#include <deque>

namespace CardLib {
class DECK_DLL_API Deck
{
    std::deque< Card > _cards;

    public:
    Deck();
    Deck(std::deque< Card > &cards);
    void shuffle();
    Card *draw();
    void insert(Card *card);
    void append(Deck &deck);

    bool operator==(const Deck &deck) const;
    std::string to_string() const;

    unsigned int size() const
    {
        return static_cast<unsigned int>(_cards.size());
    }
};
}

#endif // DECK_H
