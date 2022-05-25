#include "graph.h"
using namespace std;
Graph::Graph() {}
Graph::Graph(int ms, int ne)
{
  numSummits = 0;
  maxSummits = ms;
  nullEdge = ne;

  marker = new bool[maxSummits];
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
  delete[] marker;
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
    cout << "| ";
    for (int c = 0; c < maxSummits; c++)
      cout << adjacencyMatrix[r][c] << " | ";
    cout << endl;
  }
}
void Graph::printSummits()
{
  cout << "Lista de vértices:\n";
  for (int i = 0; i < numSummits; i++)
    cout << i << ":" << summits[i] << endl;
}
void Graph::clearMarker()
{
  for (int i = 0; i < maxSummits; i++)
    marker[i] = false;
}
void Graph::breadthFirstSearch(ItemType origin, ItemType dest)
{
  DynamicQueue summitsQueue;
  clearMarker();
  summitsQueue.enqueue(origin);
  int index = getIndex(origin);
  marker[index] = true;
  do
  {
    ItemType currentSummit = summitsQueue.dequeue();
    if (currentSummit == dest)
    {
      cout << "Visitando: " << currentSummit << endl;
      cout << "Caminho encontrado!\n";
      return;
    }
    int index = getIndex(currentSummit);
    
    cout << "Visitando: " << currentSummit << endl;
    for (int i = 0; i < maxSummits; i++)
      if (adjacencyMatrix[index][i] != nullEdge)
        if (!marker[i])
        {
          cout << "Enfileirando: " << summits[i] << endl;
          summitsQueue.enqueue(summits[i]);
          marker[i] = true;
        }
  } while (!summitsQueue.isEmpty());
  cout << "Caminho não encontrado!\n";
}
void Graph::depthFirstSearch(ItemType origin, ItemType dest)
{
  DynamicStack summitsStack;
  clearMarker();
  summitsStack.push(origin);
  int index = getIndex(origin);
  marker[index] = true;
  do
  {
    ItemType currentSummit = summitsStack.pop();
    if (currentSummit == dest)
    {
      cout << "Visitando: " << currentSummit << endl;
      cout << "Caminho encontrado!\n";
      return;
    }
    int index = getIndex(currentSummit);
    cout << "Visitando: " << currentSummit << endl;
    for (int i = 0; i < maxSummits; i++)
      if (adjacencyMatrix[index][i] != nullEdge)
        if (!marker[i])
        {
          cout << "Empilhando: " << summits[i] << endl;
          summitsStack.push(summits[i]);
          marker[i] = true;
        }
  } while (!summitsStack.isEmpty());
  cout << "Caminho não encontrado!\n";
}