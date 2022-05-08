#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include "LZespolona.hh"
// szablon klasy wektor

template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Dodajnik) const;
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (LZespolona Mnoznik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
  SWektor<STyp,SWymiar> operator / (STyp dzielnik) const;

  // SWektor<STyp, SWymiar>  operator = (const STyp liczba);
    SWektor<STyp, SWymiar>  operator = (const double liczba);
};

// dodawanie wektorow jako szablon

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Dodajnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Dodajnik[Ind];
  return Wynik;
}

// odejmowanie wektorow jako szablon

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}

// mnozenie wektora przez STyp jako szablon

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (LZespolona Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

// mnozenie wektora przez liczbe

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}
// dzielenie wektora przez STyp
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp dzielnik) const
{
  SWektor<STyp,SWymiar> wynik;
  int i;

  // jesli dzielnik jest rowny zero to wyswietl komunikat o bledzie
  if(dzielnik==0)
    {
      std::cerr<<"Blad. Dzielenie przez zero";
    }

  for(i=0; i<SWymiar; i++)
    {
      wynik._Wsp[i] = this->_Wsp[i] / dzielnik;
    }

  return wynik;

}


// przyrownanie wektora do liczby

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator = ( const double liczba)
{
int i;
  for(i=0; i<SWymiar; i++){
   this->_Wsp[i]=liczba;
  }
  return *this;
}

// wyswietlanie wspolrzednych wektora jako szablon

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &StrmWej,  SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWej >> W[Ind];
  }  
  return StrmWej;
}

#endif
