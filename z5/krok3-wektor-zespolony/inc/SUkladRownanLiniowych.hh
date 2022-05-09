#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <iomanip>
#include "SMacierz.hh"

using namespace std;





// szablon klasy SUkladRownanLiniowych
/*****************************************************************************************
 *   Klasa UkladRownanLiniowych zawiera obiekt klasy Macierz oraz obiekt klasy Wektor.
 *   Klasa umozliwia zamiane wybranej kolumny macierzy z wektorem wyrazow wolnych,
 *   transponowanie macierzy w ukladzie rownan, oraz wyswietlanie i wczytywanie ukladu
 *   rownan.    
 ****************************************************************************************/
template<typename STyp, int SWymiar>
class SUkladRownanLiniowych {
  SMacierz<STyp, SWymiar> Mac;   
  SWektor<STyp, SWymiar> Wek;   // wektor wyrazow wolnych

  /*  Funkcja zamianaKolumny zamienia kolumne macierzy na wektor wyrazow wolnych
   *  
   *  Dane wejsciowe:
   *  kolumna - kolumna ktora chcemy zamienic
   *
   *  Dane wyjsciowe:
   *  temp - macierz z zamieniona kolumna na wektor wyrazu wolnego 
   */
  
  SMacierz<STyp,SWymiar> zamianaKolumny(int kolumna) const;
  // metody ubliczne
public:
  /*  Funkcja transponuje (tylko!)macierz w klasie UkladRownanLiniowych
   *  
   *  Dane wejsciowe:
   *  brak
   *
   *  Dane wyjsciowe:
   *  temp1 - UkladRownanLiniowych z transponowana macierza
   */
  SUkladRownanLiniowych<STyp, SWymiar> transpozycja () const;
   /*  Funkcja RozwUklRow rozwiazuje uklad rownan metoda Cramera i wypisuje rozwiazania
   *  
   *  Dane wejsciowe:
   *  brak
   *
   *  Dane wyjsciowe:
   *  wyniki - wektor zawierajacy rozwiazania ukladu
   */
  SWektor<STyp,SWymiar> RozwUklRow();
  /*  Funkcja BladObl wyznacza blad obliczen macierzy w postaci Wektora i jego dlugosci
   *  Funkcja wypisuje wektor bledu i dlugosc tego wektora.   
   *  
   *  Dane wejsciowe:
   *  Wyn - Wynik obliczonej macierzy w postaci wektora
   *
   *  Dane wyjsciowe:
   *  Blad - Blad obliczen zapisany w postaci wektora
   */
  
  //Wektor BladObl(Wektor &Wyn);
  
  // zaprzyjaznienie przeciazenia strumieni

  
  
  //  friend istream& operator >> (istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown);
  //  friend ostream& operator << (ostream &Strm, const SUkladRownanLiniowych<STyp,SWymiar> UklRown);


  // interfejs do klasy
  SMacierz<STyp,SWymiar>& setMac(); // zwraca referencje do macierzy Mac
  SMacierz<STyp, SWymiar> getMac() const; // zwraca macierz Mac
  SWektor<STyp,SWymiar>& setWek();  // zwraca referencje do wektora Wek
  SWektor<STyp,SWymiar> getWek() const; // zwraca wektor Wek
};
template<typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::zamianaKolumny(int kolumna) const{
  int i;
  SMacierz<STyp, SWymiar> temp=Mac;
  for(i=0;i<ROZMIAR; i++)
    {
      temp(i,kolumna)=Wek[i];
    }
  return temp;
}
  
template<typename STyp, int SWymiar>
SUkladRownanLiniowych<STyp, SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::transpozycja () const
  {
  int i,k;
  SUkladRownanLiniowych<STyp,SWymiar> temp1 = *this;   // macierz tymczasowa, ktora bedzie zmieniana i zwracana
  SUkladRownanLiniowych<STyp,SWymiar> temp2 = *this;   // macierz tymczasowa nie zmieniana

  for(i=0; i<ROZMIAR; i++){   // transponowanie
    for(k=0; k<ROZMIAR; k++){
      temp1.Mac(i,k)=temp2.Mac(k,i);
    }}

  return  temp1;
}


