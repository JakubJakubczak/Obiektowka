#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


class Statystyka {
  //atrybuty
double poprawne;
double niepoprawne;
public:
  //konstruktor
Statystyka(double=0,double=0);
  //metody
void Wyswietl(Statystyka *stat);
void DodajPoprawna(Statystyka *stat);
void DodajNiepoprawna(Statystyka *stat);
double Oblicz(Statystyka *stat);

};




#endif
