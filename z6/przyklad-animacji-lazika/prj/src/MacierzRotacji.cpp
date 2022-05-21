#include "MacierzRotacji.hh"

Wektor3D MacRotacji::RotacjaZ(double kat) {

  kat=kat * (M_PI/180);
  MacRotacji MacRot;
  Wektor3D jednostkowyX;
  jednostkowyX[0]=1;
  jednostkowyX[1]=0;
  jednostkowyX[2]=0;
  
  MacRot(0,0)=cos(kat);
  MacRot(0,1)=-sin(kat);
  MacRot(0,2)=0;
  MacRot(1,0)=sin(kat);
  MacRot(1,1)=cos(kat);
  MacRot(1,2)=0;
  MacRot(2,0)=0;
  MacRot(2,1)=0;
  MacRot(2,2)=1;

       return MacRot*jednostkowyX;
}