template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::RozwUklRow(){
  int i;
  SUkladRownanLiniowych<STyp,SWymiar> Ukl=*this;    // uklad rownan
  SUkladRownanLiniowych<STyp,SWymiar> trans;   // uklad rownan transponowany

  trans=Ukl.transpozycja();
  
  SMacierz<STyp,SWymiar> Glow;  // macierz glowna juz transponowana;
  SMacierz<STyp,SWymiar> Zam[ROZMIAR]; // tablica macierzy dla odpowiednich podstawien

  SWektor<STyp,SWymiar> wyniki; // rozwiazania ukladu rownan
  
  STyp WyznacznikGlow; // wyznacznik glowny
  STyp WyznacznikZam[ROZMIAR]; // wyznacznik z macierzy zamienionej

  Glow=Mac.transpozycja();    // transponowanie macierzy
  WyznacznikGlow=Glow.wyznacznik();  // obliczanie wyznacznika glownego

  if(WyznacznikGlow==0){  // sprawdzanie czy wyznacznik macierzy nie rowna sie 0
    cout<<" nie jest to uklad oznaczony";
    exit(0);
  }
  cout<<"Jest to uklad oznaczony"<<endl;
  for(i=0; i<ROZMIAR; i++){  // znajdowanie rozwiazan po kolei w petli
    Zam[i]=trans.zamianaKolumny(i);  // zamienianie odpowiedniej kolumny z wyrazani wolnymi
    WyznacznikZam[i] = Zam[i].wyznacznik();  // obliczanie wyznacznika
    wyniki[i] = WyznacznikZam[i] / WyznacznikGlow; // obliczanie rozwiazania x[i]
  }

  for(i=0;i<ROZMIAR;i++){  // wypisywanie rozwiazanan
    cout<<"x"<<i+1<<"="<<wyniki[i];
    cout<<endl;
  }

  return wyniki;
  }

template<typename STyp, int SWymiar>
SMacierz<STyp,SWymiar>& SUkladRownanLiniowych<STyp, SWymiar>::setMac(){ return Mac;}
template<typename STyp, int SWymiar>
SMacierz<STyp, SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::getMac() const { return Mac;}
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar>& SUkladRownanLiniowych<STyp, SWymiar>::setWek(){ return Wek;}
template<typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp, SWymiar>::getWek() const{  return Wek;}

/*
 *  Przeciazenie input dla klasy UkladRownanLiniowych, po lewej stronie strumien, po prawej obiekt.
 *  Wczytuje elementy klasy.
 *
 *  Dane wejsciowe:
 *
 *  Strm - strumien
 *  UklRown - obiekt klasy UkladRownanLiniowych
 *
 *  Dane wyjsciowe:
 *  Strm - zwraca strumien
 */
template <typename STyp, int SWymiar>
istream& operator >> (istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown){

  
 
  Strm>>UklRown.setMac();
  Strm>>UklRown.setWek();

  return Strm;
}


/*
 *  Przeciazenie output dla klasy UkladRownanLiniowych, po lewej stronie strumien, po prawej obiekt.
 *  Wyswietla elementy klasy.
 *
 *  Dane wejsciowe:
 *
 *  Strm - strumien
 *  UklRown - obiekt klasy UkladRownanLiniowych
 *
 *  Dane wyjsciowe:
 *  Strm - zwraca strumien
 */
template <typename STyp, int SWymiar>
ostream& operator << ( ostream &Strm,  const SUkladRownanLiniowych<STyp,SWymiar>  UklRown){
  Strm<<fixed << setprecision(2);
  Strm<< UklRown.getMac();
  Strm<< UklRown.getWek();
  /* for(int i=0; i<3; i++){
    if(i==1){
      cout<<"|  "<<UklRown.Mac[i]<<" | | x_"<<i+1<<" | "<<"="<<" | "<<UklRown.Wek[i]<<" |"<<endl;}
    else cout<<"|  "<<UklRown.Mac[i]<<" | | x_"<<i+1<<" | "<<" "<<" | "<<UklRown.Wek[i]<<" |"<<endl;
    }*/
  return Strm;
}
#endif
