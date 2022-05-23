#include <iostream>
#include "binaryTree.h"

using namespace std;

BinarySearchTree bst;
int option, ra, imp;
string name;
bool found = false;

void menu();
void insert();
void remove();
void search();
void print();

int main(int argc, const char *argv[])
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
  if (bst.isFull())
    cout << "Binary Search Tree is full!\n";
  else
  {
    bst.insert(std);
    cout << endl;
  }
}

void remove()
{
  bst.printOrder(bst.getRoot());
  cout << "Digite o ra do aluno:\n";
  cin >> ra;
  Student std(ra, "");
  bst.remove(std);
  cout << endl;
}

void search()
{
  cout << "Digite o ra do aluno:\n";
  cin >> ra;
  Student std(ra, "");
  bst.search(std, found);
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
    bst.printPreOrder(bst.getRoot());
    break;
  case 1:
    bst.printOrder(bst.getRoot());
    break;
  case 2:
    bst.printPostOrder(bst.getRoot());
    break;
  }
}
