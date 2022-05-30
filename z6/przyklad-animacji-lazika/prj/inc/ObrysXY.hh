#include "SWektor.hh"

class ObrysXY
{
  Wektor2D _Wiersz_DolnyLewy;
  Wektor2D _Wiersz_GornyPrawy;

public:
    Wektor2D getDolnyLewy(){return _Wiersz_DolnyLewy;}  
    Wektor2D& setDolnyLewy(){return _Wiersz_DolnyLewy;}
    Wektor2D getGornyPrawy(){return _Wiersz_GornyPrawy;}
    Wektor2D& setGornyPrawy(){return _Wiersz_GornyPrawy;}
};
