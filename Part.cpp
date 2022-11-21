#include "Part.h"

Part::Part() 
{
	name = "";
	sprockets = 0;
}
Part::Part(int x)
{
    this->set_sprockets(x);
}
Part::Part(string n, int x)
{
    this->set_name(n);
    this->set_sprockets(x);
}
string Part::get_name()
{
	return name;
}
void Part::set_name(string n)
{
	name = n;
}
int Part::get_sprockets()
{
	return sprockets;
}
void Part::set_sprockets(int i)
{
	sprockets = i;
}

//Recursive insertion function
//Inserts a BSTNode with x below this node
void Part::insert(string name, int sp)
{
  if (sp < get_sprockets())
  {
    if (left != nullptr)
      left->insert(name, sp);
    else
    {
      left = new Part(name, sp);
      left->parent = this;
    }
  }
  else
  {
    if (right != nullptr)
      right->insert(name, sp);
    else
    {
      right = new Part(name, sp);
      right->parent = this;
    }
  }
}

////Function to remove this node from the BST
////Returns the root of this subtree after deletion
//Part* Part::remove()
//{
//  int numChildren = (left != nullptr) + (right != nullptr);
//  //Separate cases based on # of children
//  if (numChildren == 0)
//  {
//    if (isLeftChild())
//      parent->left = nullptr;
//    else if (isRightChild())
//      parent->right = nullptr;
//    //don't dereference parent if root
//
//    delete this;
//    return nullptr; //tree has no root
//  }
//  else if (numChildren == 1)
//  {
//    BSTNode* child;
//    if (left != nullptr)
//      child = left;
//    else
//      child = right;
//    
//    //Point child to parent
//    child->parent = parent;
//
//    //Point parent to child
//    if (isLeftChild())
//      parent->left = child;
//    else if (isRightChild())
//      parent->right = child;
//    
//    left = right = nullptr; //important so we don't delete child
//    delete this;
//    return child; //child is now root
//  }
//  else //2 children
//  {
//    BSTNode* swap = left->findMax();
//    data = swap->data;
//    swap->remove(); //recursively delete other node
//    return this; //still the root of the subtree
//  }
//}

//Insert an element into the BST
//Works recursively unless BST is empty
void RobotTree::insert(string name, int x)
{
  if (root != nullptr)
    root->insert(name, x);
  else
    root = new Part(name, x);
  
  size++;
}

////Function to remove a value from the BST
//void RobotTree::remove(int x)
//{
//  if (root == nullptr)
//    return; //empty BST
//  
//  BSTNode* victim = root->search(x);
//  if (victim == nullptr)
//    return; //doesn't contain x
//  
//  if (victim == root) //update root if deleting
//    root = victim->remove(); 
//  else
//    victim->remove();
//}
