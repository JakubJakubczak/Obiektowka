#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include<cstdlib>
#include "SWektor.hh"

//#include "MacierzRotacji.hh"


//  szablon klasy SMacierz
/******************************************************************************************
 *  Klasa macierz jest klasą sluzaca do przechowywania macierzy i operacji na nich.
 *  Klasa zawiera w sobie tablice obiektow klasy Wektor o rozmiarze SWymiar, funkcje 
 *  potrzebne do wyznaczania wyznacznika macierzy, mozliwosc transpozycji macierz y 
 *  oraz funkcjonalnosc mnozenia macierzy przez wektor. W klasie zostały przeciazane
 *  operatory () i [] dla ulatwienia poslugiwania sie obiektami.
 *
 *   
 *****************************************************************************************/

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

  
};

typedef SMacierz<double,3> Macierz3D;

/*!
 * Oblicza wyznacznik macierzy. Najpierw sprowadza macierz do postaci macierzy 
 * górnej trójkątnej metodą eliminacji Gaussa, a następnie wyznacza iloczyn 
 * elementów na diagonali.
 * UWAGA: Modyfikuje obiekt, dla którego jest wywołana.
 *
 * \return Wyznacznik macierzy
 */
template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::wyznacznikEliminacjaGaussa(){
  int parzystosc;
  if (!macierzTrojkatna(parzystosc)) exit(0);
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
template <typename STyp, int SWymiar>
bool SMacierz<STyp,SWymiar>::macierzTrojkatna(int &Parzystosc) {
  Parzystosc = 1;
  for(int i = 0; i<SWymiar-1; i++){
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
template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::wyznacznik () const {
  SMacierz<STyp,SWymiar> temp = *this;

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
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::transpozycja () const
{
  int i,k;
  SMacierz<STyp,SWymiar> temp1 = *this;   // macierz tymczasowa, ktora bedzie zmieniana i zwracana
  SMacierz<STyp, SWymiar> temp2 = *this;   // macierz tymczasowa nie zmieniana

  for(i=0; i<SWymiar; i++){
    for(k=0; k<SWymiar; k++){
      temp1(i,k)=temp2(k,i);
    }}

  return  temp1;
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
template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::wymnozElementyDiagonali() const
{
  int i;
  STyp wynik;
  wynik=1;
  for(i=0; i<SWymiar; i++)
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
template <typename STyp, int SWymiar>
bool SMacierz<STyp, SWymiar>::zamienWiersze (unsigned int biezacyWiersz)
{
  unsigned int nastepnyWiersz=biezacyWiersz+1; // nastepna kolumna ktora nie ma zera na diagonali

  while(_Wiersz[biezacyWiersz][nastepnyWiersz]==0) // jesli element na diagonali = 0
      {
	if(nastepnyWiersz<SWymiar){ // warunek potrzebny zeby nie wyjsc poza zakres tablicy
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
template <typename STyp, int SWymiar>
void SMacierz<STyp, SWymiar>::zerujKolumne(unsigned int biezacyWiersz)
{
 unsigned int nastepnyWiersz=biezacyWiersz+1;

 while(nastepnyWiersz<SWymiar)  // warunek potrzebny by nie wyjsc poza zakres tablicy
   {
     _Wiersz[nastepnyWiersz] = (_Wiersz[nastepnyWiersz]) - ( _Wiersz[biezacyWiersz] * _Wiersz[nastepnyWiersz][biezacyWiersz] /
							     _Wiersz[biezacyWiersz][biezacyWiersz] );
	 ++nastepnyWiersz;
   }
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
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> operator*(SMacierz<STyp, SWymiar> M, SWektor<STyp, SWymiar> W)
{
  int i,k;
  SWektor<STyp,SWymiar> Wynik;
  Wynik=0;
  
  for(i=0; i<SWymiar; i++){
    for(k=0; k<SWymiar; k++){
      Wynik[i]=Wynik[i]+M(i,k)*W[k];
    }}
      
  return Wynik;
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
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp, SWymiar> &Mac)
  {
  int i;
 for(i=0; i<SWymiar; i++)
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
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp, SWymiar>Mac)
{
   int i;
  for(i=0; i<SWymiar; i++)
    {
      Strm<<Mac[i]<<"\n";
    }
  return Strm;
}









#endif
