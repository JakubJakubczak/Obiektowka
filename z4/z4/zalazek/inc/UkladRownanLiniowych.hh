#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  Macierz Mac;   
  Wektor Wek;   // wektor wyrazow wolnych
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  // Macierz zamianaKolumny(int kolumna) const;
  Macierz zamianaKolumny(int kolumna) const;
public:
  UkladRownanLiniowych transpozycja () const;
  // Wektor RozwUklRow();
  friend std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
  friend std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:x
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych  &UklRown);




#endif
