#include "UkladRownanLiniowych.hh"
#include <iostream>
#include <cstdlib>
#include "rozmiar.h"

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
    cout<<"Jest to układ nieoznaczony";
    exit(0);
  }

  for(i=0; i<ROZMIAR; i++){  // znajdowanie rozwiazan po kolei w petli
    Zam[i]=trans.zamianaKolumny(i);  // zamienianie odpowiedniej kolumny z wyrazani wolnymi
    WyznacznikZam[i] = Zam[i].wyznacznik();  // obliczanie wyznacznika
    wyniki[i] = WyznacznikZam[i] / WyznacznikGlow; // obliczanie rozwiazania x[i]
  }

  for(i=0;i<ROZMIAR;i++){
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

  for(i=0; i<ROZMIAR; i++){
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

  Blad = trans.Mac * Wyn - trans.Wek;    // obliczanie bledu

  cout<<"Wektor bledu: ( ";
  for(int i=0; i<ROZMIAR; i++)    // wypisywanie wektora bledu
    {
      cout<<Blad[i]<<" ";
    }
  cout<<")";
  return Blad;
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
  std::cin>>UklRown.Mac;
  std::cin>>UklRown.Wek;

  return Strm;
}

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown){
  std::cout<<UklRown.Mac;
  std::cout<<UklRown.Wek;
  
  return Strm;
}
