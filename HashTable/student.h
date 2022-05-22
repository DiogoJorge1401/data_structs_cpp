#include <iostream>

class Student
{
private:
  int RA;
  std::string name;

public:
  Student();
  Student(int, std::string);
  int getRA();
  std::string getName();
};