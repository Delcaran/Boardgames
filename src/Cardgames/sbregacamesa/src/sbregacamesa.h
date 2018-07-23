#ifndef SBREGACAMESA_H
#define SBREGACAMESA_H

#include <deck.h>

class Sbregacamesa
{
    Deck _player_one, _player_two, _tallone;
    Card *_requested;
    bool _player_one_turn;

    bool ha_punti(const Card *card);

    public:
    Sbregacamesa();

    /*
     * Gioca una mano basandosi sulla mano precedente
     * @return 0 o il giocatore vincente
     */
    unsigned int play_hand();
};

#endif // SBREGACAMESA_H
