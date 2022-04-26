#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
   Program wczytuje macierz transponowana oraz wektor wyrazow wolnych
   i na podstawie wczytanych danych wyswietla uklad rownan. Wyswietla 
   napis mowiacy czy uklad jest oznaczony czy nie jest. Jesli jest to
   wyswietla rozwiazania ukladu, blad obliczen jako wektor i dlugosc tego
   wektora.
 */


int main()
{
  UkladRownanLiniowych   UklRown;   
   
   Wektor wyniki; 
    
  cout  << endl << " Start programu " << endl << endl;
  
  
  cin>>UklRown;  // wczytanie ukladu
  cout<<UklRown;  // wyswietlenie go
  wyniki=UklRown.RozwUklRow(); // rozwiazanie go, wyswietlenie i podstawienie wyniku do zmiennej wyniki
  UklRown.BladObl(wyniki); // obliczenie bledu jako wektora i jego dlugosci i wyswietlenie tych rzeczy
    
}
