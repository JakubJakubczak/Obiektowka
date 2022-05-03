#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona &operator = (double  Liczba);
  LZespolona  operator + ( LZespolona  Skl2) const;
  LZespolona  operator - ( LZespolona  Skl2) const;
  LZespolona  operator * ( LZespolona  Skl2) const;
  LZespolona  operator / ( LZespolona  Skl2) const;
  bool operator == ( LZespolona Arg2) const;
  LZespolona sprzezenie();
  double modul2();
  LZespolona  operator / ( double modul) const;
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba);
std::istream& operator >> (std::istream& wejs, LZespolona& lzesp);
std::ostream& operator << (std::ostream& wyjs, LZespolona lzesp);



#endif
