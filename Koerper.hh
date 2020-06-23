#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:
 
  virtual Vektor punkt()=0;
  virtual double mass()=0;
  virtual double rad()=0;
  virtual double hoehe()=0;
  virtual double extra()=0;
  virtual double Janalytisch()=0;
  virtual std::string name() {return "Koerper";}
  virtual std::string v1() {return " R[m]";}
  virtual std::string v2() {return " L[m]";}
  virtual std::string v3() {return " --- ";}
  virtual std::string v4() {return "M[kg]";}

};

#endif