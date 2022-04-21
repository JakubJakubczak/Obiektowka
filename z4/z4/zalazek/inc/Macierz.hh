#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  // Atrybuty prywante
  Wektor _Kolumna[ROZMIAR];
  // Metody prywatne - przyklad
  double wyznacznikEliminacjaGaussa();
  double wymnozElementyDiagonali() const;
  bool macierzTrojkatna(int &Parzystosc);
  bool zamienKolumny (unsigned int biezacaKolumna);
  void zerujWiersz(unsigned int biezacaKolumna);
public:
  // Metody publiczne - przyklad
  const Wektor& operator[ ] (int Kol) const { return _Kolumna[Kol]; }
  Wektor& operator[ ] (int Kol) { return _Kolumna[Kol]; }
  const double operator( ) (int Wi, int Ko) const {return _Kolumna[Ko][Wi];}
  double& operator( ) (int Wi, int Ko) {return _Kolumna[Ko][Wi];}

  
  /*  double& operator () (const int w, const int k);
  double operator () (const int w, const int k) const;
  Wektor& operator [] (const int k);
  Wektor operator [] (const int k) const;*/
   double wyznacznik () const;

  friend std::istream& operator >> (std::istream &Strm, Macierz &Mac);
  friend std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
