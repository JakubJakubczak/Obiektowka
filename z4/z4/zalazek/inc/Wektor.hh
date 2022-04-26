#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

#define ROZMIAR 3

/***********************************************************************************************
 *   Jest to klasa Wektor sluzaca do poslugiwania sie wektorem jako tablica o 
 *   rozmiarze ROZMIAR i dokonywania na nim operacji. Klasa zawiera przeciazenia 
 *   podstawowych operatorow matematycznych, mnozenie wektora przez liczbe, dzielenie
 *   go przez liczbe. Zawiera ona rowniez przeciazenie operatora = dla wektora ktorego 
 *   chcemy przyrownac do liczby. Dla wygody poslugiwania sie klasa stworzony 
 *   zostal interfejs poslugiwania sie wspolrzednymi wektora. Posluzyly do tego 
 *   przeciazenia operatora [], jedno zwraca oryginal a drugie kopie.
 *
 *   Do klasy zostaly zaprzyjaznione przeciazenia >> i << by strumienie in/output w prosty 
 *   sposob mogly sie laczyc z wektorem.
 ***********************************************************************************************/
class Wektor {
  //wspolrzedne wektora
  double Wsp[ROZMIAR];
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

   Wektor operator = (double liczba);

  /*
     Przeciazenie operatora rowna sie dla wektora i typu double

     Dane wejsciowe:
     Wektor W
     double liczba

     Dane wyjsciowe:
     Wynik - wypelnia wektor liczba
   */

 
  
  double  operator [](int i) const;
  /*przeciazenie operatora [] pomocne do wygodnego uzytkowania,
    dziala na kopi.
   
    /return Wsp[i]
 */

  double& operator [](int i);
  /*jak wyzej, z zastrzezeniem ze dziala na oryginale */

  
  //zaprzyjaznienie klasy wektor z przeciazeniami operujacymi na strumieniach
 friend std::istream& operator >> (std::istream &Strm, Wektor &Wek);
 friend std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);
 
};


/*
 Ta funkcja to przeciazenie strumienia wejsciowego dla wektorow.
 
 Dane wejsciowe:
 Strm - strumien wejsciowy
 Wek - wektor

 Dane wyjsciowe:
 Zwraca strumien Strm;
 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);


/*
 Ta funkcja to przeciazenie strumienia wejsciowego dla wektorow.
 
 Dane wejsciowe:
 Strm - strumien wejsciowy
 Wek - wektor
 
 Dane wyjsciowe:
 Wypisuje wektor Wek na strumien Strm
 Zwraca strumien Strm
 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
