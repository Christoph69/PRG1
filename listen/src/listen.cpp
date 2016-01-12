// listen.cpp
#include "../inc/listen.h"

// Initialisierung der Liste
void initializeList(List *list) {
  list->first = nullptr;
  list->last  = nullptr;
}

// Einfügefunktionen
bool insert0(List *list, Artikel artikel) {
  // Speicherplatz für neuen Artikel reservieren
  PLager pLager  = new Lager;
  bool   gueltig = pLager != nullptr;

  if (gueltig) {
    // den neu erstellten Lagerplatz mit meinem übergebenem Artikel befüllen
    pLager->artikel = artikel;

    // dem neuem Artikelglied den Nachfolger anhängen
    pLager->succ = list->first;

    // dem Listenanker das neue Glied als Anfang zuweisen
    list->first = pLager;
  }
  return gueltig;
}

bool insertLast(List *list, Artikel artikel) {
  // Speicherplatz für neuen Artikel reservieren
  PLager pLager  = new Lager;
  bool   gueltig = pLager != nullptr;

  if (gueltig) {
    // neuer Artikel
    pLager->artikel = artikel;

    // da letzter Artikel in der List Pointer auf nullptr
    pLager->succ = nullptr;

    // Pointer der nun vorletzten Elements auf das Letzte Element zeigen lassen
    list->last->succ = pLager;

    // den last-Pointer nun auf das neue letzte Element zeigen lassen
    list->last = pLager;
  }
  return gueltig;
}

bool insertPos(List *list, Artikel artikel, unsigned int pos) {
  // neuer Speicher
  PLager pLager   = new Lager;
  PLager speicher = list->first;
  bool   gueltig  = pLager != nullptr;

  for (int i = 0; i < pos; i++) {
    if (speicher != nullptr) {
      speicher = speicher->succ;
    }
    else gueltig = false;
  }

  if (gueltig) {
    pLager->artikel = artikel;
    pLager->succ    = speicher->succ;
    speicher->succ  = pLager;
  }
  return gueltig;
}
