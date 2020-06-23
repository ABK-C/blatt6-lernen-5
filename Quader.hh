#ifndef QUADER_HH
#define QUADER_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Quader : public Koerper {
public:
  Quader(double nr, double nl, double ne, double nm);

  Vektor punkt();
  double mass() {return m_;}
  double rad() {return r_;}
  double hoehe() {return l_;}
  double extra() {return e_;}
  double Janalytisch();
  std::string name() {return "Quader";}
  std::string v1() {return " x[m]";}
  std::string v2() {return " y[m]";}
  std::string v3() {return " z[m]";}
  std::string v4() {return "M[kg]";}

private:
  double r_, l_, e_, m_;
};

#endif