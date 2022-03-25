#include <iostream>
#include "LZespolona.hh"


using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
  Wynik.im = (Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
  return Wynik;
}


/*
double modul2(){             // Modul do kwadratu liczby zespolonej
  double modul=(Skl2.re*Skl2.re)+(Skl2.im*Skl2.im);
    return modul;
    }

LZespolona operator / (LZespolona Skl2, double modul)
{ 

   LZespolona Wynik;

   if(modul2()=0.0){
    cerr<<"Blad. Dzielenie przez zero";
    return Wynik;  
  }
   else
   {
    Wynik.re = ((Skl1.re*Skl2.re)+(Skl1.im*Skl2.im))/modul2();
    Wynik.im = ((-Skl2.im*Skl1.re)+(Skl1.im*Skl2.re))/modul2();
   }


   return Wynik;

}
*/
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  if((Skl2.re*Skl2.re)+(Skl2.im*Skl2.im)==0){
    cerr<<"Blad. Dzielenie przez zero";
  }
  
  else{
    Wynik.re = ((Skl1.re*Skl2.re)+(Skl1.im*Skl2.im))/((Skl2.re*Skl2.re)+(Skl2.im*Skl2.im));
    Wynik.im = ((-Skl2.im*Skl1.re)+(Skl1.im*Skl2.re))/((Skl2.re*Skl2.re)+(Skl2.im*Skl2.im));
  }
  return Wynik;
}

ostream& operator << (ostream& wyjs, LZespolona& lzesp)     // przeciazenie operatora dla wyswietlania liczby zespolonej
{
	wyjs <<"("<<lzesp.re << showpos << lzesp.im <<noshowpos <<"i)";

	return wyjs;
}

istream& operator >> (istream& wejs, LZespolona& lzesp)      // przeciazenie operatora dla wczytywania liczby zespolonej
{
	char nawias1, nawias2, litera;

	wejs >> nawias1;
	if ( wejs.fail() )
		return wejs;

	if( nawias1!= '(' )
	{
		wejs.setstate(ios::failbit);
		return wejs;
	}

	wejs >> lzesp.re;
	if (wejs.fail())
		return wejs;

	wejs >> lzesp.im;
	if (wejs.fail())
		return wejs;
       
       	wejs >> litera;
	if (wejs.fail())
		return wejs;

	if(litera != 'i')
	{
		wejs.setstate(ios::failbit);
		return wejs;
	}
	wejs >> nawias2;
        if (wejs.fail())
		return wejs;
	if(nawias2!= ')')
	{
		wejs.setstate(ios::failbit);
		return wejs;
	}
	return wejs;
}

bool operator == (LZespolona Arg1, LZespolona Arg2)        // przeciazenie operatora dla przyrownywania liczb zespolonych
{
	return (Arg1.re == Arg2.re && Arg1.im == Arg2.im);
}
