typedef int ItemType;

struct Node
{
  ItemType value;
  Node *previous;
};

class DynamicStack
{
private:
  Node *topNode;

public:
  DynamicStack();
  ~DynamicStack();
  bool isFull();
  bool isEmpty();
  void push(ItemType);
  ItemType pop();
  void print();
};