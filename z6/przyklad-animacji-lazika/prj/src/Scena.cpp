#include "Scena.hh"

using namespace std::literals::chrono_literals;


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
 * wspoldzielone do obiektow Lazik i ProbkaRegolitu i dodaje te wskazniki do listy. Nastepnie
 * dodaje do listy rysowania te obiekty i przelicza dla nich wierzcholki.
 * Ustawia wskaznik AktywnyLazik na Ob1 i rysuje Lacze.
 */

Scena::Scena()
{
  Inicjalizuj_Lacze(Lacze);
  Inicjalizuj_PowierzchnieMarsa(Lacze);


  std::shared_ptr<LazikSFR> Ob1 = std::make_shared<LazikSFR> ("bryly_wzorcowe/szescian3.dat","SFR",Kolor_JasnoNiebieski, 0, 0, 0);
  ObiektySceny.push_back(Ob1);

  std::shared_ptr<Lazik> Ob2 = std::make_shared<Lazik> ("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, 60, 60, 0);
  ObiektySceny.push_back(Ob2);
  
  std::shared_ptr<Lazik> Ob3 = std::make_shared<Lazik> ("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, -20, 70, 0); 
  ObiektySceny.push_back(Ob3);

  std::shared_ptr<ProbkaRegolitu> Ob4 = std::make_shared<ProbkaRegolitu> ("bryly_wzorcowe/szescian2.dat","Probka 1",Kolor_Czerwony, -50, -30, 0); 
  ObiektySceny.push_back(Ob4);

  std::shared_ptr<ProbkaRegolitu> Ob5 = std::make_shared<ProbkaRegolitu> ("bryly_wzorcowe/szescian2.dat","Probka 2",Kolor_Czerwony, -70, 10, 0); 
  ObiektySceny.push_back(Ob5);

  std::shared_ptr<ProbkaRegolitu> Ob6 = std::make_shared<ProbkaRegolitu> ("bryly_wzorcowe/szescian2.dat","Probka 3",Kolor_Czerwony, 20, -80, 0); 
  ObiektySceny.push_back(Ob6);

  std::shared_ptr<ProbkaRegolitu> Ob7 = std::make_shared<ProbkaRegolitu> ("bryly_wzorcowe/szescian2.dat","Probka 4",Kolor_Czerwony, 30, 70, 0); 
  ObiektySceny.push_back(Ob7);

  
  DodajDoListyRysowania(Lacze,*Ob1);
  DodajDoListyRysowania(Lacze,*Ob2);
  DodajDoListyRysowania(Lacze,*Ob3);
  DodajDoListyRysowania(Lacze,*Ob4);
  DodajDoListyRysowania(Lacze,*Ob5);
  DodajDoListyRysowania(Lacze,*Ob6);
  DodajDoListyRysowania(Lacze,*Ob7);
  
  Ob1->Przelicz_i_Zapisz_Wierzcholki();
  Ob2->Przelicz_i_Zapisz_Wierzcholki();
  Ob3->Przelicz_i_Zapisz_Wierzcholki();
  Ob4->Przelicz_i_Zapisz_Wierzcholki();
  Ob5->Przelicz_i_Zapisz_Wierzcholki();
  Ob6->Przelicz_i_Zapisz_Wierzcholki();
  Ob7->Przelicz_i_Zapisz_Wierzcholki();

  
  AktywnyLazik=Ob1;

  Lacze.Rysuj();
}


void Scena::WyborLazika(int i)
{
  int n=1;

  for(std::list<std::shared_ptr<ObiektGeom>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
      if((*it)->ID()==1 || (*it)->ID()==3)
	{
      if(n==i) AktywnyLazik = std::static_pointer_cast<Lazik>(*it);
      ++n;
        }
    }
}

void Scena::WypiszLaziki () 
{
  int i=1;
	
  for(std::list<std::shared_ptr<ObiektGeom>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
      if((*it)->ID()==1 || (*it)->ID()==3)
	 {
      std::cout<<i<<". Nazwa: "<< (*it)->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< (*it)->getPolozenie()<<std::endl;
      std::cout<<"   Orientacja[st]: "<< (*it)->getKat()<<std::endl;
      i++;
         }
    }
}

void Scena::WypiszProbki () 
{
  int i=1;
	
  for(std::list<std::shared_ptr<ObiektGeom>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
       if((*it)->ID()==2)
	 {
      std::cout<<i<<". Nazwa: "<< (*it)->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< (*it)->getPolozenie()<<std::endl;
      //std::cout<<"   Orientacja[st]: "<< (*it)->getKat()<<std::endl;
      i++;
         }
    }
}


void Scena::WypiszLazik () const
{
  if(AktywnyLazik->ID()==1)
    {
      std::cout<<"Aktywny Lazik ";     
      std::cout<<"   Nazwa: "<< AktywnyLazik->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< AktywnyLazik->getPolozenie()<<std::endl;
      std::cout<<"   Orientacja[st]: "<< AktywnyLazik->getOrientacja()<<std::endl;
    }
  else
    {
       std::cout<<"Aktywny Lazik ";     
      std::cout<<"   Nazwa: "<< AktywnyLazik->getNazwa()<<std::endl;
      std::cout<<"   Polozenie: "<< AktywnyLazik->getPolozenie()<<std::endl;
      std::cout<<"   Orientacja[st]: "<< AktywnyLazik->getOrientacja()<<std::endl;

      AktywnyLazik->WyswietlProbki();
    }
 
}

/*!
 * \brief
 * 
 * Metoda wyznacza wektor jednostkowy w strone osi x, ktory nastepnie moze byc  * rotowany przez macierz rotacji. Gdy zna kierunek przejazu zmienia polozenie
 * o OdlegloscDoPrzjechania. Przejazd jest animowany i rozbity na dwie funkcje,
 * by mogl byc mozliwy przejazd o wartosc minusowa
 */

void Scena::translacja()
{
  Wektor3D polozenie = AktywnyLazik->getPolozenie();
  MacRotacji MacRot;
   Wektor3D jednosX;
  jednosX[0]=1;
  jednosX[1]=0;
  jednosX[2]=0;

  if(AktywnyLazik->getOdleglosc() > 0)
    {
      for(int i=1; i<AktywnyLazik->getOdleglosc() + 1; ++i)
      {
	AktywnyLazik->setPolozenie() = MacRot.RotacjaZ(AktywnyLazik->getOrientacja()) * jednosX * i   + polozenie;
	AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(AktywnyLazik->getOrientacja());

        if(this->CzyAktywnyLazikKoliduje(ObiektKolidujacy) != TK_BrakKolizji) // sprawdzanie kolizji
	  {
	    //  std::cout<<"Kolizja";
	    AktywnyLazik->setPolozenie() = MacRot.RotacjaZ(AktywnyLazik->getOrientacja()) * jednosX * (i-1)   + polozenie;
	    AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(AktywnyLazik->getOrientacja());
	    break;
	  }

	
  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
    }

  if(AktywnyLazik->getOdleglosc()<0)
    {
      for(int i=-1; i>AktywnyLazik->getOdleglosc() - 1; --i)
      {
	AktywnyLazik->setPolozenie() = MacRot.RotacjaZ(AktywnyLazik->getOrientacja()) * jednosX * i   + polozenie;
	AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(AktywnyLazik->getOrientacja());
        if(this->CzyAktywnyLazikKoliduje(ObiektKolidujacy) != TK_BrakKolizji) // sprawdzanie kolizji
	  {
	    //std::cout<<"Kolizja";
	    AktywnyLazik->setPolozenie() = MacRot.RotacjaZ(AktywnyLazik->getOrientacja()) * jednosX * (i+1)   + polozenie;
	    AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(AktywnyLazik->getOrientacja());
	    break;
	  }

	Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
      }
    }

}

/*!
 * \brief
 * 
 * Metoda obraca lazik do stopni o wartosci KatZadany. Obracanie zaczyna sie  
 * od momentu wczesniejszego polozenia lazika i jest animowane. Zostalo 
 * rozlozone na dwa przypadki, by lazik mogl sie obracac o minusowa wartosc
 */
void Scena::obrot()
{
  if(AktywnyLazik->getKat() == AktywnyLazik->getOrientacja()) AktywnyLazik->setOrientacja()=AktywnyLazik->getKat();
  
  if(AktywnyLazik->getKat() > AktywnyLazik->getOrientacja())
    {     
 
  for(int i=AktywnyLazik->getOrientacja()+1; i<AktywnyLazik->getKat()+1; ++i)
      {
	 AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(i);
	
	if(this->CzyAktywnyLazikKoliduje(ObiektKolidujacy) != TK_BrakKolizji) // sprawdzanie kolizji
	  {
	    // std::cout<<"Kolizja";
	      AktywnyLazik->setOrientacja()=i-1;
	      AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(i-1);
	    break;
	  }

  Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
    AktywnyLazik->setOrientacja()=AktywnyLazik->getKat();
      }
          }

  if(AktywnyLazik->getKat() < AktywnyLazik->getOrientacja())
    {
      for(int i=AktywnyLazik->getOrientacja()-1; i>AktywnyLazik->getKat()-1; --i)
      {
	 AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(i);
       
	if(this->CzyAktywnyLazikKoliduje(ObiektKolidujacy) != TK_BrakKolizji) // sprawdzanie kolizji
	  {
	    // std::cout<<"Kolizja";
	    AktywnyLazik->setOrientacja()=i+1;
	    AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki(i+1);

	    break;
	  }
   Lacze.Rysuj();
  std::this_thread::sleep_for(50ms);
  AktywnyLazik->setOrientacja()=AktywnyLazik->getKat();
      }
            }

}

void Scena::menuobrot()
{

  double kat;
  std::cout<<"Podaj Orientacje lazika:  "<<std::endl;
  std::cout<<"Wartosc Kata>"; std::cin>>kat;

  AktywnyLazik->setKat()=kat;
  this->obrot();
}

void Scena::menutranslacja()
{
  double odleglosc;
  std::cout<<"Podaj odleglosc na jaka ma sie przemiescic lazik(w jednostkach sceny) "<<std::endl;
  std::cout<<"Odleglosc>"; std::cin>>odleglosc;

  AktywnyLazik->setOdleglosc()=odleglosc;
  this->translacja();

}

/*!
 * \brief
 * 
 * Metoda ustawia WynikKolizcji na jej brak, ObKolid na nullptr. Sprawdza czy aktywny Lazik koliduje z ktoryms
 * obiektem sceny. Jesli koliduje zwraca wynik kolizji.
 *
 */
TypKolizji Scena::CzyAktywnyLazikKoliduje(std::shared_ptr<ObiektGeom>& ObKolid) const
{
  
  TypKolizji  WynikKolizji = TK_BrakKolizji;
  ObKolid = nullptr;

  for(const std::shared_ptr<ObiektGeom> &Ob: ObiektySceny)
    {
      if(Ob == AktywnyLazik) continue;

      WynikKolizji = Ob->CzyKolizja(AktywnyLazik);

	if(WynikKolizji != TK_BrakKolizji)
	  {
            ObKolid = Ob;
	    return WynikKolizji;
	  } 	
    }
  return WynikKolizji;
}


void Scena::UsunZListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  // PzG::InfoPlikuDoRysowania *wInfoPliku;
  
   rLacze.UsunNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  //wInfoPliku->ZmienKolor(rOb.WezKolorID());
}
/*!
 * \brief
 * 
 * Jesli AktywnyLazik jest obiektem klasy LazikSFR i ObiektKolidujacy jest ProbkaRegolitu to jest mozliwosc
 * podniesienia probki. Wtedy zostaje dodana probka na liste lazika, probka  zostaje usunieta z listy do rysownia
 * i z listy obiektow sceny, a nastepnie Lacze jest ponownie rysowane.
 *
 */
void Scena::PodniesProbke()
{
  if(AktywnyLazik->ID() != 3)
    {
  std::cout<<"Zwykly Lazik nie moze zebrac probki";
    }
  
  else
   {  
  
  if(ObiektKolidujacy->ID() != 2)
    {
      std::cout<<"Obiekt kolidujacy nie jest probka";
    }
  else
    {
      std::static_pointer_cast<LazikSFR>(AktywnyLazik)->DodajProbke(std::static_pointer_cast<ProbkaRegolitu>(ObiektKolidujacy));
      UsunZListyRysowania(Lacze, *ObiektKolidujacy);
      ObiektySceny.remove(ObiektKolidujacy);
      Lacze.Rysuj();
    }
   }
}
