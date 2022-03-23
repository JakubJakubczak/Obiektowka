#include <iostream>
#include "WyrazenieZesp.hh"
#include <string>

using namespace std;

/*
   Przeciazenie operatora >>, które pozwala wykonac wczytywanie typu wyliczeniowego Operator.
*/
  istream& operator >> (istream &StrmWe, Operator &Op){
  char Znak;
  const string TabZnakowOp = "+-*/";
  Operator TabOper[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};

  StrmWe >> Znak;

  const size_t idxZnakOp = TabZnakowOp.find_first_of(Znak);

    if (idxZnakOp == string::npos){
    StrmWe.setstate(ios::failbit);
    return StrmWe;
  }

    
  Op = TabOper[idxZnakOp];
  return StrmWe;
}

// wyswietlanie operatora
ostream& operator << ( Operator &Op, ostream &StrmWe){
            switch(Op)
	{
		case Op_Dodaj:
		        StrmWe << "+";
			break;
		case Op_Odejmij:
		        StrmWe << "-";
			break;
		case Op_Mnoz:
			StrmWe << "*";
			break;
		case Op_Dziel:
			StrmWe << "/";
			break;
	}  
}




//Wczytywanie wyrazenia zespolonego

istream &operator>>(istream &wejs, WyrazenieZesp& WyrZ)
{
        wejs >> WyrZ.Arg1;
	wejs >> WyrZ.Op;
	wejs >> WyrZ.Arg2;
	return wejs;
}


// przeciazenie operatora wyswietlania dla wyrazenia zespolonego

ostream &operator<<( WyrazenieZesp& WyrZ, ostream &wyjs)
{
        wyjs << WyrZ.Arg1;
	wyjs << WyrZ.Op;
	wyjs << WyrZ.Arg2;
	return wyjs;
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

