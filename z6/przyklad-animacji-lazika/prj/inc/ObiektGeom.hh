#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "SWektor.hh"
#include "SMacierz.hh"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class ObiektGeom {
public:
  Wektor3D Polozenie;
  Wektor3D Skala;
  Macierz3D MacRotacji;
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
  
  public:

  ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double polozenieX, double polozenieY, double polozenieZ);

    int WezKolorID() const { return _KolorID; }
  
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
  
    const std::string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }

  bool  Przelicz_i_Zapisz_Wierzcholki( );
  /* void const Przelicz_i_Zapisz_Wierzcholki(std::istream& StrmWe, std::ostream &StrmWy);*/
				     
};


#endif
