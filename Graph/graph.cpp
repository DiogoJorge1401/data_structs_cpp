#include "graph.h"

using namespace std;

Graph::Graph() {}
Graph::Graph(int ms, int ne)
{
  numSummits = 0;
  maxSummits = ms;
  nullEdge = ne;
  summits = new ItemType[maxSummits];
  adjacencyMatrix = new int *[maxSummits];

  for (int i = 0; i < maxSummits; i++)
    adjacencyMatrix[i] = new int[maxSummits];

  for (int r = 0; r < maxSummits; r++)
    for (int c = 0; c < maxSummits; c++)
      adjacencyMatrix[r][c] = nullEdge;
}
Graph::~Graph()
{
  delete[] summits;
  for (int r = 0; r < maxSummits; r++)
    delete[] adjacencyMatrix[r];
  delete[] adjacencyMatrix;
}
int Graph::getIndex(ItemType item)
{
  int index = 0;
  while (summits[index] != item && index < maxSummits)
    index++;
  return summits[index] != item ? -1 : index;
}
bool Graph::isFull()
{
  return numSummits == maxSummits;
}
void Graph::insertSummit(ItemType summit)
{
  if (isFull())
  {
    cout << "não é possível inserir uma nova vértice, o número de vértices chegou ao máximo!\n";
    return;
  }

  summits[numSummits++] = summit;
}
void Graph::insertEdge(ItemType outNode, ItemType inNode, int weight)
{
  int outputNodeLineIndex = getIndex(outNode), inputNodeColumnIndex = getIndex(inNode);

  if (outputNodeLineIndex < 0 || inputNodeColumnIndex < 0)
  {
    cout << "Alguma vértice não foi encontrada, verifique se elas existem!\n";
    return;
  }

  adjacencyMatrix[outputNodeLineIndex][inputNodeColumnIndex] = weight;
  adjacencyMatrix[inputNodeColumnIndex][outputNodeLineIndex] = weight;
}
int Graph::getWeight(ItemType outNode, ItemType inNode)
{
  int outputNodeLineIndex = getIndex(outNode), inputNodeColumnIndex = getIndex(inNode);
  if (outputNodeLineIndex < 0 || inputNodeColumnIndex < 0)
    return -1;
  return adjacencyMatrix[outputNodeLineIndex][inputNodeColumnIndex];
}
int Graph::getDegree(ItemType node)
{
  int lineIndex = getIndex(node), degree = 0;
  if (lineIndex < 0)
    return -1;
  for (int i = 0; i < maxSummits; i++)
    if (adjacencyMatrix[lineIndex][i] != nullEdge)
      degree++;
  return degree;
}
void Graph::printMatrix()
{
  cout << "Matriz de adjacencias:\n";
  for (int r = 0; r < maxSummits; r++)
  {
    for (int c = 0; c < maxSummits; c++)
    {
      cout << "| ";
      if (c == 0)
        cout << adjacencyMatrix[r][c] << " | ";
    }
    cout << endl;
  }
}
void Graph::printSummits()
{
  cout << "Lista de vértices:\n";
  for (int i = 0; i < numSummits; i++)
    cout << i << ":" << summits[i] << endl;
}