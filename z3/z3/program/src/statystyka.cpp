#include "statystyka.hh"


#include <iostream>

using namespace std;
//konstruktor
Statystyka::Statystyka(double p, double n)
{
  poprawne=p;
  niepoprawne=n;
}
// wyswietlanie statystyki
void Statystyka::Wyswietl(Statystyka *stat)
{
     cout<<"Ilosc dobrych odpowiedzi: "<<stat->poprawne<<endl;
     cout<<"Ilosc zlych odpowiedzi: "<<stat->niepoprawne<<endl;
     cout<<"Wynik procentowy poprawnych odpowiedzi: "<<Oblicz(stat)<<"%"<<endl;
}
// dodawanie do poprawnego wyniku 1
void Statystyka::DodajPoprawna(Statystyka *stat)
{
        stat->poprawne++;
}
//dodawanie do niepoprawnego wyniku 1
void Statystyka::DodajNiepoprawna(Statystyka *stat)
{
	stat->niepoprawne++;
}
// obliczanie uzyskanego wyniku 
double Statystyka::Oblicz(Statystyka *stat)
{
        
	return (stat->poprawne/(stat->poprawne+stat->niepoprawne))*100;
}
