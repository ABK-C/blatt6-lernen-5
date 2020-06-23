#include "Quader.hh"
#include "Koerper.hh"
#include <cmath>
#include <cstdlib>

Quader::Quader(double nr, double nl , double ne, double nm) {
  r_ = nr;
  l_ = nl;
  e_ = ne;
  m_ = nm;
}

Vektor Quader::punkt() {
  double x = r_ * (rand() / (double)RAND_MAX - 0.5);
  double y = l_ * (rand() / (double)RAND_MAX - 0.5);
  double z = e_ * (rand() / (double)RAND_MAX - 0.5);
  return Vektor(x, y, z);
}

double Quader::Janalytisch() {
  return (m_ * (r_ * r_ + l_ * l_ ))/12;
}