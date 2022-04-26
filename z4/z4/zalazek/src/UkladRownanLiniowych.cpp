#include "UkladRownanLiniowych.hh"
#include <iostream>
#include <cstdlib>
#include "rozmiar.h"
#include <cmath>

#define ROZMIAR 3

using namespace std;

Macierz UkladRownanLiniowych::zamianaKolumny(int kolumna) const{
  int i;
  Macierz temp=Mac;
  for(i=0;i<ROZMIAR; i++)
    {
      temp(i,kolumna)=Wek[i];
    }
  return temp;
}

Wektor UkladRownanLiniowych::RozwUklRow(){
  int i;
  UkladRownanLiniowych Ukl=*this;    // uklad rownan
  UkladRownanLiniowych trans;   // uklad rownan transponowany

  trans=Ukl.transpozycja();
  
  Macierz Glow;  // macierz glowna juz transponowana;
  Macierz Zam[ROZMIAR]; // tablica macierzy dla odpowiednich podstawien

  Wektor wyniki; // rozwiazania ukladu rownan
  
  double WyznacznikGlow; // wyznacznik glowny
  double WyznacznikZam[ROZMIAR]; // wyznacznik z macierzy zamienionej

  Glow=Mac.transpozycja();    // transponowanie macierzy
  WyznacznikGlow=Glow.wyznacznik();  // obliczanie wyznacznika glownego

  if(WyznacznikGlow==0){  // sprawdzanie czy wyznacznik macierzy nie rowna sie 0
    cout<<" nie jest to uklad oznaczony";
    exit(0);
  }
  cout<<"Jest to uklad oznaczony"<<endl;
  for(i=0; i<ROZMIAR; i++){  // znajdowanie rozwiazan po kolei w petli
    Zam[i]=trans.zamianaKolumny(i);  // zamienianie odpowiedniej kolumny z wyrazani wolnymi
    WyznacznikZam[i] = Zam[i].wyznacznik();  // obliczanie wyznacznika
    wyniki[i] = WyznacznikZam[i] / WyznacznikGlow; // obliczanie rozwiazania x[i]
  }

  for(i=0;i<ROZMIAR;i++){  // wypisywanie rozwiazanan
    cout<<"x"<<i+1<<"="<<wyniki[i];
    cout<<endl;
  }

  return wyniki;
  }

UkladRownanLiniowych UkladRownanLiniowych::transpozycja () const
{
  int i,k;
  UkladRownanLiniowych temp1 = *this;   // macierz tymczasowa, ktora bedzie zmieniana i zwracana
  UkladRownanLiniowych temp2 = *this;   // macierz tymczasowa nie zmieniana

  for(i=0; i<ROZMIAR; i++){   // transponowanie
    for(k=0; k<ROZMIAR; k++){
      temp1.Mac(i,k)=temp2.Mac(k,i);
    }}

  return  temp1;
}

Wektor UkladRownanLiniowych::BladObl(Wektor &Wyn)
{
  UkladRownanLiniowych temp=*this;
  UkladRownanLiniowych trans=temp.transpozycja();
  Wektor Blad;
  double dlugosc=0;

  if(trans.Mac.wyznacznik()==0) exit(0);
  
  Blad = trans.Mac * Wyn - trans.Wek;    // obliczanie bledu

  cout<<"Wektor bledu: ( ";
  for(int i=0; i<ROZMIAR; i++)    // wypisywanie wektora bledu
    {
      cout<<Blad[i]<<" ";
    }
  cout<<")"<<endl;;
  for(int j=0; j<ROZMIAR; j++)
    {
      dlugosc = dlugosc + Blad[j] * Blad[j];      
    }
  cout<<"Dlugosc wektora bledu: "<<sqrt(dlugosc);
  return Blad;
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
  std::cin>>UklRown.Mac;
  std::cin>>UklRown.Wek;

  return Strm;
}

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown){
  // std::cout<<UklRown.Mac;
  // std::cout<<UklRown.Wek;
  for(int i=0; i<3; i++){
    if(i==1){
      std::cout<<"|  "<<UklRown.Mac[i]<<" | | x_"<<i+1<<" | "<<"="<<" | "<<UklRown.Wek[i]<<" |"<<endl;}
    else std::cout<<"|  "<<UklRown.Mac[i]<<" | | x_"<<i+1<<" | "<<" "<<" | "<<UklRown.Wek[i]<<" |"<<endl;
  }
  return Strm;
}
