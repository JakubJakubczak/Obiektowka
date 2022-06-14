#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"

/*!
 * \brief
 * 
 * Klasa dziedziczy z ObiekGeom i ma opcjonalnosc sprawdzania, czy aktywnylazik nie koliduje z jej obiektem
 *
 */
class ProbkaRegolitu: public ObiektGeom {
public:
ProbkaRegolitu( const char*  SNazwaPliku_BrylaWzorcowa,
		        const char*  SNazwaObiektu,
		        int          KOLORID,
			double       PolozenieX,
			double       PolozenieY,
		        double       PolozenieZ 
		       ):
  ObiektGeom(SNazwaPliku_BrylaWzorcowa, SNazwaObiektu, KOLORID, PolozenieX, PolozenieY,PolozenieZ)
{
  ZmienSkale(3,3,2);
}

  virtual ~ProbkaRegolitu(){}
  int ID() const override {return 2;}
  /*!
 * \brief
 * 
 * Metoda sprawdza czy probka koliduje z aktywnymlazikiem, jesli koliduje to wyswietla komunikat, zalezny od tego
 * z czym ta kolizja byla i zwraca Tk_Kolizja, jesli kolizji nie było zwraca TK_BrakKolizji
 *
 */
  virtual TypKolizji CzyKolizja(const std::shared_ptr<Lazik> & Wsk_Lazik) const override
  {
    if( this->getObrys().NakladanieObrysow( Wsk_Lazik->getObrys() ) )
     {
       // metoda sprawdzajacy czy lazik NIE SFR może przejechac nad probka
       if(Wsk_Lazik->ID()==1)
       {
         MacRotacji MacRot;
         Wektor3D WektorJednostkowy; // wektor wzdluz osi lazika
         Wektor3D OdlegloscPL; // odleglosc probki od lazika
         double Odleglosc;   // odleglosc probki od osi symetrii lazika jako skalar
         double sinkat; // kat orientacji wyrazony w radianach
         double IloczynSkalarny; // iloczyn skalarny OdleglosciPL i Wektora jednostkowego

         WektorJednostkowy[0] = 1;
         WektorJednostkowy[1] = 0;
         WektorJednostkowy[2] = 0;

         WektorJednostkowy = MacRot.RotacjaZ(Wsk_Lazik->getOrientacja()) * WektorJednostkowy;

          

         OdlegloscPL = this->getPolozenie() - Wsk_Lazik->getPolozenie();
         Odleglosc = sqrt( OdlegloscPL[0] * OdlegloscPL[0] + 
                           OdlegloscPL[1] * OdlegloscPL[1] + 
                           OdlegloscPL[2] * OdlegloscPL[2] ) ;
        IloczynSkalarny = OdlegloscPL[0] * WektorJednostkowy[0]  + OdlegloscPL[1] * WektorJednostkowy[1]  + OdlegloscPL[2] * WektorJednostkowy[2]; 

         sinkat = sqrt( 1 -   pow(IloczynSkalarny / Odleglosc, 2)
                      );
         if(Odleglosc * sinkat < 4 )
         {
            std::cout<<"Przejazd nad probka "<<this->getNazwa()<<std::endl;

           return TK_PrzejazdNadProbka;
         }
       }
       std::cout<<"Kolizja z probka "<<this->getNazwa()<<std::endl;
       if( Wsk_Lazik->ID() == 3)  std::cout<<"Mozliwosc podniesienia  probki";
      return TK_Kolizja;
     }
   else
     {
       // std::cout<<"Brak Kolizcji z lazikiem";
     return TK_BrakKolizji;
     }
  }
};


#endif
