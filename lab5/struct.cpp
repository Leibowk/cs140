#include <iostream>
#include <iomanip>
using namespace std;

// TYPEDEFS
typedef struct circle_st circle_t;

struct circle_st {
  float x, y, radius;
};

// PROTOTYPES
void printCircle(circle_t c);
float area(circle_t c);
float circumference(circle_t c);
bool concentric(circle_t c1, circle_t c2);

// GLOBALS
const float pi = 3.14159;

/* Print a circle structure.
 *
 * c -- Circle to be printed.
 */
void printCircle(circle_t c) {
  // TODO
  cout << "Center: (" << c.x << ", " << c.y << ")"<< endl;
  cout <<"Radius: " << c.radius << endl;
}

/* Compute the area of a circle structure. Assumes 3.14159 as 
 * estimation for pi.
 *
 * c -- Circle to compute area of.
 *
 * Returns the area of the circle structure.
 */
float area(circle_t c) {
  return pi * c.radius*c.radius;
}

/* Compute the circumference of a circle structure. Assumes 3.14159
 * as estimation for pi.
 *
 * c -- Circle to compute circumference of.
 *
 * Returns the circumference of the circle structure.
 */
float circumference(circle_t c) {
  return 2*pi*c.radius;
}

/* Test two circle structures to see if they are concentric.
 * 
 * c1, c2 -- Circle structures to test.
 * 
 * Returns true if circles are concentric, false if they are not.
 */
bool concentric(circle_t c1, circle_t c2) {
  return ((c1.x==c2.x)&&(c1.y==c2.y));
}

// DO NOT MODIFY
int main() {
  circle_t c1, c2, c3;

  c1.x = 0;
  c1.y = 0;
  c1.radius = 1;

  c2.x = 2.5;
  c2.y = 2.5;
  c2.radius = 1;

  c3.x = 0;
  c3.y = 0;
  c3.radius = 10;

  printCircle(c1);
  cout << "C1 Circumference:" << setw(10) << fixed << setprecision(2) << circumference(c1) << endl;
  cout << "C1 Area:" << setw(19) << fixed << setprecision(2) << area(c1) << endl << endl;

  printCircle(c2);
  cout << "C2 Circumference:" << setw(10) << fixed << setprecision(2) << circumference(c2) << endl;
  cout << "C2 Area:" << setw(19) << fixed << setprecision(2) << area(c2) << endl << endl;

  printCircle(c3);
  cout << "C3 Circumference:" << setw(10) << fixed << setprecision(2) << circumference(c3) << endl;
  cout << "C3 Area:" << setw(19) << fixed << setprecision(2) << area(c3) << endl << endl;

  cout << "C1 and C2 are concentric? " << boolalpha << concentric(c1, c2) << endl;
  cout << "C1 and C3 are concentric? " << boolalpha << concentric(c1, c3) << endl;
  cout << "C2 and C3 are concentric? " << boolalpha << concentric(c2, c3) << endl;
}
