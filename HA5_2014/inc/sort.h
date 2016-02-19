#ifndef SORT_H
#define SORT_H

// Funktion die prueft ob ein Array von INT-Werten sortier mit Hilfe der
// Relation kleiner gleich. Der Vorgänger soll kleiner oder gleich dem
// Nachfolger sein. Es wird dabei nur per Parametereingabe nur ein Teilbereich
// des Array betrachtet. Als Rueckgabe liefert die Funktion true oder false.
bool isSorted(int         *array, // Array von INT-Werten
              unsigned int first, // Anfangindex des Pruefbereichs
              unsigned int end);  // 1 weiter als das letzte gepruefte

// Funktion die einen Teilbereich eines Arrays mit dem Algorithmus der
// Blasensortierung sortiert. Als Rueckgabewert dienen wieder true oder false.
bool bubbleSort(int         *array,
                unsigned int first,
                unsigned int end);

// Funktion die eine Teilbreich eines Array mithilfe des Algorithmus für
// Sortierung durch Auswahl sortiert. Parameteruebergabe wie bei den anderen
// Funktionen, genauso wie die Rueckgabe.
bool selectionSort(int         *array,
                   unsigned int first,
                   unsigned int end);

// Funktion die eine Teilbreich eines Array mithilfe des Algorithmus für
// Sortierung durch Einfügen sortiert. Parameteruebergabe wie bei den anderen
// Funktionen, genauso wie die Rueckgabe.
bool insertSort(int         *array,
                unsigned int first,
                unsigned int end);

// Funktion die eine Teilbreich eines Array mithilfe des Algorithmus für
// QuickSort sortiert. Parameteruebergabe wie bei den anderen Funktionen.
void quickSort(int         *array,
               unsigned int first,
               unsigned int end);

#endif // ifndef SORT_H
