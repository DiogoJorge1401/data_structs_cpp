#include <iostream>

class Student
{
public:
  Student();
  Student(int ra, std::string name);
  std::string getName();
  int getRa();

private:
  int ra;
  std::string name;
};