#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
  Macierz M; /*Wektor wek1,wek2,wynik; */
  double wyznacznik;
  

  
  cout << endl << " Start programu " << endl << endl;

  cin>>M;
  cout<<endl<<M;
  wyznacznik=M.wyznacznik();
  cout<<wyznacznik;
  cout<<M;
  

}
