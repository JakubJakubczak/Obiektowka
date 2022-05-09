#include "LZespolona.hh"
#include <iomanip>

using namespace std;


/*!
 * Podstawia do liczby zespolonej liczbę rzeczywistą.
 * Powoduje to, że w części urojonej zostanie automatycznie podstawiona
 * wartość 0.
 */
LZespolona &LZespolona::operator = (double  Liczba)
{
  this->re = Liczba; this->im = Liczba;
  return *this;
}

/*
 * Sprawdza czy liczba zespolona jest rowna 0.
 * Jesli tak to zwraca prawde, jesli nie to false
 */

bool LZespolona::operator ==(double  Liczba)
{
  if(this->re == Liczba && this->im == Liczba) return true;
  else return false;
  
}

/*!
 * Realizuje mnozenie liczby zespolonej przez liczbę rzeczywistą (typ double)
 * Argumenty:
 *    Mnozna         - pierwszy argument operacji mnozenia (liczba zespolona),
 *    Mnoznik_Liczba - drugi argument operacji mnozenia (liczba rzeczywista).
 * Zwraca:
 *    Iloczyn dwoch argumentów przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba)
{
  LZespolona  Wynik;

  Wynik.re = Mnozna.re * Mnoznik_Liczba;
  Wynik.im = Mnozna.im * Mnoznik_Liczba;
  return Wynik;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */



LZespolona LZespolona::operator + (  LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznica dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - ( LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnozenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * ( LZespolona  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = ((this->re)*Skl2.re)-((this->im)*Skl2.im);
  Wynik.im = ((this->re)*Skl2.im)+((this->im)*Skl2.re);
  return Wynik;
}
/*
 * Zwraca sprzezenie do liczby zespolonej
 */
LZespolona LZespolona::sprzezenie()
{
  LZespolona wynik;
  wynik.re=re;
  wynik.im=-im;

  return wynik;
}
/*
 * Zwraca modul liczby zespolonej podniesiony do kwadratu
 */

double LZespolona::modul2(){             // Modul do kwadratu liczby zespolonej
  double modul=(LZespolona::re*LZespolona::re)+(LZespolona::im*LZespolona::im);
    return modul;
    }
/*!
 * Realizuje dzielenie liczy zespolonej przez liczbe.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenie - LZespolona,
 *    modul - dzielnik.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (double modul) const
{ 

   LZespolona Wynik;

   if(modul==0){
    cerr<<"Blad. Dzielenie przez zero";
  }
   else
   {
    Wynik.re = LZespolona::re/modul;
    Wynik.im = LZespolona::im/modul;
   }


   return Wynik;

}
/*!
 * Realizuje dzielenie liczy zespolonej przez liczbe zespolona.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenie - LZespolona,
 *    Skl2 - drugi skladnik dzielenia - LZespolona.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / ( LZespolona  Skl2) const
{
  LZespolona  Wynik;

  if(Skl2.modul2()==0){
    cerr<<"Blad. Dzielenie przez zero";
  }
  
  else{
    Wynik = (*this)*Skl2.sprzezenie()/Skl2.modul2();
  }
  return Wynik;
}

/*
 * Przeciazenie operatora wyswietlania LZespolonej
 * Argumenty:
 *    wyjs - strumien wyjsciowy,
 *    lzesp 
 * Zwraca:
 *    wyjs
 */

ostream& operator << (ostream& wyjs, LZespolona lzesp)     // przeciazenie operatora dla wyswietlania liczby zespolonej
{
	wyjs <<"("<<lzesp.re << showpos << lzesp.im <<noshowpos <<"i)";

	return wyjs;
}

/*
 * Przeciazenie operatora wczytywania LZespolonej
 * Argumenty:
 *    wejs - strumien wyjsciowy,
 *    lzesp 
 * Zwraca:
 *    wyjs
 */

istream& operator >> (istream& wejs, LZespolona& lzesp)      // przeciazenie operatora dla wczytywania liczby zespolonej
{
	char nawias1, nawias2, litera;

	wejs >> nawias1;
	if ( wejs.fail() )   // jesli pobranie znaku sie nie powiodlo
		return wejs;

	if( nawias1!= '(' )
	{
	  wejs.setstate(ios::failbit); // ustaw failbit
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

/*
 * Przeciazenie operatora porownujace dwie liczby zespolone,
 * zwraca 0 gdy liczby sie nie zgadzaja i 1 gdy sie zgadzaja
 */

bool LZespolona::operator == ( LZespolona Arg2) const        
{
	return (this->re == Arg2.re && this->im == Arg2.im);
}

