#ifndef HOHLZYLINDER_HH
#define HOHLZYLINDER_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Hohlzylinder : public Koerper{
public:
  Hohlzylinder(double nr, double nl, double ne, double nm);

  Vektor punkt();
  double mass() {return m_;}
  double rad() {return r_;}
  double hoehe() {return l_;}
  double extra() {return e_;}
  double Janalytisch();
  std::string name() {return "Hohlzylinder";}
  std::string v1() {return "R2[m]";}
  std::string v2() {return " L[m]";}
  std::string v3() {return "R1[m]";}
  std::string v4() {return "M[kg]";}
   
private:
  double r_, l_, e_, m_;
};

#endif