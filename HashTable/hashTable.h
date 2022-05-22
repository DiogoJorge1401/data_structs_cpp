#include "student.h"

class HashTable
{
public:
  HashTable(int, int);
  ~HashTable();
  bool isFull();
  int getCurrentSize();
  void insert(Student);
  void remove(Student);
  void search(Student&, bool&);
  void print();

private:
  int hashFunction(Student);
  int max_items;
  int quantity_items;
  int max_size;
  Student *structure;
};