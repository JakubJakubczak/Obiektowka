
#include "Lazik.hh"
//#include <chrono>
//#include <thread>
//#include "ObiektGeom.hh"
using namespace std::literals::chrono_literals;

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

void Lazik::translacja(PzG::LaczeDoGNUPlota  Lacze)
{
  Wektor3D polozenie = this->Polozenie;
  MacRotacji MacRot;
   Wektor3D jednosX;
  jednosX[0]=1;
  jednosX[1]=0;
  jednosX[2]=0;

  for(int i=1; i<OdlegloscDoPrzejechania + 1; i++)
    {
  this->Polozenie = MacRot.RotacjaZ(KatOrientacji_st) * jednosX * i   + polozenie;  
  Przelicz_i_Zapisz_Wierzcholki(KatOrientacji_st);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
    }
}

void Lazik::obrot(PzG::LaczeDoGNUPlota  Lacze)
{
  for(int i=1; i<KatOrientacji_st+1; i++)
    {
  Przelicz_i_Zapisz_Wierzcholki(i);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
    }
}
