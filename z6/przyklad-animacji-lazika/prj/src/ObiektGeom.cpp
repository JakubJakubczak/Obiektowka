#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"



using namespace std;

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

  Skala[0]=20;
  Skala[1]=20;
  Skala[2]=10;
}



bool  ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
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
  
  StrmWe >> Wsp[0] >> Wsp[1] >> Wsp[2];

  if (StrmWe.fail())return false;
  
  do {
    for(int i=0; i<3; i++)
      {
	Wsp[i]=Wsp[i]*Skala[i]+Polozenie[i];
      }
    StrmWy << Wsp[0] << " " << Wsp[1] << " " << Wsp[2] << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> Wsp[0] >> Wsp[1] >> Wsp[2];
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
 
}

/*void const ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::istream& StrmWe, std::ostream &StrmWy)
  {} */
	
