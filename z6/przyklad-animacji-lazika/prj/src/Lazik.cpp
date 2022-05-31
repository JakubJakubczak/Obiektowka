
#include "Lazik.hh"
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

/*!
 * \brief
 * 
 * Metoda wyznacza wektor jednostkowy w strone osi x, ktory nastepnie moze byc  * rotowany przez macierz rotacji. Gdy zna kierunek przejazu zmienia polozenie
 * o OdlegloscDoPrzjechania. Przejazd jest animowany i rozbity na dwie funkcje,
 * by mogl byc mozliwy przejazd o wartosc minusowa
 */

void Lazik::translacja(PzG::LaczeDoGNUPlota  Lacze)
{
  Wektor3D polozenie = this->getPolozenie();
  MacRotacji MacRot;
   Wektor3D jednosX;
  jednosX[0]=1;
  jednosX[1]=0;
  jednosX[2]=0;

  if(OdlegloscDoPrzejechania>0)
    {
  for(int i=1; i<OdlegloscDoPrzejechania + 1; ++i)
      {
	this->setPolozenie() = MacRot.RotacjaZ(KatOrientacji_st) * jednosX * i   + polozenie;  
  Przelicz_i_Zapisz_Wierzcholki(KatOrientacji_st);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
    }

  if(OdlegloscDoPrzejechania<0)
    {
  for(int i=-1; i>OdlegloscDoPrzejechania - 1; --i)
      {
	this->setPolozenie() = MacRot.RotacjaZ(KatOrientacji_st) * jednosX * i   + polozenie;  
  Przelicz_i_Zapisz_Wierzcholki(KatOrientacji_st);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
    }

}

/*!
 * \brief
 * 
 * Metoda obraca lazik do stopni o wartosci KatZadany. Obracanie zaczyna sie  
 * od momentu wczesniejszego polozenia lazika i jest animowane. Zostalo 
 * rozlozone na dwa przypadki, by lazik mogl sie obracac o minusowa wartosc
 */
void Lazik::obrot(PzG::LaczeDoGNUPlota Lacze)
{
  if(KatZadany==KatOrientacji_st) KatOrientacji_st=KatZadany;
  
  if(KatZadany>KatOrientacji_st)
    {
  for(int i=KatOrientacji_st+1; i<KatZadany+1; ++i)
      {
  Przelicz_i_Zapisz_Wierzcholki(i);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
  KatOrientacji_st=KatZadany;
    }

  if(KatZadany<KatOrientacji_st)
    {
  for(int i=KatOrientacji_st-1; i>KatZadany-1; --i)
      {
  Przelicz_i_Zapisz_Wierzcholki(i);
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
  KatOrientacji_st=KatZadany;
    }

}

TypKolizji Lazik::CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const 
 {
   if( this->getObrys().NakladanieObrysow( Wsk_Lazik->getObrys() ) )
     {
       std::cout<<"Kolizja";
      return TK_Kolizja;
     }
   else
     {
       std::cout<<"Brak Kolizcji";
     return TK_BrakKolizji;
     }
 }
