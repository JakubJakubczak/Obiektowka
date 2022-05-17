#ifndef POWIERZCHNIAMARSA_HH
#define POWIERZCHNIAMARSA_HH

#include <memory>
#include "ObiektGeom.hh"
#include "Lazik.hh"

#include "lacze_do_gnuplota.hh"

class Scena{
   std::shared_ptr<Lazik> AktywnyLazik;
  std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;



};

#define ROMIAR_POWIERZCHNI_X    200
#define ROMIAR_POWIERZCHNI_Y    200
#define ROZMIAR_OCZKA_KRATY     10



bool Inicjalizuj_PowierzchnieMarsa(
				    PzG::LaczeDoGNUPlota  &rLacze
				  );

#endif
