#include "Lazik.hh"
//#include "ObiektGeom.hh"


Lazik::Lazik( const char*  SNazwaPliku_BrylaWzorcowa,
		        const char*  SNazwaObiektu,
		        int          KOLORID,
			double       PolozenieX,
			double       PolozenieY,
		        double       PolozenieZ 
		       ):
  ObiektGeom(SNazwaPliku_BrylaWzorcowa, SNazwaObiektu, KOLORID, PolozenieX, PolozenieY,PolozenieZ)
{
  KatOrientacji_st=0;
  Szybkosc=0;
  OdlegloscDoPrzejechania=0;
}

void Lazik::translacja( double odleglosc)
{
  MacRotacji MacRot;
   Wektor3D jednosX;
  jednosX[0]=1;
  jednosX[1]=0;
  jednosX[2]=0;

  this->Polozenie = MacRot.RotacjaZ(KatOrientacji_st) * jednosX * odleglosc + this->Polozenie;

  Przelicz_i_Zapisz_Wierzcholki(KatOrientacji_st);
}

void Lazik::obrot()
{
  Przelicz_i_Zapisz_Wierzcholki(KatOrientacji_st);
}
