#include "Macierz.hh"
#include <algorithm>
#include "rozmiar.h"




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
 * \param[in] Parzystosc - referencja do zmiennej przechowującej o parzystości * liczby wykonanych zmian kolumn
 *
 * \return Informacja o powodzeniu operacji
 */

bool Macierz::macierzTrojkatna(int &Parzystosc) {
  Parzystosc = 1;
  for(int i = 0; i<ROZMIAR-1; i++){
    if (_Wiersz[i][i]==0){
      if(!zamienWiersze(i)) return false;
      Parzystosc = -Parzystosc;
    }
    zerujKolumne(i);    
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

/* Funkcja transponujaca macierz
 *  
 *  Dane wejsciowe:
 *    brak
 *
 *  Dane wyjsciowe:
 *    temp1 - transponowana macierz
 */

Macierz Macierz::transpozycja () const
{
  int i,k;
  Macierz temp1 = *this;   // macierz tymczasowa, ktora bedzie zmieniana i zwracana
  Macierz temp2 = *this;   // macierz tymczasowa nie zmieniana

  for(i=0; i<ROZMIAR; i++){
    for(k=0; k<ROZMIAR; k++){
      temp1(i,k)=temp2(k,i);
    }}

  return  temp1;
}
/* Jest to przeciazenie operatora mnozace macierz ROZMIARxROZMIAR * kolumne o wy *  miarze ROZMIAR. 
 *    
 *    Dane wejsciowe:
 *       W - kolumna przez ktora bedziemy mnozyli
 *       Macierz - niejawnie poslugujemy sie macierza w przeciazeniu
 *
 *    Dane wyjsciowe:
 *       Wynik - wynik mnozenia macierzy przez wektor
 */
Wektor operator*(Macierz M, Wektor W)
{
  int i,k;
  Wektor Wynik;
  Wynik=0;
  
  for(i=0; i<ROZMIAR; i++){
    for(k=0; k<ROZMIAR; k++){
      Wynik[i]=Wynik[i]+M(i,k)*W[k];
    }}
      
  return Wynik;
}



/*
 * funkcja wymnaza elementy na diagonali
 *
 *  Dane wejsciowe:
 *    brak
 *
 *  Dane wyjsciowe:
 *     wynik - wynik wymnozenia elementow na diagonali
 *
*/

double Macierz::wymnozElementyDiagonali() const
{
  int i;
  double wynik = 1;
  for(i=0; i<ROZMIAR; i++)
    {
      wynik= wynik * _Wiersz[i][i];
    }
  return wynik;
}

/*
 * funkcja zamienia wiersze miejscem
 *
 *  Dane wejsciowe:
 *    biezacyWiersz
 *
 *  Dane wyjsciowe:
 *     false - gdy nie zostanie znaleziony element zerowy do zamiany
 *     true - gdy zostanie znaleziony -||-
 *
*/

bool Macierz::zamienWiersze (unsigned int biezacyWiersz)
{
  unsigned int nastepnyWiersz=biezacyWiersz+1; // nastepna kolumna ktora nie ma zera na diagonali

  while(_Wiersz[biezacyWiersz][nastepnyWiersz]==0) // jesli element na diagonali = 0
      {
	if(nastepnyWiersz<ROZMIAR){ // warunek potrzebny zeby nie wyjsc poza zakres tablicy
	  std::cout<<"Nie znaleziono elemntu zerowego do zamiany";
	  return false;
	}

        ++nastepnyWiersz;
      }
    
  std::swap(_Wiersz[biezacyWiersz],_Wiersz[nastepnyWiersz]);
          return true;
}
/*
 * funkcja zeruje kolumne macierzy
 *
 *  Dane wejsciowe:
 *    biezacyWiersz
 *
 *  Dane wyjsciowe:
 *     brak - funkcja void
 *
*/

void Macierz::zerujKolumne(unsigned int biezacyWiersz)
{
 unsigned int nastepnyWiersz=biezacyWiersz+1;

 while(nastepnyWiersz<ROZMIAR)  // warunek potrzebny by nie wyjsc poza zakres tablicy
   {
     _Wiersz[nastepnyWiersz] = (_Wiersz[nastepnyWiersz]) - ( _Wiersz[biezacyWiersz] * _Wiersz[nastepnyWiersz][biezacyWiersz] /
							     _Wiersz[biezacyWiersz][biezacyWiersz] );
	 ++nastepnyWiersz;
   }
}


/* przeciazenie operatora dla wczytywania macierzy
 *
 * Dane wejsciowe:
 *   Strm - strumien
 *   Mac - macierz
 *  
 * Dane wyjsciowe:
 *   Strm
 *
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

/* przeciazenie operatora dla wyswietlania macierzy
 *
 * Dane wejsciowe:
 *   Strm - strumien
 *   Mac - macierz
 *   
 * Dane wyjsciowe:
 *   Strm
 *
 */

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
   int i;
  for(i=0; i<ROZMIAR; i++)
    {
      Strm<<Mac[i]<<"\n";
    }
  return Strm;


}





