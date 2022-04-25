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
  UkladRownanLiniowych   UklRown,wynik;   
   
   Wektor wyniki; 
    


  cout  << endl << " Start programu " << endl << endl;
  
  
  cin>>UklRown;
  wynik=UklRown.transpozycja();
  cout<<wynik;
  
  /* cin>>W;
  cout     <<endl<<M<<endl<<W;;
  
  cout<<"Wiersz 1: "<<M[0]<<endl;
  cout<<"Wiersz 2: "<<M[1]<<endl;
  cout<<"Liczba 1 wiersz 2 kolumna: "<<M(0,1)<<endl;
  cout<<"Liczba 2 wiersz 3 kolumna: "<<M(1,2)<<endl;
  
  cout<<M*W<<endl;
 
  cout<<"Wiersz 1: "<<M[0]<<endl;
  cout<<"Wiersz 2: "<<M[1]<<endl;
  cout<<"Liczba 1 wiersz 2 kolumna: "<<M(0,1)<<endl;
  cout<<"Liczba 2 wiersz 3 kolumna: "<<M(1,2)<<endl;
  
  */
  // wyznacznik=M.wyznacznik();
  // dwa<<wyznacznik;
  
  

}
