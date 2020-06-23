#include "Vektor.hh"
#include "Koerper.hh"
#include "Kugelmantel.hh"
#include "Hohlzylinder.hh"
#include "Quader.hh"
#include "Kugel.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

static std::ofstream tr("traegheit.txt");

double traegheit(Koerper* k, Vektor a , Vektor u) {

  //std::cout << "berechne fuer " << k -> name () << std::endl;
  int N = 10000;
  double J = 0;     
  double m = k->mass() / N;
  
  for (int i = 0; i < N; ++i) {
    
    Vektor x = k->punkt();
    double r = ((x-a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag();  
  
    J += m * r * r;
  }
  return J;
}

std::unique_ptr<Koerper> Koerperliste(double k_R,double k_L,double k_E,double k_M,int i) {
    
  if (i==0) {std::unique_ptr<Koerper> k(new Zylindermantel(k_R, k_L, k_E, k_M ));  return k;}
  if (i==1) {std::unique_ptr<Koerper> k(new   Vollzylinder(k_R, k_L, k_E, k_M ));  return k;}
  if (i==2) {std::unique_ptr<Koerper> k(new   Hohlzylinder(k_R, k_L, k_E, k_M ));  return k;}
  if (i==3) {std::unique_ptr<Koerper> k(new    Kugelmantel(k_R, k_L, k_E, k_M ));  return k;}
  if (i==4) {std::unique_ptr<Koerper> k(new          Kugel(k_R, k_L, k_E, k_M ));  return k;}
  if (i==5) {std::unique_ptr<Koerper> k(new         Quader(k_R, k_L, k_E, k_M ));  return k;}
}

void Tabelle2(std::unique_ptr<Koerper> k, Vektor a , Vektor u){
 
 tr << std::setw(4) << k.get()->rad() << " |"
    << std::setw(4) << k.get()->hoehe() << " |"
    << std::setw(4) << k.get()->extra() << " |"
    << std::setw(4) << k.get()->mass() << " |"
    << std::setw(2) << a << " |" 
    << std::setw(2) << u << " ||" 
    << std::setw(13) <<(k.get()->Janalytisch() + (k.get()->mass())*std::pow((((a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag()),2)) << " |"
    << std::setw(12) << traegheit(k.get(),a,u) << std::endl;
}

void Tabelle1(int i){

  std::unique_ptr<Koerper> k(Koerperliste(1,1,1,1,i));

 tr << "Berechne f\u00FCr " << k.get() -> name () << ":" << std::endl
    << std::setw(5) << k.get()->v1() << "|"
    << std::setw(5) << k.get()->v2() << "|"
    << std::setw(5) << k.get()->v3() << "|"
    << std::setw(5) << k.get()->v4() << "|"
    << std::setw(11) << "a\u20D7" << " |"  //Bitte in Firefox öffnen
    << std::setw(11) << "u\u20D7" << " ||" 
    << std::setw(13) << "J analytisch" << " |"
    << std::setw(12) << "J berechnet"
    << "\n-----|-----|-----|-----|---------|---------||--------------|------------\n";

  Tabelle2( Koerperliste(1, 1, 0.5, 1, i), Vektor(0, 0, 0) , Vektor(0, 0, 1));
  Tabelle2( Koerperliste(1, 1, 0.5, 2, i), Vektor(0, 0, 0) , Vektor(0, 0, 1));
  Tabelle2( Koerperliste(2, 1, 1.5, 1, i), Vektor(0, 0, 0) , Vektor(0, 0, 1));
  Tabelle2( Koerperliste(1, 1, 0.5, 1, i), Vektor(0, 1, 0) , Vektor(0, 0, 1));
  Tabelle2( Koerperliste(1, 1, 0.5, 2, i), Vektor(0, 1, 0) , Vektor(0, 0, 1));
  Tabelle2( Koerperliste(2, 1, 1.5, 1, i), Vektor(0, 2, 0) , Vektor(0, 0, 1));

  tr << std::endl;
}

int main() {

  for (int i=0; i<6; ++i) {
    Tabelle1(i);
  }
  std::cout << "Fertig!" << std::endl;
  tr.close();
  return 0; 
}