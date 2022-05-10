

/*
   Program wczytuje znak, na podstawie ktorego okresla czy uklad row
   nan jest rzeczywisty czy zespolony, dostosowuje odpowiednio szablony,
   pozniej wprowadza macierz transponowana oraz wektor wyrazow wolnych
   i na podstawie wczytanych danych wyswietla uklad rownan. Wyswietla 
   napis mowiacy czy uklad jest oznaczony czy nie jest. Jesli jest to
   wyswietla rozwiazania ukladu, blad obliczen jako wektor i dlugosc tego
   wektora.
 */


#include <string>
#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"

using namespace std;



// test szablonu wektora dla double
void Test_SzablonWektor_double()
{
  cout << endl
       << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<double,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;

   W_wynik = W+W;
  cout << "  Wyswietlenie wyniku: W+W" << endl
       << "        " << W_wynik << endl
       << endl;
   W_wynik = 0;
  cout << "  Przyrownywanie wektora do 0" << endl
       << "        " << W_wynik << endl
       << endl;

  /* cout << "  Wczytaj wektor " << endl;
  cin >> W_wynik;
  cout << " Wczytany wektor " << endl
  << W_wynik << endl;*/
}


// test dla lzespolonej

void Test_SzablonWektor_LZespolona()
{
  cout << endl
       << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;


  SWektor<LZespolona,ROZMIAR>    W, W_wynik;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind].re = Ind;      W[Ind].im = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;

  W_wynik = W*2;
  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W_wynik << endl
       << endl;
  
  W_wynik = W*2-W;
  cout << "  Wyswietlenie wyniku: W-W*0.5" << endl
       << "        " << W_wynik << endl
       << endl;

   W_wynik = W+W;
  cout << "  Wyswietlenie wyniku: W+W" << endl
       << "        " << W_wynik << endl
       << endl;
   W_wynik = 0;
  cout << "  Przyrownywanie wektora do 0" << endl
       << "        " << W_wynik << endl
       << endl;

  /* cout << "  Wczytaj wektor " << endl;
  cin >> W_wynik;
  cout << " Wczytany wektor " << endl
  << W_wynik << endl;*/

}



int main()
{
  // Test_SzablonWektor_double();
  // Test_SzablonWektor_LZespolona();
  char znak;
  

  cout<<endl<<" Start programu " <<endl<<endl;
  
  cin>>znak;   // pobranie znaku
  if(znak=='r')
    {
      SUkladRownanLiniowych<double,ROZMIAR> UklRown;

      cin>>UklRown;
      cout<<UklRown;
      UklRown.RozwUklRow();
    }
  else if(znak=='z')
    {
      SUkladRownanLiniowych<LZespolona,ROZMIAR> UklRown;

      cin>>UklRown;
      cout<<UklRown;
      UklRown.RozwUklRow();
    }  
  else
    {
      cout<<"Wartosc podana to nie r ani z";
      return 0;
    }
   
  return 0;
}
