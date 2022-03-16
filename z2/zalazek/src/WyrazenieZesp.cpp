#include <iostream>
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */




// Funkcja wczytujaca wyrazenie zespolone
bool WczytajWyrazenieZesp(WyrazenieZesp &rWyrZ, std::istream &rStrmWe)
{
  char pomin;
  rStrmWe >> nawias;
   rStrmWe >> rWyrZ.Arg1.re;
   rStrmWe >> rWyrZ.Arg1.im;
   rStrmWe >> pomin>>pomin;
    rStrmWe >> rWyrZ.Op;
    rStrmWe >> nawias;
   rStrmWe >> rWyrZ.Arg2.re;
   rStrmWe >> rWyrZ.Arg2.im;
  
  return rStrmWe.fail() == false;
}

bool WczytajLiczbeZespolona(WyrazenieZesp rWyrZ)
{
  cout<<"Podaj czesc rzeczywista liczby zespolonej";
  cin>>rWyrZ.Arg1.re;
  cout<<"Podaj czesc urojona liczby zespolonej";
  cin>>rWyrZ.Arg1.im;
    
}


// Funkcja wyswietlajaca wyrazenie zespolone
void Wyswietl(WyrazenieZesp  WyrZ){
  std::cout.precision(2);
  std::cout << std::fixed << "(" << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im << std::noshowpos << "i)"<<WyrZ.Op
	                  << "(" << WyrZ.Arg2.re << std::showpos << WyrZ.Arg2.im << std::noshowpos << "i);
}


//Funkcja obliczajaca wyrazenie zespolone
LZespolona Oblicz(WyrazenieZesp  WyrZ){
  int wynik;
  switch(WyrZ.Op){

  case +: Wynik =  WyrZ,Arg1 + WyrZ.Arg2;
    return Wynik;
    break;
  case -: Wynik =  WyrZ.Arg1 - WyrZ.Arg2;
    return Wynik;
    break;
  case *: Wynik =  WyrZ.Arg1 * WyrZ.Arg2;
    return Wynik;
    break;
  case /: Wynik =  WyrZ.Arg1 / WyrZ.Arg2;
    return Wynik;
    break;

  default: cout<<"blad";

  }

}

