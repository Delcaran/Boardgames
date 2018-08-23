#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <list>

#include <Sbregaciamesa.h>

class Vertex
{
  std::string _name;
public:
  bool _visited;
  std::set<unsigned int> _partite;
  std::set<Vertex*> _input; // genitori
  std::set<Vertex*> _output; // figli

  Vertex()
  {
    _name = "";
    _visited = false;
    _partite.clear();
    _input.clear();
    _output.clear();
  }
  Vertex(const std::string &name) : _name(name)
  {
    _partite.clear();
    _input.clear();
    _output.clear();
  }

  ~Vertex()
  {
    _partite.clear();
    _input.clear();
    _output.clear();
  }

  bool Vertex::operator==(const Vertex &v) const
  {
    return _name == v._name;
  }
};

bool has_loops(std::map<std::string, Vertex> &vertici)
{
  // Sfrutto l'algoritmo di Kahn per l'ordinamento topologico per individuare cicli
  std::list<Vertex*> radixes; // nodi senza input
  // riempio la lista delle radici
  for (std::map<std::string, Vertex>::iterator nodo = vertici.begin(); nodo != vertici.end(); ++nodo)
  {
    if (nodo->second._input.size() == 0)
    {
      radixes.push_back(&nodo->second);
    }
  }
  // partendo dai nodi senza input, cancello gli input da tutti i figli
  while (!radixes.empty())
  {
    Vertex* n = radixes.front();
    // rimuovo n dall'elenco degli ingressi nei figli di n
    for (std::set<Vertex*>::iterator figlio = n->_output.begin(); figlio != n->_output.end(); ++figlio)
    {
      (*figlio)->_input.erase((*figlio)->_input.find(n));
      if ((*figlio)->_input.empty())
      {
        // se il figlio non ha input, va nell'elenco delle radici
        radixes.push_back(*figlio);
      }
    }
    radixes.pop_front();
  }
  // se ora esistono nodi con input, vuol dire che esiste almeno un ciclo
  for (std::map<std::string, Vertex>::iterator nodo = vertici.begin(); nodo != vertici.end(); ++nodo)
  {
    if (nodo->second._input.size() != 0)
    {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  std::map<std::string, Vertex> mani;
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
      std::map<std::string, Vertex>::iterator itin = mani.find(stringa_inizio);
      std::map<std::string, Vertex>::iterator itfi = mani.find(stringa_fine);
      Vertex *inizio, *fine;
      if (itin != mani.end())
      {
        // questa mano era gia' presente: prendo l'indirizzo
        // NB: questo caso sara' praticamente sempre vero
        inizio = &itin->second;
      }
      else
      {
        // nuova mano: aggiungo alla lista e prendo l'indirizzo
        mani[stringa_inizio] = Vertex(stringa_inizio);
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
        mani[stringa_fine] = Vertex(stringa_fine);
        fine = &mani[stringa_fine];
      }

      inizio->_output.insert(fine);
      inizio->_partite.insert(partita);
      fine->_input.insert(inizio);
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
  if (has_loops(mani))
  {
    std::cout << "Esiste almeno una partita infinita" << std::endl;
  }

  
  return 0;
}

