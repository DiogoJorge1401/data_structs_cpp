#include <iostream>
#include "Graph/graph.h"

using namespace std;
int maxSummits, valueNullEdge;
ItemType item1, item2;
int option, value, weight;

void insertSummit(Graph &graph)
{
  cout << endl;
  cout << "Valor do vértice: ";
  getline(cin, item1);
  cout << endl;
  graph.insertSummit(item1);
}
void insertEdge(Graph &graph)
{
  cout << endl;
  cout << "Valor da vértice de saída: ";
  getline(cin, item1);
  cout << "Valor da vértice de entrada: ";
  getline(cin, item2);
  cout << item1 << " " << item2 << endl;
  cout << "Peso desta aresta: ";
  cin >> weight;
  graph.insertEdge(item1, item2, weight);
}
void summitDegree(Graph &graph)
{
  cout << endl;
  cout << "Valor da vértice: ";
  getline(cin, item1);
  value = graph.getDegree(item1);
  if (value < 0)
  {
    cout << "Vértice não foi encontrada, verifique se ela existem!\n";
    return;
  }
  cout << "O grau desse vértice é " << value << endl;
}
void edgeWeight(Graph &graph)
{
  cout << endl;
  cout << "Valor da vértice de saída: ";
  getline(cin, item1);
  cout << "Valor da vértice de entrada: ";
  getline(cin, item2);
  value = graph.getWeight(item1, item2);
  if (value < 0)
  {
    cout << "Alguma vértice não foi encontrada, verifique se elas existem!\n";
    return;
  }
  cout << "O peso desta aresta é: " << value << endl;
}
void printAdjacencyMatrix(Graph &graph)
{
  cout << endl;
  graph.printMatrix();
}
void printSummits(Graph &graph)
{
  cout << endl;
  graph.printSummits();
}
void breadthFirstSearch(Graph &graph)
{
  cout << endl;
  cout << "Digite o vértice de origem: ";
  getline(cin, item1);
  cout << "Digite o vértice de destino: ";
  getline(cin, item2);
  graph.breadthFirstSearch(item1, item2);
}
void depthFirstSearch(Graph &graph)
{
  cout << endl;
  cout << "Digite o vértice de origem: ";
  getline(cin, item1);
  cout << "Digite o vértice de destino: ";
  getline(cin, item2);
  graph.depthFirstSearch(item1, item2);
}
void menu()
{
  cout << endl;
  cout << "0: parar o algoritmo!\n"
          "1: inserir um vértice\n"
          "2: inserir uma aresta\n"
          "3: imprimir o grau de uma vértice\n"
          "4: imprimir o peso de uma aresta\n"
          "5: imprimir a matriz de adjacencias\n"
          "6: imprimir a lista de vértices\n"
          "7: busca em largura\n"
          "8: busca em profundidade\n";
  cin >> option;
  cin.get();
}

int main(int argc, const char *argv[])
{
  system("clear");
  cout << "Digite a quantidade máxima de vérices:\n";
  cin >> maxSummits;
  cout << "Digite o valor para representar a ausencia de uma aresta:\n";
  cin >> valueNullEdge;
  Graph graph(maxSummits, valueNullEdge);

  do
  {
    menu();
    switch (option)
    {
    case 1:
      insertSummit(graph);
      break;
    case 2:
      insertEdge(graph);
      break;
    case 3:
      summitDegree(graph);
      break;
    case 4:
      edgeWeight(graph);
      break;
    case 5:
      printAdjacencyMatrix(graph);
      break;
    case 6:
      printSummits(graph);
      break;
    case 7:
      breadthFirstSearch(graph);
      break;
    case 8:
      depthFirstSearch(graph);
      break;
    }
  } while (option);

  return 0;
}