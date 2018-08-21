#include <iostream>
#include <map>
#include <set>

#include <Sbregaciamesa.h>

class Nodo
{
  std::string _name;
public:
  std::set<unsigned int> _partite;
  std::set < Nodo* > _ingressi;
  std::set < Nodo* > _uscite;

  Nodo()
  {
    _name = "";
    _partite.clear();
    _ingressi.clear();
    _uscite.clear();
  }
  Nodo(const std::string &name) : _name(name)
  {
    _partite.clear();
    _ingressi.clear();
    _uscite.clear();
  }

  ~Nodo()
  {
    _partite.clear();
    _ingressi.clear();
    _uscite.clear();
  }
};

int main(int argc, char *argv[])
{
  std::map<std::string, Nodo> mani;
  unsigned int num_partite = 10;
  if (argc > 1)
  {
    num_partite = atoi(argv[1]);
  }
  double results[4] = { 0 }; // 0: # loops, 1: # vittorie 1, 2: # vittore 2, 3: # errori
  for (unsigned int partita = 0; partita < num_partite; partita++)
  {
    Sbregaciamesa nuovo_gioco;

    unsigned int vincitore = 0;
    unsigned int mano = 0;
    bool old_match_found = false;
    while (!old_match_found && !vincitore)
    {
      std::string stringa_inizio = nuovo_gioco.to_string();

      vincitore = nuovo_gioco.play_hand(mano);

      std::string stringa_fine = nuovo_gioco.to_string();
      std::map<std::string, Nodo>::iterator itin = mani.find(stringa_inizio);
      std::map<std::string, Nodo>::iterator itfi = mani.find(stringa_fine);
      Nodo *inizio, *fine;
      if (itin != mani.end())
      {
        // questa mano era gia' presente: prendo l'indirizzo
        // NB: questo caso sara' praticamente sempre vero
        inizio = &itin->second;
      }
      else
      {
        // nuova mano: aggiungo alla lista e prendo l'indirizzo
        mani[stringa_inizio] = Nodo(stringa_inizio);
        inizio = &mani[stringa_inizio];
      }

      if (itfi != mani.end() && itfi != itin)
      {
        // questa mano era gia' presente e non e' quella di partenza: prendo l'indirizzo
        fine = &itfi->second;
        old_match_found = true;
        if (fine->_partite.find(partita) != fine->_partite.end())
        {
          //std::cout << "Trovato loop semplice! Partita infinita?" << std::endl;
          results[vincitore]++; // aumento contatore dei loop
        }
      }
      else
      {
        // nuova mano: aggiungo alla lista e prendo l'indirizzo
        mani[stringa_fine] = Nodo(stringa_fine);
        fine = &mani[stringa_fine];
      }

      inizio->_uscite.insert(fine);
      inizio->_partite.insert(partita);
      fine->_ingressi.insert(inizio);
      fine->_partite.insert(partita);
    }
    results[vincitore]++;
    /*
    std::cout << "Partita " << partita + 1 << " : ";
    if (vincitore != 0)
    {
      std::cout << "vince " << vincitore << " dopo " << mano << " mani" << std::endl;
    }
    if (old_match_found)
    {
      std::cout << "trovata una mano gia' giocata dopo " << mano << " mani, termino" << std::endl;
    }
    */
  }

  std::cout << "Loops semplici : " << results[0] << std::endl;
  std::cout << "Vittorie Giocatore 1 : " << results[1] << " ( " << ((results[1] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Vittorie Giocatore 2 : " << results[2] << " ( " << ((results[2] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Errori : " << results[3] << std::endl;

  return 0;
}