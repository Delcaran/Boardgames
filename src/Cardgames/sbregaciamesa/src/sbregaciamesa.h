#ifndef Sbregaciamesa_H
#define Sbregaciamesa_H

#ifdef Sbregaciamesa_EXPORTS
#define Sbregaciamesa_DLL_API __declspec(dllexport) 
#else
#define Sbregaciamesa_DLL_API __declspec(dllimport) 
#endif

#include <deck.h>

class Sbregaciamesa_DLL_API Sbregaciamesa
{
    CardLib::Deck _player_one, _player_two, _tallone;
    bool _player_one_turn;
    unsigned int _estrai_max;
    unsigned int _estratte;

    bool ha_punti(const CardLib::Card *card);

    public:
    Sbregaciamesa();

    /*
     * Gioca una mano basandosi sulla mano precedente
     * @return 0 o il giocatore vincente
     */
    unsigned int play_hand(unsigned int &mano);

    bool operator==(const Sbregaciamesa &game) const;
    bool compare(const std::string &gamestring) const;
    std::string to_string() const;
};

#endif // Sbregaciamesa_H
