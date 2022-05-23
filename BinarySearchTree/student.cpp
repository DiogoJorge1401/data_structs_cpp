#include "student.h"

using namespace std;

Student::Student()
{
  ra = -1;
  name = "";
}
Student::Student(int r, string n)
{
  ra = r;
  name = n;
}
string Student::getName()
{
  return name;
}
int Student::getRa()
{
  return ra;
}