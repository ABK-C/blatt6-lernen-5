#include "Kugel.hh"
#include "Koerper.hh"
#include <cmath>
#include <cstdlib>

Kugel::Kugel(double nr, double nl , double ne, double nm) {
  r_ = nr;
  l_ = nl;
  e_ = ne;
  m_ = nm;
}

Vektor Kugel::punkt() {
  double R = r_ *  cbrt(rand() / (double)RAND_MAX );
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double roh = acos(1 - 2 * (rand() / (double)RAND_MAX));

  double x = R * cos(phi) * sin(roh);
  double y = R * sin(phi) * sin(roh);
  double z = R * cos(roh);
  return Vektor(x, y, z);
}

double Kugel::Janalytisch() {
  return (m_ * r_ * r_)*2/5;
}