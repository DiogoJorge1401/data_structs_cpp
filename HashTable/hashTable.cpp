#include "hashTable.h"
using namespace std;

HashTable::HashTable(int maxsize, int maxitems)
{
  max_items = maxitems;
  max_size = maxsize;
  quantity_items = 0;
  structure = new Student[maxsize];
}
HashTable::~HashTable()
{
  delete[] structure;
}
int HashTable::hashFunction(Student std)
{
  return std.getRA() % max_size;
}
int HashTable::getCurrentSize()
{
  return quantity_items;
}
bool HashTable::isFull()
{
  return quantity_items == max_items;
}
void HashTable::insert(Student std)
{
  if (isFull())
  {
    cout << "Hash Table is full!\n";
    return;
  }
  int location = hashFunction(std);
  while (structure[location].getRA() >= 0)
    location = (location + 1) % max_items;

  structure[location] = std;
  quantity_items++;
}
void HashTable::remove(Student std)
{
  int location = hashFunction(std);
  Student aux = structure[location];
  while (aux.getRA() != -1)
  {
    if (aux.getRA() == std.getRA())
    {
      cout << "Aluno removido: " << aux.getName() << endl;
      structure[location] = Student(-2, " ");
      quantity_items--;
      return;
    }
    location = (location + 1) % max_items;
    aux = structure[location];
  }

  cout << "Aluno não encontrado!\n";
}
void HashTable::search(Student &std, bool &state)
{
  int location = hashFunction(std);

  while (structure[location].getRA() != 1)
  {
    if (structure[location].getRA() == std.getRA())
    {
      state = true;
      std = structure[location];
      return;
    }
    location = (location + 1) % max_items;
  }

  state = false;
}

void HashTable::print()
{
  cout << "Hash Table:\n";
  for (int i = 0; i < max_size; i++)
  {
    Student std = structure[i];
    if (std.getRA() >= 0)
      cout << i << ": " << std.getRA() << " " << std.getName() << endl;
  }
}