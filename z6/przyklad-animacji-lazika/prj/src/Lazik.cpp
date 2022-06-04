
#include "Lazik.hh"

class Scena;
using namespace std::literals::chrono_literals;
/*!
 * \brief
 * 
 * Konstruktor wywoluje na liscie inicjalizacyjnej konstruktor klasy pochodnej 
 * ObiektGeom, inicjalizuje swoje dane.
 */

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
  OdlegloscDoPrzejechania=0;
  KatZadany=0;
}


TypKolizji Lazik::CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const 
 {
   if( this->getObrys().NakladanieObrysow( Wsk_Lazik->getObrys() ) )
     {
       std::cout<<"Kolizja z lazikiem "<< this->getNazwa();
      return TK_Kolizja;
     }
   else
     {
       // std::cout<<"Brak Kolizcji z lazikiem";
     return TK_BrakKolizji;
     }
 }
