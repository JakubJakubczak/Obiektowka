
#ifndef LAZIK_HH
#define LAZIK_HH

#include <chrono>
#include <thread>
#include "lacze_do_gnuplota.hh"
#include "ObiektGeom.hh"

class Lazik
     : public ObiektGeom
{
  //public:
  double KatOrientacji_st;
  double KatZadany; 
  //double Szybkosc;
  double OdlegloscDoPrzejechania;

public:
  Lazik(const char* SNazwaPliku_BrylaWzorcowa, const char* SNazwaObiektu, int KOLORID, double PolozenieX, double PolozenieY, double PolozenieZ);
  void translacja(PzG::LaczeDoGNUPlota  Lacze);
  void obrot(PzG::LaczeDoGNUPlota  Lacze);

  double& setKat(){return KatZadany;}
  double getKat(){return KatZadany;}
  double& setOdleglosc(){return OdlegloscDoPrzejechania;}
  double getOdleglosc(){return OdlegloscDoPrzejechania;}

};



#endif
