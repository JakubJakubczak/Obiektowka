#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/******************************************************************************************
 *  Klasa macierz jest klasą sluzaca do przechowywania macierzy i operacji na nich.
 *  Klasa zawiera w sobie tablice obiektow klasy Wektor o rozmiarze ROZMIAR, funkcje 
 *  potrzebne do wyznaczania wyznacznika macierzy, mozliwosc transpozycji macierz y 
 *  oraz funkcjonalnosc mnozenia macierzy przez wektor. W klasie zostały przeciazane
 *  operatory () i [] dla ulatwienia poslugiwania sie obiektami.
 *
 *  Z klasą zostały zaprzyjaznione funkcje wczytywania i wyswietlanai macierzy
 *
 *****************************************************************************************/

class Macierz {
  // Atrybuty prywante
  Wektor _Wiersz[ROZMIAR];
  // Metody prywatne - przyklad
  double wyznacznikEliminacjaGaussa();
  double wymnozElementyDiagonali() const;
  bool macierzTrojkatna(int &Parzystosc);
  bool zamienWiersze (unsigned int biezacyWiersz);
  void zerujKolumne(unsigned int biezacyWiersz);
public:
  // Metody publiczne - przyklad
  // przeciazenie operatorow () i [] dla wygody korzystania
  const Wektor& operator[ ] (int Wi) const { return _Wiersz[Wi]; }    // zwraca typ  Wektor
  Wektor& operator[ ] (int Wi) { return _Wiersz[Wi]; }
  const double operator( ) (int Wi, int Ko) const {return _Wiersz[Wi][Ko];}  // zwraca typ double
  double& operator( ) (int Wi, int Ko) {return _Wiersz[Wi][Ko];}
  

  double wyznacznik () const;
  Macierz transpozycja() const;

  // zaprzyjaznienie przeciazen na strumieniach
  friend std::istream& operator >> (std::istream &Strm, Macierz &Mac);
  friend std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);
};


Wektor operator*(Macierz M, Wektor W);
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
