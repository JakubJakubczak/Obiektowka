#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"


/*****************************************************************************************
 *   Klasa UkladRownanLiniowych zawiera obiekt klasy Macierz oraz obiekt klasy Wektor.
 *   Klasa umozliwia zamiane wybranej kolumny macierzy z wektorem wyrazow wolnych,
 *   transponowanie macierzy w ukladzie rownan, oraz wyswietlanie i wczytywanie ukladu
 *   rownan.    
 ****************************************************************************************/
class UkladRownanLiniowych {
  Macierz Mac;   
  Wektor Wek;   // wektor wyrazow wolnych

  /*  Funkcja zamianaKolumny zamienia kolumne macierzy na wektor wyrazow wolnych
   *  
   *  Dane wejsciowe:
   *  kolumna - kolumna ktora chcemy zamienic
   *
   *  Dane wyjsciowe:
   *  temp - macierz z zamieniona kolumna na wektor wyrazu wolnego 
   */
  
  Macierz zamianaKolumny(int kolumna) const;
  // metody ubliczne
public:
  /*  Funkcja transponuje (tylko!)macierz w klasie UkladRownanLiniowych
   *  
   *  Dane wejsciowe:
   *  brak
   *
   *  Dane wyjsciowe:
   *  temp1 - UkladRownanLiniowych z transponowana macierza
   */
  UkladRownanLiniowych transpozycja () const;
   /*  Funkcja RozwUklRow rozwiazuje uklad rownan metoda Cramera i wypisuje rozwiazania
   *  
   *  Dane wejsciowe:
   *  brak
   *
   *  Dane wyjsciowe:
   *  wyniki - wektor zawierajacy rozwiazania ukladu
   */
  Wektor RozwUklRow();
  /*  Funkcja BladObl wyznacza blad obliczen macierzy w postaci Wektora i jego dlugosci
   *  Funkcja wypisuje wektor bledu i dlugosc tego wektora.   
   *  
   *  Dane wejsciowe:
   *  Wyn - Wynik obliczonej macierzy w postaci wektora
   *
   *  Dane wyjsciowe:
   *  Blad - Blad obliczen zapisany w postaci wektora
   */
  Wektor BladObl(Wektor &Wyn);
  // zaprzyjaznienie przeciazenia strumieni 
  friend std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
  friend std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);
};


/*
 *  Przeciazenie input dla klasy UkladRownanLiniowych, po lewej stronie strumien, po prawej obiekt.
 *  Wczytuje elementy klasy.
 *
 *  Dane wejsciowe:
 *
 *  Strm - strumien
 *  UklRown - obiekt klasy UkladRownanLiniowych
 *
 *  Dane wyjsciowe:
 *  Strm - zwraca strumien
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);



/*
 *  Przeciazenie output dla klasy UkladRownanLiniowych, po lewej stronie strumien, po prawej obiekt.
 *  Wyswietla elementy klasy.
 *
 *  Dane wejsciowe:
 *
 *  Strm - strumien
 *  UklRown - obiekt klasy UkladRownanLiniowych
 *
 *  Dane wyjsciowe:
 *  Strm - zwraca strumien
 */

std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych  &UklRown);




#endif
