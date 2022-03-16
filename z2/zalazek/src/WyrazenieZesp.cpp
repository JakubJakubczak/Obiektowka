#include <iostream>
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */




// Funkcja wczytujaca wyrazenie zespolone
int WczytajWyrazenieZesp(WyrazenieZesp rWyrZ )
{
  cout<<"Podaj czesc rzeczywista 1 liczby zespolonej"; //1 liczba zespolona
  cin>>rWyrZ.Arg1.re;
  cout<<"Podaj czesc urojona 1 liczby zespolonej";
  cin>>rWyrZ.Arg1.im;

  cout<<"Wprowadz operator";
  cin<<rWyrZ.Op;
        if(rWyrZ.Op == '+')
	{
	  rWyrZ.Op=Op_Dodaj;
	}
	 if(rWyrZ.Op == '-')
	{
	  rWyrZ.Op=Op_Ddejmij;
	}
	  if(rWyrZ.Op == '*')
	{
	  rWyrZ.Op=Op_Mnoz;
	}
	   if(rWyrZ.Op == '/')
	{
	  rWyrZ.Op=Op_Dziel;
	}

}
  
  cout<<"Podaj czesc rzeczywista 2 liczby zespolonej"; //2 liczba zespolona
  cin>>rWyrZ.Arg1.re;
  cout<<"Podaj czesc urojona 2 liczby zespolonej";
  cin>>rWyrZ.Arg1.im;
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
LZespolona Oblicz(WyrazenieZesp WyrZ)
{
	LZespolona Wynik;

	if(WyrZ.Op == Op_Dodaj)
	{
		Wynik= WyrZ.Arg1 + WyrZ.Arg2;
	}
	if(WyrZ.Op == Op_Odejmij)
	{
		Wynik= WyrZ.Arg1 - WyrZ.Arg2;
	}
	if(WyrZ.Op == Op_Mnoz)
	{
		Wynik= WyrZ.Arg1 * WyrZ.Arg2;
	}
	if(WyrZ.Op == Op_Dziel)
	{		
	      	Wynik= WyrZ.Arg1 / WyrZ.Arg2;
        
	}
	return Wynik;
}

