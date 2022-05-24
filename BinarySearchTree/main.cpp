#include <iostream>
#include "avlTree.h"

using namespace std;

AVLTree avlt;
int option, ra, imp;
string name;
bool found = false;

void menu();
void insert();
void remove();
void search();
void print();

int main()
{

  do
  {
    menu();
    switch (option)
    {
    case 1:
      insert();
      break;
    case 2:
      remove();
      break;
    case 3:
      search();
      break;
    case 4:
      print();
      break;
    }
  } while (option);

  return 0;
}

void menu()
{
  cout << "\nDigite 0 para parar o algoritmo!\n"
       << "Digite 1 para inserir um aluno!\n"
       << "Digite 2 para remover um aluno!\n"
       << "Digite 3 para buscar um aluno!\n"
       << "Digite 4 para imprimir a arvore!\n\n";
  cin >> option;
  cout << endl;
}

void insert()
{
  cout << "Digite o nome do aluno:\n";
  cin >> name;
  cout << "Digite o ra do aluno:\n";
  cin >> ra;
  Student std(ra, name);
  if (avlt.isFull())
    cout << "Binary Search Tree is full!\n";
  else
  {
    avlt.insert(std);
    cout << endl;
  }
}

void remove()
{
  avlt.printOrder(avlt.getRoot());
  cout << "Digite o ra do aluno:\n";
  cin >> ra;
  Student std(ra, "");
  avlt.remove(std);
  cout << endl;
}

void search()
{
  cout << "Digite o ra do aluno:\n";
  cin >> ra;
  Student std(ra, "");
  avlt.search(std, found);
  if (!found)
  {
    cout << "Aluno não encontrado\n";
    return;
  }
  cout << "Name:\t" << std.getName() << endl
       << "RA:\t" << std.getRa() << endl;
}

void print()
{
  cout << "Imprimir em:" << endl
       << "\tPré Ordem: 0" << endl
       << "\tOrdem: 1" << endl
       << "\tPós Ordem: 2" << endl;
  cin >> imp;
  cout << endl;

  switch (imp)
  {
  case 0:
    avlt.printPreOrder(avlt.getRoot());
    break;
  case 1:
    avlt.printOrder(avlt.getRoot());
    break;
  case 2:
    avlt.printPostOrder(avlt.getRoot());
    break;
  }
}
