#include <iostream>
#include <cstdio>
#include <map>
#include <set>

#include <Sbregaciamesa.h>

class Nodo
{
  std::string _name;
public:
  bool _visited;
  std::set<unsigned int> _partite;
  std::set < Nodo* > _ingressi;
  std::set < Nodo* > _uscite;

  Nodo()
  {
    _name = "";
    _visited = false;
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
typedef std::set < Nodo* > insieme_nodi_t;
typedef insieme_nodi_t::iterator insieme_nodi_it;

bool parse_node(Nodo* radix, insieme_nodi_t &stack_ricorsione)
{
  if (!radix->_visited)
  {
    // marco il nodo corrente come visitato e lo aggiungo allo stack di ricorsione
    radix->_visited = true;
    stack_ricorsione.insert(radix);

    // ricorro in tutti i vertici adiacenti
    // uscite
    for (insieme_nodi_it it = radix->_uscite.begin(); it != radix->_uscite.end(); ++it)
    {
      Nodo *nodo = (*it);
      if (!nodo->_visited && parse_node(nodo, stack_ricorsione))
      {
        return true;
      }
      else if (stack_ricorsione.find(nodo) != stack_ricorsione.end())
      {
        return true;
      }
    }

  }
  stack_ricorsione.erase(radix);
  return false;
}

void print_spinning()
{
  static unsigned int count = 0;
  switch (count)
  {
    case 0: printf("\b|"); break;
    case 1: printf("\b/"); break;
    case 2: printf("\b-"); break;
    case 3: printf("\b\\"); break;
    default:
      count = 0;
  }
  fflush(stdout);
}

int main(int argc, char *argv[])
{
  std::map<std::string, Nodo> mani;
  unsigned int num_partite = 10;
  if (argc > 1)
  {
    num_partite = atoi(argv[1]);
  }
  double results[4] = { 0 }; // 0: # loops, 1: # vittorie 1, 2: # vittore 2, 3: # errori
  std::cout << "Partite in corso" << std::endl;

  for (unsigned int partita = 0; partita < num_partite; partita++)
  {
    Sbregaciamesa nuovo_gioco;

    unsigned int vincitore = 0;
    unsigned int mano = 0;
    bool old_match_found = false;
    while (!old_match_found && !vincitore)
    {
      std::string stringa_inizio = nuovo_gioco.to_string();
      //print_spinning();
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
    std::cout << ".";
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

  std::cout << std::endl;
  std::cout << "Loop semplici : " << results[0] << std::endl;
  std::cout << "Vittorie Giocatore 1 : " << results[1] << " ( " << ((results[1] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Vittorie Giocatore 2 : " << results[2] << " ( " << ((results[2] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Errori : " << results[3] << std::endl;

  std::cout << "Avvio ricerca di loop complessi..." << std::endl;

  // cerco le radici
  insieme_nodi_t radixes;
  for (std::map<std::string, Nodo>::iterator nodo = mani.begin(); nodo != mani.end(); ++nodo)
  {
    if (nodo->second._ingressi.size() == 0)
    {
      radixes.insert(&nodo->second);
    }
  }

  // parso il grafo
  for (insieme_nodi_it radice = radixes.begin(); radice != radixes.end(); ++radice)
  {
    insieme_nodi_t nodi;
    if (parse_node(*radice, nodi))
    {
      std::cout << "Ho trovato un loop" << std::endl;
    }
  }

  return 0;
}

