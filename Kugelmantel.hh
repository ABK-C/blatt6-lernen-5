#ifndef KUGELMANTEL_HH
#define KUGELMANTEL_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Kugelmantel : public Koerper{
public:
  Kugelmantel(double nr, double nl, double ne, double nm);

  Vektor punkt();
  double mass() {return m_;}
  double rad() {return r_;}
  double hoehe() {return 0;}
  double extra() {return 0;}
  double Janalytisch();
  std::string name() {return "Kugelmantel";}
  std::string v1() {return " R[m]";}
  std::string v2() {return " --- ";}
  std::string v3() {return " --- ";}
  std::string v4() {return "M[kg]";}
   
private:
  double r_, l_, e_, m_;
};

#endif