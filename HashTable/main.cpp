#include <iostream>
#include "hashTable.h"

using namespace std;

int hashTableSize, maxElements, option;

class MyProgram
{
  HashTable *hashTable = NULL;

public:
  MyProgram(HashTable *ht) : hashTable(ht) {}
  void insert()
  {
    int ra;
    string name;
    cout << "Qual é o RA do aluno?\n";
    cin >> ra;
    cout << "Qual é o nome do aluno?\n";
    cin >> name;
    Student student = Student(ra, name);
    hashTable->insert(student);
  }
  void remove()
  {
    int ra;
    cout << "Qual é o RA do aluno a ser removido?\n";
    cin >> ra;
    Student st(ra, "");
    hashTable->remove(st);
  }
  void search()
  {
    int RA;
    bool searchResult;

    cout << "Qual é o RA do aluno a ser buscado?\n";
    cin >> RA;

    Student st(RA, " ");
    hashTable->search(st, searchResult);

    if (!searchResult)
    {
      cout << "Aluno não encontrado!\n";
      return;
    }
    cout << "\n--------------------\n";
    cout << "Nome: " << st.getName() << "\n"
         << "RA: " << st.getRA() << "\n";
    cout << "--------------------";
  }
  void print()
  {
    hashTable->print();
  }
};

void start()
{
  cout << "Digite o tamanho da Hash Table: ";
  cin >> hashTableSize;
  cout << "Digite o número máximo de elementos: ";
  cin >> maxElements;
  cout << "O fator de carga é: " << float(maxElements) / float(hashTableSize);
}

void options()
{
  static HashTable studentHash(hashTableSize, maxElements);
  static MyProgram myProgram(&studentHash);
  switch (option)
  {
  case 0:
    break;
  case 1:
    myProgram.insert();
    break;
  case 2:
    myProgram.remove();
    break;
  case 3:
    myProgram.search();
    break;
  case 4:
    myProgram.print();
    break;
  }
}

void menu()
{
  cout << "\n\n";
  cout
      << "Digite 0 para parar o algoritmo!\n"
      << "Digite 1 para inserir um aluno!\n"
      << "Digite 2 para remover um aluno!\n"
      << "Digite 3 para buscar um aluno!\n"
      << "Digite 4 para imprimir a tabela hash!\n\n";
  cin >> option;
  options();
}

int main(int argc, const char *argv[])
{
  cout << "Programa gerador de Hash Table\n";
  start();

  do
  {
    menu();
  } while (option);
  return 0;
}