 #ifndef SCENA_HH
 #define SCENA_HH

#include <list>
#include <memory>
#include "Lazik.hh"
#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"

class Scena{
   std::shared_ptr<Lazik> AktywnyLazik;
   std::list<std::shared_ptr<Lazik>> ObiektySceny;
   PzG::LaczeDoGNUPlota  Lacze;
  

  void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
  void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);

public:
  Scena();
  void WyborLazika(int i);
  void WypiszLaziki() ;
  void WypiszLazik() const;
  void menuobrot();
  void menutranslacja();
};


#endif
