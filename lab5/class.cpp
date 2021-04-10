#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
  float x, y, radius;
public:
  Circle (float, float, float);
  void print();
  float area();
  float circumference();
  bool concentric(Circle c);
};

const float pi = 3.14159;

/* Constructor. Initializes x, y, and radius to the provided arguments.
 * 
 * a -- Initial x value.
 * b -- Initial y value.
 * c -- Initial radius value. 
 */
Circle::Circle(float a, float b, float c) {
  if (c<=0){
    cout<<"Radius provided less than or equal to zero"<<endl;
    exit(1);
  }
  this->x = a;
  this->y = b;
  this->radius = c;
}

/* Print a circle object.
 *
 * No arguments.
 */
void Circle::print() {
  cout << "Center: (" << this->x << ", " << this->y << ")"<< endl;
  cout <<"Radius: " << this->radius << endl;
}

/* Compute the area of a circle object.
 *
 * No arguments.
 *
 * Returns area of the circle object.
 */
float Circle::area() {
  return pi * this->radius*this->radius;
}

/* Compute circumference of a circle object.
 *
 * No arguments.
 * 
 * Returns circumference of circle object.
 */
float Circle::circumference() {
  return 2*pi*this->radius;
}

/* Test to see if another circle object is concentric.
 *
 * c -- Circle object to test against.
 *
 * Returns true if circle is concentric to c, false otherwise.
 */
bool Circle::concentric(Circle c) {
  return ((this->x==c.x)&&(this->y==c.y));
}

// DO NOT MODIFY
int main() {
  Circle c1(0, 0, 1);
  Circle c2(2.5, 2.5, 1);
  Circle c3(0, 0, 10);

  c1.print();
  cout << "C1 Circumference:" << setw(10) << fixed << setprecision(2) << c1.circumference() << endl;
  cout << "C1 Area:" << setw(19) << fixed << setprecision(2) << c1.area() << endl << endl;

  c2.print();
  cout << "C2 Circumference:" << setw(10) << fixed << setprecision(2) << c2.circumference() << endl;
  cout << "C2 Area:" << setw(19) << fixed << setprecision(2) << c2.area() << endl << endl;


  c3.print();
  cout << "C3 Circumference:" << setw(10) << fixed << setprecision(2) << c3.circumference() << endl;
  cout << "C3 Area:" << setw(19) << fixed << setprecision(2) << c3.area() << endl << endl;

  cout << "C1 and C2 are concentric? " << boolalpha << c1.concentric(c2) << endl;
  cout << "C1 and C3 are concentric? " << boolalpha << c1.concentric(c3) << endl;
  cout << "C2 and C3 are concentric? " << boolalpha << c2.concentric(c3) << endl;
}
