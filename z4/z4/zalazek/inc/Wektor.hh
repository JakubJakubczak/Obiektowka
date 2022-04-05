#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  //wspolrzedne wektora
 double  x;
 double  y;
 double  z;
public:  

  //metody
  Wektor operator + (  Wektor  W2) const;
  /*
     Przeciazenie operatora dodawnia dla wektorow

     Dane wejsciowe:
     Wektor W1 
     Wektor W2

     Dane wyjsciowe:
     Zwraca wynik dodawania wektorow
   */
  Wektor operator - (  Wektor  W2) const;
   /*
     Przeciazenie operatora odejmowania dla wektorow

     Dane wejsciowe:
     Wektor W1 
     Wektor W2

     Dane wyjsciowe:
     Zwraca wynik odejmowania wektorow
   */
  Wektor operator * (  Wektor  W2) const;
   /*
     Przeciazenie operatora mnozenia dla wektorow

     Dane wejsciowe:
     Wektor W1 
     Wektor W2

     Dane wyjsciowe:
     Zwraca wynik mnozenia wektorow
   */
  Wektor operator / (  Wektor  W2) const;
   /*
     Przeciazenie operatora dzielenia dla wektorow

     Dane wejsciowe:
     Wektor W1 
     Wektor W2

     Dane wyjsciowe:
     Zwraca wynik dzielenia wektorow
   */
  Wektor operator * (double mnoznik) const;
    /*
     Przeciazenie operatora mnozenia wektora przez liczbe

     Dane wejsciowe:
     Wektor W1 
     double mnoznik 

     Dane wyjsciowe:
     Zwraca wynik mnozenia wektora przez liczbe
   */
  Wektor operator / (double dzielnik) const;

    /*
     Przeciazenie operatora dzielenia wektora przez liczbe

     Dane wejsciowe:
     Wektor W1 
     double dzielnik

     Dane wyjsciowe:
     Zwraca wynik dzielenia wektora przez liczbe
   */

  //zaprzyjaznienie klasy wektor z funkcjami operujacymi na strumieniach
 friend std::istream& operator >> (std::istream &Strm, Wektor &Wek);
 friend std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);
 
};


/*
 Ta funkcja to przeciazenie strumienia wejsciowego dla wektorow trzywymiarowych.
 
 Dane wejsciowe:
 Strm - strumien wejsciowy
 Wek - wektor

 Dane wyjsciowe:
 Zwraca strumien Strm;
 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);


/*
 Ta funkcja to przeciazenie strumienia wejsciowego dla wektorow trzywymiarowych.
 
 Dane wejsciowe:
 Strm - strumien wejsciowy
 Wek - wektor
 
 Dane wyjsciowe:
 Wypisuje wektor Wek na strumien Strm
 Zwraca strumien Strm
 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
