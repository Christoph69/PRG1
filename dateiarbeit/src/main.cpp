// main.cpp Dateiarbeit, endlich mal seine Daten speichern...
#include <iostream>

const int PRODUKTANZAHL = 5;
const int MAX_NAME      = 60;

int main(int argc, char const *argv[]) {
  FILE *hFile = fopen("Produktnamen.txt", "w");

  // Eingabe von Produktnamen

  char produktnamen[PRODUKTANZAHL][MAX_NAME];

  for (int i = 0; i < PRODUKTANZAHL; i++) {
    std::cout << "Eingabe Produktname: ";
    std::cin.getline(produktnamen[i][MAX_NAME], MAX_NAME);
  }

  // WICHTIG: Wir müssen prüfen ob das funktioniert hat! Wie? Woran erkennen wir
  // es?

  if (hFile != nullptr) {
    // Eröffnung hat funktioniert - Datei steht zur Verfügung
    // Zeichenkette werden in die Datei ausgegeben
    for (int i = 0; i < PRODUKTANZAHL; i++) {
      fprintf(hFile, "%s\n", produktnamen[i]);
    }

    // Dateiwiederschliesen
    fclose(hFile);
  }
  else {
    // Eröffnung gescheitert
    std::cout << "Es konnte keine Datei geöffnet werden! Wegen Fehler NR. " <<
      errno << std::endl;
  }

  // Datei wieder einlesen
  hFile = fopen("Produktnamen.txt", "w");

  if (hFile != nullptr) {
    // Eröffnung hat funktioniert - Datei steht zur Verfügung
    for (int i = 0; i < PRODUKTANZAHL; i++) {
      fscanf(hFile, "%s\n", produktnamen[i]);
    }

    // Dateiwiederschliesen
    fclose(hFile);
  }
  else {
    // Eröffnung gescheitert
    std::cout << "Es konnte keine Datei geöffnet werden! Wegen Fehler NR. " <<
      errno << std::endl;
  }

  return 0;
}
