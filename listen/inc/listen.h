// listen.h am Beispiel einer Lagerverwaltung

// Konstanten
const int MAX_NAMENSLAENGE = 40;

// Typendefinitionen für meine Artikelspezifikatioen
typedef char         Name[MAX_NAMENSLAENGE];
typedef unsigned int Artikelnummer;
typedef unsigned int Preis; // Preis in EuroCent

// Datentyp für meine Artikele
struct Artikel {
  Artikelnummer artikelnummer;
  Name          name;
  Preis         PreisInCent;
};

// Datentyp für mein Artiekelliste, welches mit dem struct Artikel gefüllt
// werden soll.
struct Lager;

// Definition für meinen Pointer der immer auf das nächste GLied zeigt
typedef Lager *PLager;

struct Lager {
  Artikel artikel;
  PLager  succ; // Successor ( = Nachfolger)
};

struct List {
  PLager first;
  PLager last;
};

// Funktionen für den Umgang mit Listen

// Initialisierung der Liste, first und last Pointer werden auf nullptr
void initializeList(List *);

// Einfügefunktionen
// Einfügen eines Elements am Anfang der Liste
bool insert0(List *, Artikel);

// Einfügen am Ende
bool insertLast(List *, Artikel);
