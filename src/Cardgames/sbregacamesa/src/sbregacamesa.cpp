#include "sbregacamesa.h"

#include <card.h>

Sbregacamesa::Sbregacamesa() : _requested(NULL), _player_one_turn(true)
{
    unsigned int num_assi = 0;
    unsigned int num_due = 0;
    unsigned int num_tre = 0;
    Deck deck;
    for (int carta = 0; carta < 40; ++carta)
    {
        int punti = 0;
        if (num_assi < 4)
        {
            punti = 1;
            ++num_assi;
        }
        else if (num_due < 4)
        {
            punti = 2;
            ++num_due;
        }
        else if (num_tre < 4)
        {
            punti = 3;
            ++num_tre;
        }
        Card card(punti);
        deck.insert(&card);
    }
    deck.shuffle();
}

bool Sbregacamesa::ha_punti(const Card *card)
{
    return (card->points() > 0);
}

unsigned int Sbregacamesa::play_hand()
{
    Deck *deck = NULL;
    Deck *other_deck = NULL;
    if (_player_one_turn)
    {
        deck = &_player_one;
        other_deck = &_player_two;
    }
    else
    {
        deck = &_player_two;
        other_deck = &_player_one;
    }
    if (_requested != NULL)
    {
        int requested = _requested->points();
        if (requested > 0)
        {
            for (int c = 0; c < requested; ++c)
            {
                Card *drawed = deck->draw();
                if (drawed)
                {
                    _tallone.insert(drawed);
                    if (ha_punti(drawed))
                    {
                        _requested = drawed;
                        _player_one_turn = !_player_one_turn;
                        return 0;
                    }
                }
                else
                {
                    // giocatore corrente ha finito le carte, quindi ha perso
                    if (_player_one_turn)
                    {
                        return 2;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            // se arrivo qui sono state giocate tutte le carte richieste senza trovarne altre con punti
            other_deck->append(_tallone);
            _requested = NULL;
            if (deck->size() == 0)
            {
                if (_player_one_turn)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            // nessuna carta con punti richiesta, ne gioco una se ne ho
            Card *drawed = deck->draw();
            if (drawed)
            {
                _tallone.insert(drawed);
                _requested = drawed;
                _player_one_turn = !_player_one_turn;
            }
            else
            {
                // giocatore corrente ha finito le carte, quindi ha perso
                if (_player_one_turn)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        _requested = deck->draw();
        _player_one_turn = !_player_one_turn;
    }
    return 0;
}
