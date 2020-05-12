/** TreeNode.cpp
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: tree node class to make node for tree
* Date: May 12, 2020
*/
#include "TreeNode.h"
//default constructor
template <class T>
TreeNode<T>::TreeNode(){
    key = 0;
    left = NULL;
    right = NULL;
    data = NULL;
  }

//overloaded constructor
template <class T>
TreeNode<T>::TreeNode(T d, int k){
    data = d;
    key = k;
    left = NULL;
    right = NULL;
  }

//destructor
template <class T>
TreeNode<T>::~TreeNode(){
  //build chatacter
    delete left;
    delete right;
  }
