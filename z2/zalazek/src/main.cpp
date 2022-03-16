#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"

using namespace std;




void WykonajTest(istream &rStrmWej)
{
  WyrazenieZesp   WyrZ_PytanieTestowe;
   
  while (WczytajWyrazenieZesp(WyrZ_PytanieTestowe, rStrmWej)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }
}





int main(int argc, char **argv)
{

  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
    cerr << endl;
    return 1;
  }

  ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {
    //
    // Tu trzeba wpisac wyswietlenie informacji, ze nie
    // mozna otworzyc pliku i nalezy wyswietlic jego nazwe.
    //
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WykonajTest(PlikTestu);
  
  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
