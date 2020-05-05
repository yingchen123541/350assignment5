#include "BSTree1.h"

//overloaded constructor
BSTree1::BSTree1(){
  //we don't have a node yet, root is null
  root=NULL;
}

//virtual BSTree:~:BSTree() for templete class
BSTree1:~:BSTree1(){
  //figure it out
}

void BSTree1::printTree(TreeNode1 *node)
{
  //if equals to null, not returning anything
  if(node==NULL){
    return;
  }

  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

TreeNode1* BSTree1::getMax()
{
  TreeNode1 *curr = root; //start at the root

  if(root==NULL){
    return NULL; //tree is empty
  }
  //everything on the right is bigger than the root so go to the right for bigger value
  while(curr->right !=NULL){
    curr=curr->right;
  }
  return curr; //if tree consist of a numeric type curr->key or curr->value
}
//everything less than the root will go to the left
TreeNode1* BSTree1::getMin()
{
  TreeNode1 *curr = root; //start at the root

  if(root==NULL){
    return NULL; //tree is empty
  }
  //eberything on the right is bigger than the root so go to the right for bigger value
  while(curr->left !=NULL){
    curr=curr->left;
  }
  return curr; //if tree consist of a numeric type curr->key or curr->value
}

bool BSTree1::isEmpty()
{
  return (root==NULL); //or size of tree=0
}

void BSTree1::insert(int value)
{
  TreeNode1 *node = new TreeNode1(value); //value is also the key
  if(root==NULL)
  {
    //root is empty, equal to null
    root=node;
  }else{
    //tree is not empty, need to find location
    TreeNode1 *curr = root;
    TreeNode1 *parent; //empty node, the node right above the potential new insertion node, like prev in linkedlist
    while(true){
      //find the insertion point
      parent=curr;
      if(value < curr->key){
        //go left in the tree
        curr=curr->left;
        if(curr==NULL){
          //this spot is empty in the tree, we find the insertion point
          parent->left = node;
          break;
        }
      }else{
        //go right
        curr=curr->right;
        if(curr==NULL){
          //find the insertion point
          parent->right=node;
          break;
        }
      }
      }
    }
  }

//key is the value we are searching for
//if want to make it recursive, has how to do it in textbook
bool BSTree1::search(int value)
{
  if(isEmpty()){
    return false;
  }
  else{
    //tree is not empty
    TreeNode1 *current=root;
    while (current->key != value){
      if(value < current->key){
        current = current->left;
      }else{
        current=current->right;
      }

      if(current==NULL)
        return false;
    }
    return true;
  }
}

bool BSTree1::deleteNode(int k)
{
  if(isEmpty()){
    return false;
  }
  //tree is not empty, and value exists, look for the value
  TreeNode1 *current=root;
  TreeNode1 *parent=root;
  //if the node is at the left
  bool ifLeft = true;
  //usual code to find treenode
  // we will also update pointers
  while(current->key != k){
    parent = current;
    if (k < current->key){
      ifLeft=true;
      current=current->left;
    }else{
      ifLeft=false;
      current=current->right;
    }
    if(current==NULL)
      return false;
  }

  //if we made here, we founf the node, proceed to deletre
  //no child, leaf TreeNode
  if(current->left==NULL && current->right==NULL) {
    if(current==root){
      root = NULL;
    }
    else if(isLeft){
      parent->left=NULL;
    }
    else{
      parent->right = NULL;
    }
  }
    //one child and the child is at the left
    else if(current->right == NULL){
      //does not have a right child
      if(current==root){
        root = current->left;
      }
      else if(isLeft){
        parent->left=current->left;
      }
      else{
        parent->right = current->left;
      }
    }
    //one child and the child is at the right
    else if(current->left == NULL){
      //does not have a right child
      if(current==root){
        root = current->right;
      }
      else if(isLeft){
        parent->left=current->right;
      }
      else{
        parent->right = current->right;
      }
    }
    else{
      //the node has two children
      TreeNode1 *successor = getSuccessor(current);

      if(current==root){
        root=successor;
      }else if(isLeft){
        parent->left=successor;
      }else{
        parent->right=successor;
      }

      successor->left=current->left;
      return true;
    }
  }

TreeNode1* BSTree1::getSuccessor(TreeNode1 *d)
{
  //d is the node to be deleted
  TreeNode1 *sp=d;
  TreeNode1 *successor=d;
  TreeNode1 *current= d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right=d->right;
  }
  return successor;
}
