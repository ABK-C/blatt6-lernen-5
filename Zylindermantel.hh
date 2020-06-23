#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Zylindermantel : public Koerper {
public:
  Zylindermantel(double nr, double nl, double ne, double nm);

  Vektor punkt();
  double mass() {return m_;}
  double rad() {return r_;}
  double hoehe() {return l_;}
  double extra() {return 0;}
  double Janalytisch();
  std::string name() {return "Zylindermantel";}
  std::string v1() {return " R[m]";}
  std::string v2() {return " L[m]";}
  std::string v3() {return " --- ";}
  std::string v4() {return "M[kg]";}

private:
  double r_, l_, e_, m_;
};

#endif