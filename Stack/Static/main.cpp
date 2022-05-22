#include <iostream>
#include "stack.h"

using namespace std;

Stack stack;
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

void length()
{
  cout << "\nTamanho da pilha: " << stack.getLength() << endl;
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
    cout << "Digite 3 para imprimir a pilha!\n";
    cout << "Digite 4 para saber o tamanho da pilha!\n";

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
    case 4:
      length();
      break;
    default:
      cout << "\nOpção inválida!\n";
      break;
    }

  } while (option);
  return 0;
}