#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"

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
  ZmienSkale(2,6,2);
}

  int ID() const override {return 2;}
  virtual TypKolizji CzyKolizja(const std::shared_ptr<Lazik> & Wsk_Lazik) const override
  {
    if( this->getObrys().NakladanieObrysow( Wsk_Lazik->getObrys() ) )
     {
       std::cout<<"Kolizja z probka "<<this->getNazwa()<<std::endl;
       std::cout<<"Mozliwosc podniesienia  probki";
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
