// listen.cpp
#include "../inc/listen.h"
#include <iostream>

// Initialisierung der Liste
void initializeList(List *list) {
  list->first = nullptr;
  list->last  = nullptr;
}

////////////////////
// Einfügefunktionen
////////////////////

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

  if (list->last == nullptr) list->last = pLager;
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

  for (int i = 0; i < pos - 1; i++) {
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

//////////////////////
// Entfernenfunktionen
//////////////////////

bool remove0(List *list) {
  bool gueltig = list->first != nullptr;

  if (gueltig) {
    PLager freigabe = list->first;
    list->first = freigabe->succ;
    delete freigabe;
  }
  return gueltig;
}

bool removePos(List *list, unsigned int pos) {
  bool   gueltig  = list->first != nullptr;
  PLager speicher = list->first;

  for (int i = 0; i < pos - 1; i++) {
    if (speicher != nullptr) speicher = speicher->succ;
    else gueltig = false;
  }
  PLager freigabe = speicher;
  speicher->succ = freigabe->succ->succ;
  delete freigabe;
  return gueltig;
}

//////////////////////////////
// Funktion für struct Artikel
//////////////////////////////

// Eingabe
Artikel insertArtikel() {
  Artikel artikel;
  std::cout << "Eingabe Artikelnummer: ";
  std::cin >> artikel.artikelnummer;
  std::cout << "Eingabe Artikelname: ";
  std::cin >> artikel.name;
  std::cout << "Eingabe Artikelpreis: ";
  std::cin >> artikel.PreisInCent;
  std::cout << std::endl;

  return artikel;
}

// Ausgabe
void outputList(List *list) {
  PLager speicher = list->first;

  if (list->first != nullptr) {
    do {
      std::cout << "Artikelnummer: " << speicher->artikel.artikelnummer <<
        std::endl;
      std::cout << "Artikelname  : " << speicher->artikel.name << std::endl;
      std::cout << "Artikelpreis : " << speicher->artikel.PreisInCent <<
        std::endl << std::endl;
      speicher = speicher->succ;
    } while (speicher != nullptr);
  }
}
