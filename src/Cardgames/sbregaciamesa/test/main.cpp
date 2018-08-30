/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "graphwidget.h"
#include <sbregaciamesa.h>

#include <QApplication>
#include <QTime>
#include <QMainWindow>

#include <iostream>
#include <set>

/*
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
*/

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  GraphWidget *widget = new GraphWidget;
  QMainWindow mainWindow;
  mainWindow.setCentralWidget(widget);

  mainWindow.show();

  std::set<std::string> mani;
  unsigned int num_partite = 2;
  if (argc > 1)
  {
    num_partite = atoi(argv[1]);
  }
  double results[4] = { 0 }; // 0: # loops, 1: # vittorie 1, 2: # vittore 2, 3: # errori
  std::cout << "Partite in corso" << std::endl;

  for (unsigned int partita = 0; partita < num_partite; partita++)
  {
    Sbregaciamesa nuovo_gioco;
    std::string str = nuovo_gioco.to_string();
    if (mani.find(str) != mani.end())
    {
      // partita gia' giocata
      continue;
    }
    mani.insert(str);
    widget->addNode(&str); // mostro la mano iniziale nella gui

    unsigned int vincitore = 0;
    unsigned int mano = 0;
    bool old_match_found = false;
    while (!old_match_found && !vincitore)
    {
      std::string prev = nuovo_gioco.to_string();
      vincitore = nuovo_gioco.play_hand(mano);
      // a questo punto nuovo_gioco rappresenta una nuova mano derivata da precedente
      std::string next = nuovo_gioco.to_string();
      old_match_found = (mani.find(next) != mani.end()); // controllo se si tratta di una mano gia' giocata
      if (!old_match_found)
      {
        // le mani nuove le aggiungo alla lista e le mostro nella gui
        widget->addNode(&next, &prev);
        mani.insert(next);
      }
    }
    results[vincitore]++;
    std::cout << ".";
  }
  // ora disegno i nodi

  std::cout << std::endl;
  std::cout << "Loop semplici : " << results[0] << std::endl;
  std::cout << "Vittorie Giocatore 1 : " << results[1] << " ( " << ((results[1] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Vittorie Giocatore 2 : " << results[2] << " ( " << ((results[2] / num_partite) * 100.0) << " % )" << std::endl;
  std::cout << "Errori : " << results[3] << std::endl;

  std::cout << "Avvio ricerca di loop complessi..." << std::endl;
  /*
  if (has_loops(mani))
  {
    std::cout << "Esiste almeno una partita infinita" << std::endl;
  }
  */

  return app.exec();
}