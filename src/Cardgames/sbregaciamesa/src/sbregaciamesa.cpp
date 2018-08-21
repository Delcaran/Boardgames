#include "Sbregaciamesa.h"

#include <card.h>

#include <iostream>

Sbregaciamesa::Sbregaciamesa() : _player_one_turn(true), _estrai_max(0), _estratte(0)
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

bool Sbregaciamesa::ha_punti(const CardLib::Card *card)
{
    return (card->points() > 0);
}

unsigned int Sbregaciamesa::play_hand(unsigned int &mano)
{
    CardLib::Deck *deck = NULL;
    CardLib::Deck *other_deck = NULL;
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
    ++mano;

    // Check di coerenza
    if ((deck->size()) + other_deck->size() + _tallone.size() != 40)
    {
      // ERRORE molto grave
      return 3;
    }

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

            if (deck->size() == 0)
            {
              // giocatore attuale ha finito le carte e quindi perso
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

            _player_one_turn = !_player_one_turn;
          }
        }
      }
    }
    
    return 0;
}

bool Sbregaciamesa::operator==(const Sbregaciamesa &game) const
{
  bool uno = _player_one == game._player_one;
  bool due = _player_two == game._player_two;
  bool tallone = _tallone == game._tallone;
  bool turno = _player_one_turn == game._player_one_turn;
  return uno && due && tallone && turno;
}

bool Sbregaciamesa::compare(const std::string &gamestring) const
{
  return to_string() == gamestring;
}

std::string Sbregaciamesa::to_string() const
{
  std::ostringstream oss;
  oss << _player_one_turn << "#" << _player_one.to_string() << "#" << _player_two.to_string() << "#" << _tallone.to_string();
  return oss.str();
}