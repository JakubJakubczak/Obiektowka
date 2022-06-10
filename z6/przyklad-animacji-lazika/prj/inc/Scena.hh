 #ifndef SCENA_HH
 #define SCENA_HH

#include <memory>
//#include "Lazik.hh"
#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"
//#include "ProbkaRegolitu.hh"
#include "LazikSFR.hh"
/*!
 * \brief
 * 
 * Klasa modeluje scene na ktorej beda laziki i obiekty geometryczne  
 *
 */
class Scena{

   std::shared_ptr<Lazik> AktywnyLazik;
   std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;
   PzG::LaczeDoGNUPlota  Lacze;
   std::shared_ptr<ObiektGeom> ObiektKolidujacy;
  //  TypKolizji WynikKolizji;
  
  void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
  void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
  void UsunZListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
public:

/*!
 * \brief
 * 
 * Metoda sprawdza czy aktywny lazik koliduje z obiektami sceny
 *
 */
  TypKolizji CzyAktywnyLazikKoliduje(std::shared_ptr<ObiektGeom> & ObKolid) const;
  /*!
 * \brief
 * 
 * Obrot lazika razem z animacja
 *
 */
  void obrot();
  /*!
 * \brief
 * 
 * translacja lazika razem z animacja
 */
  void translacja();
  /*!
 * \brief
 * 
 * Podnoszenie probki przez lazikSFR
 */
  void PodniesProbke();  

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
 * Wypisywanie probek na scenie
 *
 */
  void WypiszProbki();
  
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
