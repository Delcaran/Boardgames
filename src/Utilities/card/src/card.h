#ifndef CARD_H
#define CARD_H

#ifdef Card_EXPORTS
#define CARD_DLL_API __declspec(dllexport) 
#else
#define CARD_DLL_API __declspec(dllimport) 
#endif

#include <string>
#include <sstream>

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

    bool operator==(const Card& c) const
    {
      return (_name == c._name && _points == c._points);
    }

    std::string to_string() const
    {
      std::ostringstream oss;
      oss << _name << ":" << _points;
      return oss.str();
    }
};
}

#endif // CARD_H
