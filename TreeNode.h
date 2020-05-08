#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

template <class T>
class TreeNode{
  public:
    TreeNode<T>();
    TreeNode<T>(T d, int k);
    //TreeNode(int key, <type> value) another way
    ~TreeNode<T>();
    //Destructor

    T data;
    int key;
    TreeNode<T> *left;
    TreeNode<T> *right;

  };

#endif
