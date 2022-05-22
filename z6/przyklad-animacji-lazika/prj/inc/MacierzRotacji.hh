#ifndef MACIERZROTACJI_HH
#define MACIERZROTACJI_HH

#include <cmath>
#include "SMacierz.hh"




class MacRotacji
 :  public  Macierz3D
{
public:
  MacRotacji RotacjaZ(double kat);
  
};


#endif
