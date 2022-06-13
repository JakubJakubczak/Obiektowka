
#ifndef LAZIK_HH
#define LAZIK_HH

#include <chrono>
#include <thread>
#include "lacze_do_gnuplota.hh"
#include "ObiektGeom.hh"

class ProbkaRegolitu;
/*!
 * \brief
 * 
 * Klasa modeluje Lazik. Dziedziczy on z klasy ObiektGeom  
 * Klasa posiada funkcjonalnosc sprawdzania kolizji
 */
class Lazik
  : public ObiektGeom
{
  double KatZadany; 
  double OdlegloscDoPrzejechania;

public:
/*!
 * \brief
 * 
 * Metoda sprawdzajaca czy lazik koliduje z aktywnym lazikiem
 *
 */
    TypKolizji CzyKolizja(const std::shared_ptr<Lazik>& Wsk_Lazik) const override;
  int ID() const override {return 1;}

  /*!
 * \brief
 * 
 * Metoda wirtualna lazika, ktora sluzy do wyswietlania obiektow klasy LazikSFR, gdyz AktywnyLazik jest klasy Lazik
 *
 */
  virtual void WyswietlProbki(){;};    
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
