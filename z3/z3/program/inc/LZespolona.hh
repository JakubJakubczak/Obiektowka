#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
 public:
  //atrybuty
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  //metody
  
  LZespolona  operator + ( LZespolona  Skl2) const;
  LZespolona  operator - ( LZespolona  Skl2) const;
  LZespolona  operator * ( LZespolona  Skl2) const;
  LZespolona  operator / ( LZespolona  Skl2) const;
  bool operator == ( LZespolona Arg2) const;

  //double modul2();
  //LZespolona  operator / (LZespolona Skl2, double modul);
  
};



/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

std::istream& operator >> (std::istream& wejs, LZespolona& lzesp);
std::ostream& operator << (std::ostream& wyjs, LZespolona& lzesp);


#endif
