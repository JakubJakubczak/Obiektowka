#ifndef LAZIKSFR_HH
#define LAZIKSFR_HH

#include "Lazik.hh"
#include "ProbkaRegolitu.hh"
#include <list>

/*!
 * \brief
 * 
 * Klasa LazikSFR dziedziczy klasy Lazik. Pozwala ona na dodoatkowe funkcjonalnosci takie jak
 * dodawanie probek do listy i pozniejsze ich wyswietlanie. 
 *
 */
class LazikSFR : public Lazik
{
  std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;

public:

  LazikSFR( const char*  SNazwaPliku_BrylaWzorcowa,
		        const char*  SNazwaObiektu,
		        int          KOLORID,
			double       PolozenieX,
			double       PolozenieY,
		        double       PolozenieZ 
		       ):
    Lazik(SNazwaPliku_BrylaWzorcowa, SNazwaObiektu, KOLORID, PolozenieX, PolozenieY,PolozenieZ){}
  virtual ~LazikSFR(){;}
  int ID() const override {return 3;}
  TypKolizji CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const override
  {
     if( this->getObrys().NakladanieObrysow( Wsk_Lazik->getObrys() ) )
     {
       std::cout<<"Kolizja z LazikiemSRF "<<this->getNazwa()<<std::endl;
      return TK_Kolizja;
     }
   else
     {
       // std::cout<<"Brak Kolizcji z lazikiem";
     return TK_BrakKolizji;
     }
  }

  void WyswietlProbki() 
    {
      int i=1;

      std::cout<<"Lista probek: "<<std::endl;
  for(std::list<std::shared_ptr<ProbkaRegolitu>>::iterator it = ListaProbek.begin(); it!= ListaProbek.end();  ++it)
      {
      std::cout<<i<<". Nazwa: "<< (*it)->getNazwa()<<std::endl;
      // std::cout<<"   Polozenie: "<< (*it)->getPolozenie()<<std::endl;
      //std::cout<<"   Orientacja[st]: "<< (*it)->getKat()<<std::endl;
      i++;         
      }
    }
   void DodajProbke(const std::shared_ptr<ProbkaRegolitu> Probka) 
  {
    ListaProbek.push_back(Probka);
  }

  void SprzezProbki(std::shared_ptr<LazikSFR> Wsk_lazik)
  {
    double l=0;
   for(std::list<std::shared_ptr<ProbkaRegolitu>>::iterator it = ListaProbek.begin(); it!= ListaProbek.end();  ++it)
   { 
     
     (*it)->setPolozenie()[0]=Wsk_lazik->getPolozenie()[0];
     (*it)->setPolozenie()[1]=Wsk_lazik->getPolozenie()[1];
     (*it)->setPolozenie()[2]=10 + 2 * l;
     (*it)->setOrientacja()=Wsk_lazik->getOrientacja();
     (*it)->Przelicz_i_Zapisz_Wierzcholki((Wsk_lazik)->getOrientacja());
     l=l+1;
   }
  }


  void PrzeliczanieWierzDlaProbek(double i)
  {
     for(std::list<std::shared_ptr<ProbkaRegolitu>>::iterator it = ListaProbek.begin(); it!= ListaProbek.end();  ++it)
     {
       (*it)->Przelicz_i_Zapisz_Wierzcholki(i);
       (*it)->setOrientacja()=i;
     }
  }
};



#endif
