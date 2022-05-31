#include "SWektor.hh"
//#include "Scena.hh"

class Scena;

class ObrysXY
{
public:
  Wektor2D _Wiersz_DolnyLewy;
  Wektor2D _Wiersz_GornyPrawy;

public:
    Wektor2D getDolnyLewy(){return _Wiersz_DolnyLewy;}  
    Wektor2D& setDolnyLewy(){return _Wiersz_DolnyLewy;}
    Wektor2D getGornyPrawy(){return _Wiersz_GornyPrawy;}
    Wektor2D& setGornyPrawy(){return _Wiersz_GornyPrawy;}

  ObrysXY(){_Wiersz_DolnyLewy=0; _Wiersz_GornyPrawy=0;}

 bool  NakladanieObrysow(ObrysXY Obrys)
  {
    if( ( this->_Wiersz_DolnyLewy[0] <= Obrys._Wiersz_GornyPrawy[0] &&
	  Obrys._Wiersz_DolnyLewy[0] <= this->_Wiersz_GornyPrawy[0] )
	    &&
	( this->_Wiersz_DolnyLewy[1] <= Obrys._Wiersz_GornyPrawy[1] &&
	  Obrys._Wiersz_DolnyLewy[1] <= this->_Wiersz_GornyPrawy[1] ) 
      )
      {
	std::cout<<"Przecieie";
    return true;
      }

    else {std::cout<<"Brak Przeciecia"; return false;}
  }
  
};


