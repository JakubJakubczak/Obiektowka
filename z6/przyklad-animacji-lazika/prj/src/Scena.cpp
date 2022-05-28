#include "Scena.hh"



/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Scena::Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void Scena::DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

/*!
 * \brief
 * 
 * Konstruktor sceny inicjalizuje lacze i powierzchnie marsa. Tworzy wskazniki 
 * wspoldzielone do obiektow Lazik i dodaje te wskazniki do listy. Nastepnie
 * dodaje do listy rysowania Laziki i przelicza dla nich wierzcholki.
 * Ustawia wskaznik AktywnyLazik na Ob1 i rysuje Lacze.
 */

Scena::Scena()
{
  Inicjalizuj_Lacze(Lacze);
  Inicjalizuj_PowierzchnieMarsa(Lacze);


  std::shared_ptr<Lazik> Ob1 = std::make_shared<Lazik> ("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, 0, 0, 0);
  ObiektySceny.push_back(Ob1);

  std::shared_ptr<Lazik> Ob2 = std::make_shared<Lazik> ("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, 60, 60, 0);
  ObiektySceny.push_back(Ob2);
  
  std::shared_ptr<Lazik> Ob3 = std::make_shared<Lazik> ("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, -20, 70, 0); 
  ObiektySceny.push_back(Ob3);

 
  DodajDoListyRysowania(Lacze,*Ob1);
  DodajDoListyRysowania(Lacze,*Ob2);
  DodajDoListyRysowania(Lacze,*Ob3);

  
  Ob1->Przelicz_i_Zapisz_Wierzcholki();
  Ob2->Przelicz_i_Zapisz_Wierzcholki();
  Ob3->Przelicz_i_Zapisz_Wierzcholki();

  AktywnyLazik=Ob1;

  Lacze.Rysuj();
}


void Scena::WyborLazika(int i)
{
  int n=1;
  for(std::list<std::shared_ptr<Lazik>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
      if(n==i) AktywnyLazik = *it;
      ++n;
    }
}

void Scena::WypiszLaziki () 
{
  int i=1;
  for(std::list<std::shared_ptr<Lazik>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
      std::cout<<i<<". Nazwa: "<< (*it)->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< (*it)->getPolozenie()<<std::endl;
      std::cout<<"   Orientacja[st]: "<< (*it)->getKat()<<std::endl;
      i++;
    }
}

void Scena::WypiszLazik () const
{     std::cout<<"Aktywny Lazik ";     
      std::cout<<"   Nazwa: "<< AktywnyLazik->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< AktywnyLazik->getPolozenie()<<std::endl;
      std::cout<<"   Orientacja[st]: "<< AktywnyLazik->getKat()<<std::endl;

 
}

void Scena::menuobrot()
{

  double kat;
  std::cout<<"Podaj kat obrotu w stopniach "<<std::endl;
  std::cout<<"Wartosc Kata>"; std::cin>>kat;

  AktywnyLazik->setKat()=kat;
  AktywnyLazik->obrot(Lacze);
}

void Scena::menutranslacja()
{
  double odleglosc;
  std::cout<<"Podaj odleglosc na jaka ma sie przemiescic lazik(w jednostkach sceny) "<<std::endl;
  std::cout<<"Odleglosc>"; std::cin>>odleglosc;

  AktywnyLazik->setOdleglosc()=odleglosc;
  AktywnyLazik->translacja(Lacze);

}
