#include "Hohlzylinder.hh"
#include "Koerper.hh"
#include <cmath>
#include <cstdlib>

Hohlzylinder::Hohlzylinder(double nr, double nl , double ne, double nm) {
  r_ = nr;
  l_ = nl;
  e_ = ne;
  m_ = nm;
}

Vektor Hohlzylinder::punkt() {
  double R = sqrt((r_ * r_ - e_ * e_  ) * rand() / (double)RAND_MAX + e_ * e_ );
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = R* cos(phi);
  double y = R* sin(phi);
  return Vektor(x, y, z);
}

double Hohlzylinder::Janalytisch() {
  return (m_ *( r_ * r_ + e_ * e_  ))/2;
}