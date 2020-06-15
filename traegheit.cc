#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>
#include <iomanip>

static std::ofstream tr("traegheit.txt");

int traegheit(double N, double M, double ZM_R, Vektor a , Vektor u, double ZM_L = 1 ) {

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    // Abstand Punkt x und Gerade a + t*u
    double r = ((x-a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag();  
    //std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }

   std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));

  double I = 0;     // Massentraegheitsmoment
  m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = vz->punkt();
    // Abstand Punkt x und Gerade a + t*u
    double r = ((x-a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag();  
    //std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    I += m * r * r;
  }


 tr   << std::setw(3) << ZM_R << " |" 
      << std::setw(3) << ZM_L << " |" 
      << std::setw(4) << M << " |"
      << std::setw(2) << a << " |" 
      << std::setw(2) << u << " ||" 
      << std::setw(14) << M*(ZM_R*ZM_R+std::pow((((a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag()),2)) << " |"
      << std::setw(13) << J << " ||" 
      << std::setw(14) << M*(ZM_R*ZM_R/2+std::pow((((a).Vektor::kreuz(u)).Vektor::betrag() / u.Vektor::betrag()),2))  << " |" 
      << std::setw(13) << I << std::endl;

  return 0;
}

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  
  tr  << std::setw(3) << "R[m]" << "|" 
      << std::setw(3) << "L[m]" << "|" 
      << std::setw(3) << "M[kg]" << "|"
      << std::setw(11) << "a\u20D7" << " |"  //Bitte in Firefox öffnen
      << std::setw(11) << "u\u20D7" << " ||" 
      << std::setw(8) << "Jzm analytisch"  << " |"
      << std::setw(7) << "Jzm berechnet" << " ||" 
      << std::setw(8) << "Jvz analytisch"  << " |" 
      << std::setw(11) << "Jvz berechnet"
      << "\n----|----|-----|---------|---------||---------------|--------------||---------------|-------------\n";

  Vektor a(0,0,0); // Punkt auf der Rotationsachse
  Vektor u(0,0,1); // Richtung der Rotationsachse

  traegheit(N,1,1,a,u);
  traegheit(N,2,1,a,u);
  traegheit(N,1,2,a,u);
  a = Vektor(0,1,0);
  traegheit(N,1,1,a,u);
  traegheit(N,2,1,a,u);
  a = Vektor(0,2,0);
  traegheit(N,1,2,a,u);
  
  std::cout << "Fertig!" << std::endl;
  tr.close();
  
  return 0;
}
