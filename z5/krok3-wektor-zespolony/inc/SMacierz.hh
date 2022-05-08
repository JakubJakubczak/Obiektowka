#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "SWektor.hh"


//  szablon klasy macierz

template <typename STyp, int SWymiar>
class SMacierz {
  // Atrybuty prywante
  SWektor<STyp, SWymiar> _Wiersz[SWymiar];
  // Metody prywatne - przyklad
  STyp wyznacznikEliminacjaGaussa();
  STyp wymnozElementyDiagonali() const;
  bool macierzTrojkatna(int &Parzystosc);
  bool zamienWiersze (unsigned int biezacyWiersz);
  void zerujKolumne(unsigned int biezacyWiersz);
public:
  // Metody publiczne - przyklad
  // przeciazenie operatorow () i [] dla wygody korzystania
  const SWektor<STyp,SWymiar> & operator[ ] (int Wi) const { return _Wiersz[Wi]; }    // zwraca typ  Wektor
  SWektor<STyp, SWymiar>& operator[ ] (int Wi) { return _Wiersz[Wi]; }
  const STyp operator( ) (int Wi, int Ko) const {return _Wiersz[Wi][Ko];}  // zwraca typ double
  STyp& operator( ) (int Wi, int Ko) {return _Wiersz[Wi][Ko];}

  SMacierz<STyp, SWymiar> operator!() const;

  STyp wyznacznik () const;
  SMacierz<STyp, SWymiar> transpozycja() const;

  // zaprzyjaznienie przeciazen na strumieniach
  /*
  friend  std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac);
  friend  std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp, SWymiar> &Mac);
  */
};
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> operator*(SMacierz<STyp, SWymiar> M, SWektor<STyp, SWymiar> W);
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp, SWymiar> &Mac);

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp, SWymiar>&Mac);












#endif
