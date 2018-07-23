#include "card.h"

Card::Card(const std::string &name, const int points) : _name(name), _points(points)
{
}

Card::Card(const int points) : _points(points), _name("")
{
}

Card::Card() : _points(0), _name("")
{
}
