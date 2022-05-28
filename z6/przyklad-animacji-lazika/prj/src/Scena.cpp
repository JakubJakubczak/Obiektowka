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

  std::cin.ignore(100,'\n');
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

void Scena::WypiszLaziki()
{
  for(std::list<std::shared_ptr<Lazik>>::iterator it = ObiektySceny.begin(); it!= ObiektySceny.end();  ++it)
    {
      std::cout<< (*it)->getNazwa()<<std::endl;
    }
}
