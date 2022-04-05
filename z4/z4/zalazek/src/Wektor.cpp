#include "Wektor.hh"

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

  wynik.x = this->x + W2.x;
  wynik.y = this->y + W2.y;
  wynik.z = this->z + W2.z;

  return wynik;

}

Wektor Wektor::operator - (  Wektor  W2) const
{
  Wektor wynik;

  wynik.x = this->x - W2.x;
  wynik.y = this->y - W2.y;
  wynik.z = this->z - W2.z;

  return wynik;

}
Wektor Wektor::operator / (  Wektor  W2) const
{
  Wektor wynik;

  // jesli ktorys argument wektora jest rowny zero to wyswietl komunikat o bledzie
  if(W2.x==0 || W2.y==0 || W2.z==0)  cerr<<"Blad. dzielenie przez zero";
  
  wynik.x = this->x / W2.x;
  wynik.y = this->y / W2.y;
  wynik.z = this->z / W2.z;

  return wynik;

}

Wektor Wektor::operator * (  Wektor  W2) const
{
  Wektor wynik;

  wynik.x = this->x * W2.x;
  wynik.y = this->y * W2.y;
  wynik.z = this->z * W2.z;
  return wynik;

}

Wektor Wektor::operator * (double mnoznik) const
{
  Wektor wynik;

  wynik.x = this->x * mnoznik;
  wynik.y = this->y * mnoznik;
  wynik.z = this->z * mnoznik;

    return wynik;

}

Wektor Wektor::operator / (double dzielnik) const
{
  Wektor wynik;

  // jesli dzielnik jest rowny zero to wyswietl komunikat o bledzie
  if(dzielnik==0)
    {
    cerr<<"Blad. Dzielenie przez zero";
    }
  wynik.x = this->x / dzielnik;
  wynik.y = this->y / dzielnik;
  wynik.z = this->z / dzielnik;
  
  return wynik;
  
}

istream& operator >> (istream &Strm, Wektor &Wek)
{
  cin >> Wek.x;
  cin >> Wek.y;
  cin >> Wek.z;

  return Strm;

}

ostream& operator << (ostream&Strm, const Wektor& Wek)
{
  Strm<<Wek.x<<" "<<Wek.y<<" "<<Wek.z;

  return Strm;

}
