#ifndef SBREGACAMESA_H
#define SBREGACAMESA_H

#ifdef Sbregacamesa_EXPORTS
#define SBREGACAMESA_DLL_API __declspec(dllexport) 
#else
#define SBREGACAMESA_DLL_API __declspec(dllimport) 
#endif

#include <deck.h>

class SBREGACAMESA_DLL_API Sbregacamesa
{
    CardLib::Deck _player_one, _player_two, _tallone;
    bool _player_one_turn;
    unsigned int _estrai_max;
    unsigned int _estratte;

    bool ha_punti(const CardLib::Card *card);

    public:
    Sbregacamesa();

    /*
     * Gioca una mano basandosi sulla mano precedente
     * @return 0 o il giocatore vincente
     */
    unsigned int play_hand();
};

#endif // SBREGACAMESA_H
