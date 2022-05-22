#include <iostream>
#include "dynamicStack.h"

using namespace std;

DynamicStack stack;
ItemType item;
int option;

void insert()
{
  cout << "\nDigite o valor do elemento: ";
  cin >> item;
  stack.push(item);
}

void remove()
{
  ItemType deleted = stack.pop();
  cout << "\nItem excluido: " << deleted << endl;
}

void print()
{
  stack.print();
}

int main(int argc, char const *argv[])
{
  cout << "Programa gerador de pilhas:";

  do
  {
    cout << "\n\n";
    cout << "Digite 0 para parar o programa!\n";
    cout << "Digite 1 para inserir um elemento!\n";
    cout << "Digite 2 para remover um elemento!\n";
    cout << "Digite 3 para imprimir a pilha!\n\n";

    cin >> option;

    switch (option)
    {
    case 0:
      break;
    case 1:
      insert();
      break;
    case 2:
      remove();
      break;
    case 3:
      print();
      break;
    default:
      cout << "\nOpção inválida!\n";
      break;
    }

  } while (option);
  return 0;
}