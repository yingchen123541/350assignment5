#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <fstream>
#include "TreeNode.h"
#include "TreeNode.cpp"

//TRY THIS BST
using namespace std;

template <class T>
class BST{
public:
  BST();
  ~BST();

  //core functions
  bool search(int k);
  void insert(T node, int k);
  bool deleteNode(int k);
  TreeNode<T>* getSuccessor(TreeNode<T> *d);
  T returnT(int k);

  //helper function
  bool isEmpty();
  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  void printTree(TreeNode<T> *node);
  void printRoot();
  void printPreorder(TreeNode<T> *node);
  void printToFile(TreeNode<T> *node, ofstream& out);
  void PrintFileR(ofstream& out);


private:
  TreeNode<T> *root;

};
#endif
