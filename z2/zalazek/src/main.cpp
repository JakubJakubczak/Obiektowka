#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"
#include "statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{
  WyrazenieZesp  WyrZ;
  Operator Op;
  LZespolona wynik, odp;
  int bledy=0;
  
  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
    cerr << endl;
    return 1;
  }
  
  ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {
    cerr<<"Nie można otworzyc pliku"<< argv[1]<<endl;
    return 1;
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;


  


  while (!PlikTestu.eof()) 
  {
  PlikTestu>>WyrZ;   // wczytanie  wyrazenia
  cout<<"Podaj wynik operacji: ";
  cout<<WyrZ<<endl; // wyswietlanie wyrazenia
  cout<<"Twoja odpowiedz :";	  
  wynik=Oblicz(WyrZ);                  // obliczanie wyniku
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
   DodajNiepoprawna();
  }
  else if (wynik==odp)
  {
	  cout<<"Odpowiedz poprawna"<<endl;
	  DodajPoprawna();
  }
  else
  {
	  cout<<"Blad. Prawidlowym wynikiem jest: "<<wynik<<endl;
	  DodajNiepoprawna();
  }
  bledy=0;
  cin.clear();
  cin.ignore(1000, '\n');   // nastepna linia
  }
   

   
  
  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
