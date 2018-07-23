#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
    int _points;
    std::string _name;

    public:
    Card(const std::string &name, const int points);
    Card(const int points);
    Card();

    int points() const
    {
        return _points;
    }
};

#endif // CARD_H
