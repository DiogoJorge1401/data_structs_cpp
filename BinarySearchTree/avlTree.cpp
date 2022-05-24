#include <cstddef>
#include "avlTree.h"

using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree ::~AVLTree()
{
  deleteTree(root);
}

void AVLTree::deleteTree(Node *currentNode)
{
  if (currentNode)
  {
    deleteTree(currentNode->leftNode);
    deleteTree(currentNode->rightNode);
    delete currentNode;
  }
}

Node *AVLTree::getRoot() { return root; }

bool AVLTree::isEmpty() { return !root; }

bool AVLTree::isFull()
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

void AVLTree::insert(Student student)
{
  bool incresed;
  recursivelyInsert(root, student, incresed);
}

void AVLTree::recursivelyInsert(Node *&currentNode, Student student, bool &incresed)
{
  if (!currentNode)
  {
    currentNode = new Node;
    currentNode->leftNode = NULL;
    currentNode->rightNode = NULL;
    currentNode->student = student;
    currentNode->balancingFactor = 0;
    incresed = true;
    return;
  }

  if (student.getRa() < currentNode->student.getRa())
  {
    recursivelyInsert(currentNode->leftNode, student, incresed);
    if (incresed)
      currentNode->balancingFactor -= 1;
  }
  else
  {
    recursivelyInsert(currentNode->rightNode, student, incresed);
    if (incresed)
      currentNode->balancingFactor += 1;
  }
  rotate(currentNode);
  if (incresed && currentNode->balancingFactor == 0)
    incresed = false;
}

void AVLTree::remove(Student student)
{
  bool decreased;
  removeSearch(student, root, decreased);
}

void AVLTree::removeSearch(Student student, Node *&currentNode, bool &decreased)
{
  if (student.getRa() < currentNode->student.getRa())
  {
    removeSearch(student, currentNode->leftNode, decreased);
    if (decreased)
      currentNode->balancingFactor += 1;
  }
  else if (student.getRa() > currentNode->student.getRa())
  {
    removeSearch(student, currentNode->rightNode, decreased);
    if (decreased)
      currentNode->balancingFactor -= 1;
  }
  else
    removeNode(currentNode, decreased);

  if (currentNode)
  {
    rotate(currentNode);
    if (decreased && currentNode->balancingFactor != 0)
      decreased = false;
  }
}

void AVLTree::removeNode(Node *&currentNode, bool &decreased)
{
  Node *aux = currentNode;
  if (!currentNode->leftNode)
  {
    currentNode = currentNode->rightNode;
    decreased = true;
    delete aux;
  }
  else if (!currentNode->rightNode)
  {
    currentNode = currentNode->leftNode;
    decreased = true;
    delete aux;
  }
  else
  {
    Student ss;
    getSuccessor(ss, currentNode);
    currentNode->student = ss;
    removeSearch(ss, currentNode->rightNode, decreased);
    if (decreased)
      currentNode->balancingFactor -= 1;
  }
}

void AVLTree::getSuccessor(Student &successorStudent, Node *temp)
{
  Node *aux = temp->rightNode;
  while (aux->leftNode)
    aux = aux->leftNode;
  successorStudent = aux->student;
}

void AVLTree::search(Student &student, bool &found)
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

void AVLTree::printPreOrder(Node *currentNode)
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

void AVLTree::printOrder(Node *currentNode)
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

void AVLTree::printPostOrder(Node *currentNode)
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

void AVLTree::rightRotation(Node *&currentNode)
{
  Node *newParent = currentNode->leftNode;
  currentNode->leftNode = newParent->rightNode;
  newParent->rightNode = currentNode;
  currentNode = newParent;
}

void AVLTree::leftRotation(Node *&currentNode)
{
  Node *newParent = currentNode->rightNode;
  currentNode->rightNode = newParent->leftNode;
  newParent->leftNode = currentNode;
  currentNode = newParent;
}

void AVLTree::leftRightRotation(Node *&currentNode)
{
  Node *newChild = currentNode->leftNode;
  leftRotation(newChild);
  currentNode->leftNode = newChild;
  rightRotation(currentNode);
}

void AVLTree::rightLeftRotation(Node *&currentNode)
{
  Node *newChild = currentNode->rightNode;
  rightRotation(newChild);
  currentNode->rightNode = newChild;
  leftRotation(currentNode);
}

void AVLTree::rotate(Node *&currentNode)
{
  Node *child;
  Node *grandchild;

  if (currentNode->balancingFactor == -2)
  {
    child = currentNode->leftNode;
    if (child->balancingFactor == -1)
    {
      currentNode->balancingFactor = 0;
      child->balancingFactor = 0;
      rightRotation(currentNode);
    }
    else if (child->balancingFactor == 0)
    {
      currentNode->balancingFactor = -1;
      child->balancingFactor = 1;
      rightRotation(currentNode);
    }
    else if (child->balancingFactor == 1)
    {
      grandchild = child->rightNode;
      if (grandchild->balancingFactor == -1)
      {
        currentNode->balancingFactor = 1;
        child->balancingFactor = 0;
      }
      else if (grandchild->balancingFactor == 0)
      {
        currentNode->balancingFactor = 0;
        child->balancingFactor = 0;
      }
      else if (grandchild->balancingFactor == 1)
      {
        currentNode->balancingFactor = 0;
        child->balancingFactor = -1;
      }

      grandchild->balancingFactor = 0;
      leftRightRotation(currentNode);
    }
  }

  else if (currentNode->balancingFactor == 2)
  {
    child = currentNode->rightNode;
    if (child->balancingFactor == 1)
    {
      currentNode->balancingFactor = 0;
      child->balancingFactor = 0;
      leftRotation(currentNode);
    }
    else if (child->balancingFactor == 0)
    {
      currentNode->balancingFactor = 1;
      child->balancingFactor = -1;
      leftRotation(currentNode);
    }
    else if (child->balancingFactor == -1)
    {
      grandchild = child->leftNode;
      if (grandchild->balancingFactor == -1)
      {
        currentNode->balancingFactor = 0;
        child->balancingFactor = 1;
      }
      else if (grandchild->balancingFactor == 0)
      {
        currentNode->balancingFactor = 0;
        child->balancingFactor = 0;
      }
      else if (grandchild->balancingFactor == 1)
      {
        currentNode->balancingFactor = -1;
        child->balancingFactor = 0;
      }

      grandchild->balancingFactor = 0;
      rightLeftRotation(currentNode);
    }
  }
}
