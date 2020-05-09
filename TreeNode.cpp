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
//ignore non tempalte code
// public:
//     TreeNode();
//     TreeNode(int key);
//   //  TreeNode(int key, <type> value) another way
//     ~TreeNode();
//     // when working with template classes, virtual key word
//     // research what that means
//
//     int key;
//     TreeNode *left;
//     TreeNode *right;
//
// };
//
// // tree implementation
// //default
// TreeNode::TreeNode(){
//   key =0;
//   left = NULL;
//   right = NULL;
// }
// // overloaded
// TreeNode::TreeNode(int key){
//   key = k;
//   left = NULL;
//   right = NULL;
// }
// //deconstructor
// ~TreeNode::TreeNode(){
//   // do this
