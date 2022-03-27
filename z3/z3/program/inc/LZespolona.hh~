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
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};



/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

//double modul2();
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator / (LZespolona Skl2, double modul);
bool operator == (LZespolona Arg1, LZespolona Arg2);
std::istream& operator >> (std::istream& wejs, LZespolona& lzesp);
std::ostream& operator << (std::ostream& wyjs, LZespolona& lzesp);


#endif
