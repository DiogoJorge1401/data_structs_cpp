#include <cstddef>
#include "binaryTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinarySearchTree ::~BinarySearchTree()
{
  deleteTree(root);
}

void BinarySearchTree::deleteTree(Node *currentNode)
{
  if (currentNode)
  {
    deleteTree(currentNode->leftNode);
    deleteTree(currentNode->rightNode);
    delete currentNode;
  }
}

Node *BinarySearchTree::getRoot() { return root; }

bool BinarySearchTree::isEmpty() { return !root; }

bool BinarySearchTree::isFull()
{
  try
  {
    Node *n = new Node;
    delete n;
    return false;
  }
  catch (...)
  {
    return true;
  }
}

void BinarySearchTree::insert(Student student)
{
  Node *newNode = new Node;
  newNode->leftNode = NULL;
  newNode->rightNode = NULL;
  newNode->student = student;

  Node *aux = root;

  while (aux)
  {
    if (student.getRa() < aux->student.getRa())
    {
      if (!aux->leftNode)
      {
        aux->leftNode = newNode;
        return;
      }
      else
      {
        aux = aux->leftNode;
        continue;
      }
    }
    if (!aux->rightNode)
    {
      aux->rightNode = newNode;
      return;
    }
    aux = aux->rightNode;
  }
  root = newNode;
}

void BinarySearchTree::remove(Student student)
{
  removeSearch(student, root);
}

void BinarySearchTree::removeSearch(Student student, Node *&currentNode)
{
  if (currentNode)
  {
    if (student.getRa() < currentNode->student.getRa())
      removeSearch(student, currentNode->leftNode);
    else if (student.getRa() > currentNode->student.getRa())
      removeSearch(student, currentNode->rightNode);
    else
      removeNode(currentNode);
  }
}

void BinarySearchTree::removeNode(Node *&currentNode)
{
  Node *aux = currentNode;
  if (!currentNode->leftNode)
  {
    currentNode = currentNode->rightNode;
    delete aux;
  }
  else if (!currentNode->rightNode)
  {
    currentNode = currentNode->leftNode;
    delete aux;
  }
  else
  {
    Student ss;
    getSuccessor(ss, currentNode);
    currentNode->student = ss;
    removeSearch(ss, currentNode->rightNode);
  }
}

void BinarySearchTree::getSuccessor(Student &successorStudent, Node *temp)
{
  Node *aux = temp->rightNode;
  while (aux->leftNode)
    aux = aux->leftNode;
  successorStudent = aux->student;
}

void BinarySearchTree::search(Student &student, bool &found)
{
  Node *aux = root;
  found = false;

  while (aux)
  {
    if (student.getRa() == aux->student.getRa())
    {
      student = aux->student;
      found = true;
      return;
    }
    else if (student.getRa() > aux->student.getRa())
      aux = aux->rightNode;
    else
      aux = aux->leftNode;
  }
}

void BinarySearchTree::printPreOrder(Node *currentNode)
{
  if (isEmpty())
  {
    cout << "Binary Search Tree is empty!\n";
    return;
  }
  if (currentNode)
  {
    cout << "Name:\t" << currentNode->student.getName() << endl
         << "RA:\t" << currentNode->student.getRa() << endl;
    printPreOrder(currentNode->leftNode);
    printPreOrder(currentNode->rightNode);
  }
}

void BinarySearchTree::printOrder(Node *currentNode)
{
  if (isEmpty())
  {
    cout << "Binary Search Tree is empty!\n";
    return;
  }
  if (currentNode)
  {
    printOrder(currentNode->leftNode);
    cout << "Name:\t" << currentNode->student.getName() << endl
         << "RA:\t" << currentNode->student.getRa() << endl;
    printOrder(currentNode->rightNode);
  }
}

void BinarySearchTree::printPostOrder(Node *currentNode)
{
  if (isEmpty())
  {
    cout << "Binary Search Tree is empty!\n";
    return;
  }
  if (currentNode)
  {
    printPostOrder(currentNode->leftNode);
    printPostOrder(currentNode->rightNode);
    cout << "Name:\t" << currentNode->student.getName() << endl
         << "RA:\t" << currentNode->student.getRa() << endl;
  }
}