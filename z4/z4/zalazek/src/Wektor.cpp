#include "Wektor.hh"
#define ROZMIAR 3
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */





Wektor Wektor::operator + (  Wektor  W2) const
{
  Wektor wynik;
  int i;
  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] + W2.Wsp[i];
    }

  return wynik;

}

Wektor Wektor::operator - (  Wektor  W2) const
{
  Wektor wynik;
  int i;
  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] - W2.Wsp[i];
    }

  return wynik;

}
Wektor Wektor::operator / (  Wektor  W2) const
{
  Wektor wynik;
  int i;

  // jesli ktorys argument wektora jest rowny zero to wyswietl komunikat o bledzie
  if(W2.Wsp[0]==0 || W2.Wsp[1]==0 || W2.Wsp[2]==0)  cerr<<"Blad. dzielenie przez zero";
  
  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] / W2.Wsp[i];
    }

  return wynik;
}

Wektor Wektor::operator * (  Wektor  W2) const
{
 Wektor wynik;
  int i;
  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] * W2.Wsp[i];
    }

  return wynik;

}

Wektor Wektor::operator * (double mnoznik) const
{
  Wektor wynik;
  int i;
  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] * mnoznik;
    }

  return wynik;;

}

Wektor Wektor::operator / (double dzielnik) const
{
  Wektor wynik;
  int i;

  // jesli dzielnik jest rowny zero to wyswietl komunikat o bledzie
  if(dzielnik==0)
    {
    cerr<<"Blad. Dzielenie przez zero";
    }

  for(i=0; i<ROZMIAR; i++)
    {
      wynik.Wsp[i] = this->Wsp[i] / dzielnik;
    }

  return wynik;

  
}

Wektor Wektor::operator = (double liczba){
  int i;
  for(i=0; i<ROZMIAR; i++){
   this->Wsp[i]=liczba;
  }
  return *this;
}

double  &Wektor::operator [](int i) 
{
  return Wsp[i];
}


double  Wektor::operator [](int i) const
{
  return Wsp[i];
}

istream& operator >> (istream &Strm, Wektor &Wek)
{
  int i;
 for(i=0; i<ROZMIAR; i++)
    {
      Strm>>Wek[i];
    }

  return Strm;

}

ostream& operator << (ostream&Strm, const Wektor& Wek)
{
  int i;
  for(i=0; i<ROZMIAR; i++)
    {
      Strm<<Wek[i]<<' ';
    }
  return Strm;

}

