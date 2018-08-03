#include "sbregacamesa.h"

#include <card.h>

#include <iostream>

Sbregacamesa::Sbregacamesa() : _player_one_turn(true), _estrai_max(0), _estratte(0)
{
    unsigned int num_assi = 0;
    unsigned int num_due = 0;
    unsigned int num_tre = 0;
    CardLib::Deck deck;
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
        CardLib::Card card(punti);
        deck.insert(&card);
    }
    deck.shuffle();
    while (deck.size())
    {
      _player_one.insert(deck.draw());
      _player_two.insert(deck.draw());
    }
}

bool Sbregacamesa::ha_punti(const CardLib::Card *card)
{
    return (card->points() > 0);
}

unsigned int Sbregacamesa::play_hand()
{
  static unsigned int mano = 0;
    CardLib::Deck *deck = NULL;
    CardLib::Deck *other_deck = NULL;
    std::cout << std::endl << "Mano " << mano
      << " : 1 = " << _player_one.size()
      << "   2 = " << _player_two.size()
      << "   T = " << _tallone.size();
    if (_player_one_turn)
    {
      std::cout << ", ---- 1 gioca un ";
        deck = &_player_one;
        other_deck = &_player_two;
    }
    else
    {
      std::cout << ", ---- 2 gioca un ";
        deck = &_player_two;
        other_deck = &_player_one;
    }
    ++mano;

    if (deck->size() == 0)
    {
      // giocatore attuale ha perso
      if (_player_one_turn)
      {
        // vince player 2
        return 2;
      }
      else
      {
        // vince player 1
        return 1;
      }
    } 
    else 
    {
      CardLib::Card *estratta = deck->draw();
      _tallone.insert(estratta);
      std::cout << estratta->points();
      if (_estrai_max == 0)
      {
        // si procede ad oltranza
        if (ha_punti(estratta))
        {
          _estrai_max = estratta->points();
        }
        _player_one_turn = !_player_one_turn;
      }
      else
      {
        if (ha_punti(estratta))
        {
          // ho estratto una carta con punti, resetto il contatore e tocca all'altro
          _estrai_max = estratta->points();
          _estratte = 0;
          _player_one_turn = !_player_one_turn;
        }
        else
        {
          // carta senza punti, incremento il contatore
          ++_estratte;
          if (_estratte == _estrai_max)
          {
            // l'avversario raccoglie il tallone
            other_deck->append(_tallone);
            _estrai_max = 0;
            _estratte = 0;
            _player_one_turn = !_player_one_turn;
          }
        }
      }
    }
    
    return 0;
}
