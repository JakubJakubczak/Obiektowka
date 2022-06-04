
#ifndef LAZIK_HH
#define LAZIK_HH

#include <chrono>
#include <thread>
#include "lacze_do_gnuplota.hh"
#include "ObiektGeom.hh"

/*!
 * \brief
 * 
 * Klasa modeluje Lazik. Dziedziczy on z klasy ObiektGeom  
 * Klasa posiada funkcjonalnosc translacji i rotacji Lazika na Laczu
 */
class Lazik
  : public ObiektGeom
{
  double KatOrientacji_st;
  double KatZadany; 
  double OdlegloscDoPrzejechania;

public:
    TypKolizji CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const override;
  int ID() const override {return 1;}
  /*!
 * \brief
 * 
 * Konstruktor klasy Lazik  
 *
 */
  Lazik(const char* SNazwaPliku_BrylaWzorcowa, const char* SNazwaObiektu, int KOLORID, double PolozenieX, double PolozenieY, double PolozenieZ);
  virtual ~Lazik(){}

  /*!
 * \brief
 * 
 * \return KatZadany do modyfikacji  
 *
 */
  double& setKat(){return KatZadany;}
  /*!
 * \brief
 * 
 * \return KatZadany do odczytu  
 *
 */
  double getKat() const override{return KatZadany;}

  /*!
 * \brief
 * 
 * \return KatOrientacji_st do modyfikacji  
 *
 */

  double& setOrientacja(){return KatOrientacji_st;}
  /*!
 * \brief
 * 
 * \return KatOrientacji_st do odczytu  
 *
 */
  double getOrientacja() const {return KatOrientacji_st;}

  /*!
 * \brief
 * 
 * \return OdlegloscDoPrzejechania do modyfikacji  
 *
 */

  
  double& setOdleglosc(){return OdlegloscDoPrzejechania;}

  /*!
 * \brief
 * 
 * \return OdlegloscDoPrzejechania do odczytu 
 *
 */
  double getOdleglosc()const{return OdlegloscDoPrzejechania;}

};



#endif
