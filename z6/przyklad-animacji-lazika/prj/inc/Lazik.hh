
#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"

class Lazik
     : public ObiektGeom
{
public:
  double KatOrientacji_st;
  double Szybkosc;
  double OdlegloscDoPrzejechania;

public:
  Lazik(const char* SNazwaPliku_BrylaWzorcowa, const char* SNazwaObiektu, int KOLORID, double PolozenieX, double PolozenieY, double PolozenieZ);
  void translacja( double odleglosc);
  void obrot();
};



#endif
