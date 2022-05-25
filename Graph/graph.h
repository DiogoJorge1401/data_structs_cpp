// weighted undirected simple graph
#include <iostream>
typedef std::string ItemType;

class Graph
{
private:
  int nullEdge;
  int maxSummits;
  int numSummits;
  ItemType *summits;
  int **adjacencyMatrix;

public:
  Graph(int maxSummit, int nullEdge);
  Graph();
  ~Graph();
  int getIndex(ItemType item);
  bool isFull();
  void insertSummit(ItemType summit);
  void insertEdge(ItemType outNode, ItemType inNode, int weight);
  int getWeight(ItemType outNode, ItemType inNode);
  int getDegree(ItemType node);
  void printMatrix();
  void printSummits();
};