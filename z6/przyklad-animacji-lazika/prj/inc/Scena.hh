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

/*!
 * \brief
 * 
 * Klasa modeluje scene na ktorej beda laziki i obiekty geometryczne  
 *
 */
class Scena{
public:
   std::shared_ptr<Lazik> AktywnyLazik;
   std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;
   PzG::LaczeDoGNUPlota  Lacze;
  

  void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
  void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);

public:

  /*!
 * \brief
 * 
 * Konstruktor klasy  
 *
 */
  Scena();

  /*!
 * \brief
 * 
 * Metoda pozwalajaca na wybor Lazika    
 *
 */
  void WyborLazika(int i);

  /*!
 * \brief
 * 
 * Metoda wypisujaca laziki na scenie  
 *
 */
  void WypiszLaziki() ;

  /*!
 * \brief
 * 
 * Metoda wypisujaca AktywnyLazik na scenie  
 *
 */
  void WypiszLazik() const;

  /*!
 * \brief
 * 
 * Obrot AktywnegoLazika o zadany kat  
 *
 */
  void menuobrot();

  /*!
 * \brief
 * 
 * Translacja AktywnegoLazika o zadany kat  
 *
 */
  void menutranslacja();
};


#endif
