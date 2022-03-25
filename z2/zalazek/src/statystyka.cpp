#include "statystyka.hh"


#include <iostream>

using namespace std;


void inicjalizuj(Statystyka *stat)
{
  stat->poprawne=0;
  stat->niepoprawne=0;
}
void Wyswietl(Statystyka *stat)
{
     cout<<"Ilosc dobrych odpowiedzi: "<<stat->poprawne<<endl;
     cout<<"Ilosc zlych odpowiedzi: "<<stat->niepoprawne<<endl;
     cout<<"Wynik procentowy poprawnych odpowiedzi: "<<Oblicz(stat)<<"%"<<endl;
}

void DodajPoprawna(Statystyka *stat)
{
        stat->poprawne++;
}
void DodajNiepoprawna(Statystyka *stat)
{
	stat->niepoprawne++;
}

double Oblicz(Statystyka *stat)
{
        
	return (stat->poprawne/(stat->poprawne+stat->niepoprawne))*100;
}
