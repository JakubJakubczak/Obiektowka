 #ifndef SCENA_HH
 #define SCENA_HH

#include "Lazik.hh"



class Scena{
   std::shared_ptr<Lazik> AktywnyLazik;
   std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;

  void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
  void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
};


#endif
