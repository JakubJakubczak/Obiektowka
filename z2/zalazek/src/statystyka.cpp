#include "statystyka.hh"


#include <iostream>

using namespace std;



void Wyswietl()
{
     cout<<"Ilosc dobrych odpowiedzi: "<<poprawne<<endl;
     cout<<"Ilosc zlych odpowiedzi: "<<niepoprawne<<endl;
     cout<<"Wynik procentowy poprawnych odpowiedzi: "<<Oblicz()<<"%"<<endl;
}

void DodajPoprawna()
{
        poprawne++;
}
void DodajNiepoprawna()
{
	niepoprawne++;
}x

double Oblicz()
{
        
	return (poprawne/(poprawne+niepoprawne))*100;
}
