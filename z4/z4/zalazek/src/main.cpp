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
  // double wyznacznik;
  

  


  cout  << endl << " Start programu " << endl << endl;

  cin>>M;
  cout     <<endl<<M;
  
  cout<<"Wiersz 1: "<<M[0]<<endl;
  cout<<"Wiersz 2: "<<M[1]<<endl;
  cout<<"Liczba 1 wiersz 2 kolumna: "<<M(0,1)<<endl;
  cout<<"Liczba 2 wiersz 3 kolumna: "<<M(1,2)<<endl;
  
  cout<<M.wyznacznik()<<endl;
 
  cout<<"Wiersz 1: "<<M[0]<<endl;
  cout<<"Wiersz 2: "<<M[1]<<endl;
  cout<<"Liczba 1 wiersz 2 kolumna: "<<M(0,1)<<endl;
  cout<<"Liczba 2 wiersz 3 kolumna: "<<M(1,2)<<endl;
  
 
  // wyznacznik=M.wyznacznik();
  // dwa<<wyznacznik;
  
  

}
