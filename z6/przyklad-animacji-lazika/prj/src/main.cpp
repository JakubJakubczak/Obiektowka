//#include <chrono>
//#include <thread>
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
  /*PzG::LaczeDoGNUPlota  Lacze;
   
  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  Lazik  Ob1("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, 0, 0, 0);
  Lazik  Ob2("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, 60, 60, 0);
  Lazik  Ob3("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, -20, 70, 0);  

  //Ob2.Polozenie= MacRot.RotacjaZ(90) * 20 + Ob2.Polozenie;
  cout<<Ob2.Polozenie;
  
  DodajDoListyRysowania(Lacze,Ob1);
  DodajDoListyRysowania(Lacze,Ob2);
  DodajDoListyRysowania(Lacze,Ob3);

  
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Ob2.Przelicz_i_Zapisz_Wierzcholki();
  Ob3.Przelicz_i_Zapisz_Wierzcholki();
  */

  

 
  

   cin.ignore(100,'\n');
   /*
    Ob2.OdlegloscDoPrzejechania=-30;
    Ob2.translacja(Lacze);
    
    Ob2.KatZadany=90;
    cin.ignore(100,'\n');
    Ob2.obrot(Lacze);

    Ob2.KatZadany=-90;
    cin.ignore(100,'\n');
    Ob2.obrot(Lacze);
    
    
    Ob2.translacja(Lacze);
    cin.ignore(100,'\n');

    cout<<Ob2.Polozenie<<endl;
    cout<<Ob2.KatOrientacji_st<<endl;*/
    Wektor3D::WyswietlLiczbeObiektow();
}
