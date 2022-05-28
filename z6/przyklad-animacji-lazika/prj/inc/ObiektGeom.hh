#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "MacierzRotacji.hh"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

/*!
 * \brief
 * 
 * Klasa modeluje obiekt geometryczny  
 *
 */
class ObiektGeom {
  //public:
  Wektor3D Polozenie;
  Wektor3D Skala;
  MacRotacji MacRot;
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
  
  public:
  /*!
 * \brief
 * 
 * Konstruktor klasy ObiektGeom  
 *
 */ 
  ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double polozenieX, double polozenieY, double polozenieZ);

  /*!
 * \brief
 * 
 * \return kolor  
 *
 */
    int WezKolorID() const { return _KolorID; }

  /*!
 * \brief
 * 
 * \return _NazwaObiektu  
 *
 */
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }

  /*!
 * \brief
 * 
 * \return _NazwaPliku_BrylaRysowana  
 *
 */
    const std::string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }
/*!
 * \brief
 * 
 * przelicza wierzcholki bryly  
 *
 */
  bool  Przelicz_i_Zapisz_Wierzcholki(double kat=0 );

/*!
 * \brief
 * 
 * \return Polozenie do modyfikacji  
 *
 */
  Wektor3D& setPolozenie(){return Polozenie;}

  /*!
 * \brief
 * 
 * \return Polozenie do odczytu  
 *
 */
  Wektor3D getPolozenie() const {return Polozenie;}

/*!
 * \brief
 * 
 * \return _NazwaObiektu do odczytu  
 *
 */
  std::string getNazwa() const {return _NazwaObiektu;}
   
};


#endif
