#include "Macierz.hh"
#include <algorithm>
#include "rozmiar.h"




/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*!
 * Oblicza wyznacznik macierzy. Najpierw sprowadza macierz do postaci macierzy 
 * górnej trójkątnej metodą eliminacji Gaussa, a następnie wyznacza iloczyn 
 * elementów na diagonali.
 * UWAGA: Modyfikuje obiekt, dla którego jest wywołana.
 *
 * \return Wyznacznik macierzy
 */
double Macierz::wyznacznikEliminacjaGaussa(){
  int parzystosc;
  if (!macierzTrojkatna(parzystosc)) return 0;
  return wymnozElementyDiagonali()*parzystosc;
}

/*!
 * Metoda pozwala sprowadzić dowolną macierz do postaci macierzy górnej 
 * trójkątnej. Jeśli macierz zawiera wiersz zerowy, to operacja ta jest 
 * niemożliwa do przeprowadzenia, a metoda zwraca informację o porażce. 
 * W przeciwnym razie zwraca sukces.
 * UWAGA: Modyfikuje obiekt, dla którego jest wywołana.
 *
 * \param[in] Parzystosc - referencja do zmiennej przechowującej o parzystości *                          liczby wykonanych zmian kolumn
 *
 * \return Informacja o powodzeniu operacji
 */
bool Macierz::macierzTrojkatna(int &Parzystosc) {
  Parzystosc = 1;
  for(int i = 0; i<ROZMIAR; i++){
    if (_Kolumna[i][i]==0){
      if(!zamienKolumny(i)) return false;
      Parzystosc = -Parzystosc;
    }
    zerujWiersz(i);    
  }
  return true;
}

/*!
 * Metoda oblicza i zwraca wyznacznik danej macierzy
 *
 * \return Wyznacznik macierzy
 */
double Macierz::wyznacznik () const {
  Macierz temp = *this;

  return temp.wyznacznikEliminacjaGaussa();
}


double Macierz::wymnozElementyDiagonali() const
{
  int i;
  double k = 1;
  for(i=0; i<ROZMIAR; i++)
    {
      k= k * _Kolumna[i][i];
    }
  return k;
}

bool Macierz::zamienKolumny (unsigned int biezacaKolumna)
{
  unsigned int nastepnaKolumna=biezacaKolumna+1; // nastepna kolumna ktora nie ma zera na diagonali


  
  while(_Kolumna[biezacaKolumna][nastepnaKolumna]==0)
      {
	if(nastepnaKolumna<ROZMIAR){
	  std::cout<<"Nie znaleziono elemntu zerowego do zamiany";
	  return false;
	}

        ++nastepnaKolumna;
      }
    
  std::swap(_Kolumna[biezacaKolumna],_Kolumna[nastepnaKolumna]);
          return true;
}

void Macierz::zerujWiersz(unsigned int biezacaKolumna)
{
 unsigned int nastepnaKolumna=biezacaKolumna+1;

 while(nastepnaKolumna<ROZMIAR)
   {
     _Kolumna[nastepnaKolumna] = (_Kolumna[nastepnaKolumna]) - ( _Kolumna[biezacaKolumna] * _Kolumna[biezacaKolumna][nastepnaKolumna] /
								 _Kolumna[biezacaKolumna][biezacaKolumna] );
	 ++nastepnaKolumna;
   }
}

/*double& Macierz::operator () (const int w, const int k)
{
  
}

double Macierz::operator () (const int w, const int k) const
{
  
}

Wektor& Macierz::operator [] (const int k)
{
  
}

Wektor Macierz::operator [] (const int k) const
{

}
*/

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
  int i;
 for(i=0; i<ROZMIAR; i++)
    {
      Strm>>Mac[i];
    }

  return Strm;


}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
   int i;
  for(i=0; i<ROZMIAR; i++)
    {
      Strm<<Mac[i]<<"\n";
    }
  return Strm;


}





