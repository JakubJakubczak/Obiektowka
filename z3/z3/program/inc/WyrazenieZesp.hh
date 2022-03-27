#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"


/*
* Modeluje zbior operatorow arytmetycznych.
 */
 enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
  //atrybuty
  public:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
  //metody
  LZespolona Oblicz(WyrazenieZesp  WyrZ);   // obliczanie wyrazenia zespolonego
  
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream& operator << (std::ostream &StrmWe, Operator &Op);  // przeciazenie wyswietlania operatora
std::istream& operator >> (std::istream &StrmWe, Operator &Op);  // przeciazenie wczytywania operatora
std::istream &operator>>(std::istream &wejs, WyrazenieZesp &WyrZ); // przeciazenie wczytywania wyrazenia zespolonego
std::ostream &operator<<(std::ostream &wyj, WyrazenieZesp &WyrZ); // przeciazenie wyswietlania wyrazenia zespolonego

#endif
