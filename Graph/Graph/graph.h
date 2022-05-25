#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "../Stack/dynamicStack.h"
#include "../Queue/dynamicQueue.h"

class Graph
{
private:
  int nullEdge;
  int maxSummits;
  int numSummits;
  ItemType *summits;
  int **adjacencyMatrix;
  bool *marker;

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
  void clearMarker();
  void breadthFirstSearch(ItemType origin, ItemType dest);
  void depthFirstSearch(ItemType origin, ItemType dest);
};
#endif