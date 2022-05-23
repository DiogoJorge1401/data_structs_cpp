#include <iostream>
#include "student.h"

struct Node
{
  Student student;
  Node *leftNode;
  Node *rightNode;
};

class BinarySearchTree
{
private:
  Node *root;

public:
  BinarySearchTree();
  ~BinarySearchTree();
  void deleteTree(Node *currentNode);
  Node *getRoot();
  bool isEmpty();
  bool isFull();
  void insert(const Student student);
  void remove(Student student);
  void removeSearch(Student student, Node *&curretnNode);
  void removeNode(Node *&currentNode);
  void getSuccessor(Student &successorStudent, Node *temp);
  void search(Student &student, bool &found);
  void printPreOrder(Node *currentNode);
  void printOrder(Node *currentNode);
  void printPostOrder(Node *currentNode);
};