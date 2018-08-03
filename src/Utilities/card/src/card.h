#ifndef CARD_H
#define CARD_H

#ifdef Card_EXPORTS
#define CARD_DLL_API __declspec(dllexport) 
#else
#define CARD_DLL_API __declspec(dllimport) 
#endif

#include <string>

namespace CardLib {
class CARD_DLL_API Card
{
    int _points;
    std::string _name;

    public:
    Card(const std::string &name, const int points);
    Card(const int points);
    Card();
    virtual ~Card();

    int points() const
    {
        return _points;
    }
};
}

#endif // CARD_H
