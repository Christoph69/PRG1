// listen.cpp
#include "../inc/listen.h"

// Einfügefunktionen
bool insert0(List *first, Artikel artikel) {
  // Speicherplatz für neuen Artikel reservieren
  PLager pLager  = new Lager;
  bool   gueltig = pLager != nullptr;

  if (gueltig) {
    // den neu erstellten Lagerplatz mit meinem übergebenem Artikel befüllen
    pLager->artikel = artikel;

    // dem neuem Artikelglied den Nachfolger anhängen
    pLager->succ = first->first;

    // dem Listenanker das neue Glied als Anfang zuweisen
    first->first = pLager;
  }
  return gueltig;
}
