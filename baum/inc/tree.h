#ifndef TREE_H
#define TREE_H
#include <cstdio>

// Datenstruktur für einen Knoten bei einem Baum
struct Knoten {
  int     data;
  Knoten *left, *right;
};

// Funktionen für dem Umgang mit dem Baum

// zum einfuegen eines neuen Knotens in den Baum
bool insertNode(Knoten **wurzel,
                int      data);

// zum ausgeben des Baumes
void outputTree(Knoten **wurzel);

#endif // ifndef TREE_H
