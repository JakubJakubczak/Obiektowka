#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"


using namespace std;

/*!
 * \brief
 * 
 * Konstruktor inicjalizuje obiekty klasy i ustawia wektor klasy na (20,20,10) 
 *
 */

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID,
			double       polozenieX,
			double       polozenieY,
			double       polozenieZ  
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
  
  Polozenie[0]=polozenieX;
  Polozenie[1]=polozenieY;
  Polozenie[2]=polozenieZ;
  
   KatOrientacji_st=0;

  Skala[0]=20;
  Skala[1]=20;
  Skala[2]=10;
}

void ObiektGeom::ZmienSkale(int x, int y, int z)
{
  Skala[0]=x;
  Skala[1]=y;
  Skala[2]=z;
}

/*!
 * \brief
 * 
 * metoda czyta z pliku wspolrzedne bryly, nastepnie zmienia te wspolrzedne  
 * wedlug skali, polozenia i podanego kata na nowe i zapisuje do pliku wyjs.
 * Metoda rowniez wylicza obrys obiektu.
 */
bool  ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(double kat)
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Wektor3D  Wsp;
  int Indeks_Wiersza = 0;
  Wektor2D Najmniejsze;
  Wektor2D Najwieksze;
  // inicjalizacja zmiennych do obrysu
  Najmniejsze=200;
  Najwieksze=-200;
  
  StrmWe >> Wsp;

  if (StrmWe.fail())return false;
  
  do {
    Wsp = MacRot.RotacjaZ(kat) * Wsp * Skala + Polozenie;
    StrmWy << Wsp<< endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

     //wyliczanie obrysu

    if(Wsp[0] < Najmniejsze[0]) Najmniejsze[0]=Wsp[0];
    if(Wsp[0] > Najwieksze[0]) Najwieksze[0]=Wsp[0];
    if(Wsp[1] < Najmniejsze[1]) Najmniejsze[1]=Wsp[1];
    if(Wsp[1] > Najwieksze[1]) Najwieksze[1]=Wsp[1];
    
    StrmWe >> Wsp;

          
  } while (!StrmWe.fail());

    // przypisywanie wartosci
  this->setObrys().setDolnyLewy() = Najmniejsze;
  this->setObrys().setGornyPrawy() = Najwieksze;

  
  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
 
}

	
