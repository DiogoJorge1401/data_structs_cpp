#include "student.h"
using namespace std;

Student::Student()
{
  RA = -1;
  name = " ";
}
Student::Student(int r, string n) : RA(r), name(n) {}
int Student::getRA(){return RA;}
string Student::getName() { return name; }