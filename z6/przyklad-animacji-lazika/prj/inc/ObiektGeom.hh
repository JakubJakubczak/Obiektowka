#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "MacierzRotacji.hh"
#include "ObrysXY.hh"
#include "TypKolizji.hh"
#include <memory>

class Lazik;

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

//class Lazik;
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
  ObrysXY Obrys;
  
  public:

  void ZmienSkale(int x, int y, int z);
  virtual TypKolizji CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const=0;
  //{return TK_BrakKolizji;}
  virtual double getKat() const {return 0;}
  virtual int ID() const {return 0;}
  /*!
 * \brief
 * 
 * Konstruktor klasy ObiektGeom  
 *
 */ 
  ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double polozenieX, double polozenieY, double polozenieZ);
  virtual ~ObiektGeom(){}


  ObrysXY getObrys() const {return Obrys;}
  ObrysXY& setObrys() {return Obrys;}
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
