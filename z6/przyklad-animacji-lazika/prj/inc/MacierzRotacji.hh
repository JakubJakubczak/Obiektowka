#ifndef MACIERZROTACJI_HH
#define MACIERZROTACJI_HH

#include <cmath>
#include "SMacierz.hh"


/*!
 * \brief
 * 
 * Klasa modeluje pojecie Macierzy Rotacji.  
 * Dziedzczy ona z klasy Macierz3D
 */
class MacRotacji
 :  public  Macierz3D
{
public:
  /*!
 * \brief
 * 
 * Macierz Rotacji wzgledem osi Z  
 *
 */
  MacRotacji RotacjaZ(double kat);
  
};


#endif
