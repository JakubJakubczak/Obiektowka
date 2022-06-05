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

  
  Scena scena;
  int numer;
  char znak= 'm';

  while(znak!='k')
  {
    cout<<endl;
    scena.WypiszLazik();

    //  scena.ObiektySceny.back()->CzyKolizja(scena.AktywnyLazik);
    
    Wektor3D::WyswietlLiczbeObiektow();
    cout<<endl;
    cin>>znak;
  switch (znak)
  {
  case 'm':
    cout<<"j - jazda na wprost"<<endl;
    cout<<"o - zmien orientacje"<<endl;
    cout<<"w - wybor lazika"<<endl;
    cout<<"d - wyswietl probki na scenie"<<endl;
    cout<<"p - podnies probke(tylko dla SFR) "<<endl;
    cout<<"m - wyswietl menu"<<endl<<endl;
    cout<<"k - koniec dzialania programu"<<endl;
    break;

  case 'j':
    scena.menutranslacja();
  break;

  case 'p':
    scena.PodniesProbke();
    break;
  
    case 'w':
      scena.WypiszLaziki();
      cin>>numer;
      scena.WyborLazika(numer);
  break;

  case 'o':
    scena.menuobrot();
  break;

  case 'd':
    scena.WypiszProbki();
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
