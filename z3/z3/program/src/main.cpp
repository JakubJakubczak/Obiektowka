#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"
#include "statystyka.hh"

using namespace std;



// wykonywanie testu na liczbach zespolonych

//  ifstream &PlikTestu - strumien, z ktorego bedziemy czytac pytania
//  WyrazenieZesp &WyrZ - obiekt WyrZ klasy  wyrazenie zespolone, na ktorym bedziemy robili obliczenia
//  Statystyka &stat - obiekt stat klasy Statystyka, ktory posluzy do robienia statystyki
//  LZespolona &wynik - obiekt wynik klasy LZespolona, ktory posluzy do przechowywania wyniku
//  LZespolona &odp - obiekt odp klasy LZespolona, ktory posluzy do przechowywania odpowiedzi uzytkownika

//  Zwraca statystyke testu

void WykonajTest(ifstream &PlikTestu, WyrazenieZesp &WyrZ, Statystyka &stat, LZespolona &wynik, LZespolona &odp)
{

  int bledy=0;
  
  
  while (!PlikTestu.eof())  // dopoki plik sie nie skonczy
  {
  PlikTestu>>WyrZ;   // wczytanie  wyrazenia
  if(PlikTestu.eof()) continue;      // warunek potrzebny, by ostatnie wyrazenie nie wczytywalo sie dwa razy 
  cout<<"Podaj wynik operacji: ";
  cout<<WyrZ<<endl; // wyswietlanie wyrazenia
  cout<<"Twoja odpowiedz :";
  wynik=WyrZ.Oblicz(WyrZ);                  // obliczanie wyniku
  cin>>odp;       // wprowadzanie odpoweidzi
  while(cin.fail() && bledy!=3) // jesli strumien jest w bledzie i bledy =!3
  {
	  cout<<"Blad zapisu liczby zespolonej. Sproboj jeszcze raz."<<endl;
	  cin.clear();   // czyszczenies strumienia
	  cout<<"Twoja odpowiedz: ";
          cin>>odp;
	  bledy++;
  }
  if(bledy==3)
  {
	  cout<<"Za duzo nieudanych prob. Odpowiedz jest bledna"<<endl;
   stat.DodajNiepoprawna(&stat);
  }
  else if (wynik==odp)
  {
	  cout<<"Odpowiedz poprawna"<<endl;
	  stat.DodajPoprawna(&stat);
  }
  else
  {
	  cout<<"Blad. Prawidlowym wynikiem jest: "<<wynik<<endl;
	  stat.DodajNiepoprawna(&stat);
  }
  bledy=0;
  cin.clear();
  cin.ignore(10000, '\n');   // nastepna linia
  }
   

  stat.Wyswietl(&stat);  // wyswietlanie statystyki
  
  PlikTestu.close();   // zamykanie pliku
}


int main(int argc, char **argv)
{
  WyrazenieZesp  WyrZ;
  LZespolona wynik, odp;
  Statystyka stat;


  // jesli nie podano nazwy testu przy wywolaniu to wyswietlamy komunikat
  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
    cerr << endl;
    return 1;
  }
  
  ifstream  PlikTestu(argv[1]);

  // jesli pliku nie otworzono to wyswietlamy komunikat
  if (PlikTestu.is_open() == false) {
    cerr<<"Nie można otworzyc pliku"<< argv[1]<<endl;
    return 1;
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  // wykonywanie testu
  WykonajTest(PlikTestu, WyrZ, stat, wynik, odp);
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
