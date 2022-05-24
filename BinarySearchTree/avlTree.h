#include <iostream>
#include "student.h"

struct Node
{
  Student student;
  Node *leftNode;
  Node *rightNode;
  int balancingFactor;
};

class AVLTree
{
private:
  Node *root;

public:
  AVLTree();
  ~AVLTree();
  void deleteTree(Node *currentNode);
  Node *getRoot();
  bool isEmpty();
  bool isFull();
  void insert(const Student student);
  void remove(Student student);
  void removeSearch(Student student, Node *&curretnNode, bool &decreased);
  void removeNode(Node *&currentNode, bool &decreased);
  void getSuccessor(Student &successorStudent, Node *temp);
  void search(Student &student, bool &found);
  void printPreOrder(Node *currentNode);
  void printOrder(Node *currentNode);
  void printPostOrder(Node *currentNode);

  void rightRotation(Node *&currentNode);
  void leftRotation(Node *&currentNode);
  void leftRightRotation(Node *&currentNode);
  void rightLeftRotation(Node *&currentNode);
  void rotate(Node *&currentNode);
  void recursivelyInsert(Node *&currentNode, Student student, bool &incresed);
};