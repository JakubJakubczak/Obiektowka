//#include <chrono>
//#include <thread>s
#include <iostream>
#include <fstream>
//#include "lacze_do_gnuplota.hh"
//#include "PowierzchniaMarsa.hh"
#include "Scena.hh"
//#include "ObiektGeom.hh"
//#include "Kolory.hh"
//#include "Lazik.hh"
//#include "MacierzRotacji.hh"
//#include "SWektor.hh"


using namespace std;





int main()
{
  /*ObrysXY Obrys1,Obrys2;

  Obrys1._Wiersz_DolnyLewy[0]=40;
  Obrys1._Wiersz_DolnyLewy[1]=40;
  Obrys1._Wiersz_GornyPrawy[0]=60;
  Obrys1._Wiersz_GornyPrawy[1]=60;

  Obrys2._Wiersz_DolnyLewy[0]=30;
 Obrys2._Wiersz_DolnyLewy[1]=30;
Obrys2._Wiersz_GornyPrawy[0]=75;
Obrys2._Wiersz_GornyPrawy[1]=75;
 
 Obrys1.NakladanieObrysow(Obrys2);
  */




  
  Scena scena;
  int numer;
  char znak= 'm'; 
  while(znak!='k')
  {
    cout<<endl;
    scena.WypiszLazik();
    Wektor3D::WyswietlLiczbeObiektow();
    cout<<endl;
    cin>>znak;
  switch (znak)
  {
  case 'm':
    cout<<"j - jazda na wprost"<<endl;
    cout<<"o - zmien orientacje"<<endl;
    cout<<"w - wybor lazika"<<endl;
    cout<<"m - wyswietl menu"<<endl<<endl;
    cout<<"k - koniec dzialania programu"<<endl;
    break;

  case 'j':
    scena.menutranslacja();
  break;

    case 'w':
      scena.WypiszLaziki();
      cin>>numer;
      scena.WyborLazika(numer);
  break;

  case 'o':
    scena.menuobrot();
  break;

  case 'k':
    cout<<"Koniec programu"<<endl;
  return 0;
  break;

  default:
    break;
  }

  }
 Wektor3D::WyswietlLiczbeObiektow();
   
    cin.ignore(100,'\n');

}
