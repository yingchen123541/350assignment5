/** binarytree.h
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: to define the datastructure and functions of a binary tree
* Date: May 12, 2020
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <fstream>
#include "TreeNode.cpp"

//TRY THIS BST
using namespace std;

template <class T>
class BST{
public:
  //constructor
  BST();
  //destructor
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
