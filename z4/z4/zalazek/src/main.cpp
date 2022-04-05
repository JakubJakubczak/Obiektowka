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
  Wektor wek1,wynik;
  double mnoznik;
  

  
  cout << endl << " Start programu " << endl << endl;

  cin>>wek1>>mnoznik;
  wynik=wek1/mnoznik;
  cout<<wynik;

}
