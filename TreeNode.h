/** TreeNode.h
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: tree node class to make tree node for tree
* Date: May 12, 2020
*/
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
