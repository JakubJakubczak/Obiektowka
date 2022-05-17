#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
//#include "LZespolona.hh"
/***********************************************************************************************
 *   Jest to szablon klasy Wektor sluzacy do poslugiwania sie wektorem jako tablica o 
 *   rozmiarze SWymiar i dokonywania na nim operacji. Klasa zawiera przeciazenia 
 *   podstawowych operatorow matematycznych, mnozenie wektora przez liczbe, dzielenie
 *   go przez liczbe. Zawiera ona rowniez przeciazenie operatora = dla wektora ktorego 
 *   chcemy przyrownac do liczby. Dla wygody poslugiwania sie klasa stworzony 
 *   zostal interfejs poslugiwania sie wspolrzednymi wektora. Posluzyly do tego 
 *   przeciazenia operatora [], jedno zwraca oryginal a drugie kopie.
 *
 *   typename STyp - typ zmiennych ktorymi bedziemy sie poslugiwali
 *   int SWymiar - wymiar wektora
 ***********************************************************************************************/


template <typename STyp, int SWymiar>
class SWektor {
  static int AktualnaIloscObiektow;
  static int LacznaIloscObiektow;
    STyp  _Wsp[SWymiar];
  public:
  SWektor<STyp,SWymiar>() { for (STyp &Wsp: _Wsp) Wsp = 0; AktualnaIloscObiektow++; LacznaIloscObiektow++;}
  ~SWektor<STyp,SWymiar>(){AktualnaIloscObiektow--;}

  static void WyswietlLiczbeObiektow();
  /*SWektor(double x, double y, double z)
    : ( _Wsp[0] )(x), ( _Wsp[1] )(y), ( _Wsp[2] )(z){}*/
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Dodajnik) const;
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
  // SWektor<STyp,SWymiar> operator * (LZespolona Mnoznik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
  SWektor<STyp,SWymiar> operator / (STyp dzielnik) const;
  SWektor<STyp,SWymiar> operator * (  SWektor<STyp,SWymiar>  W2) const;
  // SWektor<STyp, SWymiar>  operator = (const STyp liczba);
    SWektor<STyp, SWymiar>  operator = (const double liczba);
};

typedef SWektor<double,3> Wektor3D;

template <typename STyp, int SWymiar>
int SWektor<STyp,SWymiar>::AktualnaIloscObiektow=0;  // inicjalizacja zmiennej  statycznej
template <typename STyp, int SWymiar>
int SWektor<STyp,SWymiar>::LacznaIloscObiektow=0;

template <typename STyp, int SWymiar>      // wyswietlanie zmiennych statycznych
void SWektor<STyp,SWymiar>::WyswietlLiczbeObiektow()
{
  std::cout<<"Aktualna ilosc obiektow Wektor3D: " << AktualnaIloscObiektow <<std::endl;
  std::cout<<"Laczna ilosc obiektow Wektor3D: "   << LacznaIloscObiektow   <<std::endl;
  
}

// dodawanie wektorow jako szablon
/*
     Przeciazenie operatora dodawnia dla wektorow
     Dane wejsciowe:
     SWektor  
     SWektor 
     Dane wyjsciowe:
     Zwraca wynik dodawania wektorow
   */

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Dodajnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Dodajnik[Ind];
  return Wynik;
}

// odejmowanie wektorow jako szablon
/*
     Przeciazenie operatora odejmowania dla wektorow
     Dane wejsciowe:
     SWektor  
     SWektor 
     Dane wyjsciowe:
     Zwraca wynik odejmowania wektorow
   */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}

// mnozenie wektora przez LZespolona jako szablon
/*
     Przeciazenie operatora mnozenia wektora przez LZespolona
     Dane wejsciowe:
     SWektor  
     LZespolona
     Dane wyjsciowe:
     Zwraca wynik mnozenia 
   */

/*
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (LZespolona Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}
*/
// mnozenie wektora przez liczbe
/*
     Przeciazenie operatora mnozenia wektora przez liczbe
     Dane wejsciowe:
     SWektor  
     double 
     Dane wyjsciowe:
     Zwraca wynik mnozenia wektora przez liczbe
   */

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}
// dzielenie wektora przez STyp
  /*
     Przeciazenie operatora dzielenia wektora przez STyp
     Dane wejsciowe:
     SWektor  
     STyp 
     Dane wyjsciowe:
     Zwraca wynik dzielenia wektora przez STyp
   */
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
/*
     Przeciazenie operatora rowna sie dla wektora i typu double
     Dane wejsciowe:
     SWektor 
     double 
     Dane wyjsciowe:
     Wynik - wypelnia wektor liczba
   */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator = ( const double liczba)
{
int i;
  for(i=0; i<SWymiar; i++){
   this->_Wsp[i]=liczba;
  }
  return *this;
}

/*
     Przeciazenie operatora mnozenia dla wektorow
     Dane wejsciowe:
     Wektor W1 
     Wektor W2
     Dane wyjsciowe:
     Zwraca wynik mnozenia wektorow
   */
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (  SWektor<STyp,SWymiar>  W2) const
  {
    SWektor<STyp,SWymiar> wynik;
  int i;
  for(i=0; i<SWymiar; i++)
    {
      wynik._Wsp[i] = this->_Wsp[i] * W2._Wsp[i];
    }

  return wynik;

}

// wyswietlanie wspolrzednych wektora jako szablon
/*
 Ta funkcja to przeciazenie strumienia wyjsciowego dla wektorow.
 
 Dane wejsciowe:
 StrmWej 
 SWektor 
 Dane wyjsciowe:
 Zwraca strumien StrmWej;
 
 */

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << W[Ind]<<" ";
  }  
  return StrmWyj;
}

template <typename STyp>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,2>& W)
{
  for (unsigned int Ind = 0; Ind < 2; ++Ind) {
    StrmWyj << W[Ind];
    StrmWyj << std::endl;
  }  
  return StrmWyj;
}
// wczytywanie wspolrzednych wektora jako szablon
/*
 Ta funkcja to przeciazenie strumienia wejsciowego dla wektorow.
 
 Dane wejsciowe:
 StrmWej 
 SWektor 
 Dane wyjsciowe:
 Zwraca strumien StrmWej;
 
 */


template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &StrmWej,  SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWej >> W[Ind];
  }  
  return StrmWej;
}



#endif
